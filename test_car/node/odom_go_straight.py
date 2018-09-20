#!/usr/bin/env python



import rospy
from geometry_msgs.msg import Twist, Point, Quaternion
import tf
#from rbx1_nav.transform_utils import quat_to_angle, normalize_angle
from math import radians, copysign, sqrt, pow, pi

#chmod +x odom_out_and_back.py
#rosrun tf tf_echo [reference coordinate] [target coordinate]


class go_straight():
    def __init__(self):
        # Give the node a name
        rospy.init_node('go_straight', anonymous=False)

        # Set rospy to execute a shutdown function when exiting       
        rospy.on_shutdown(self.shutdown)

        # Publisher to control the robot's speed
        self.cmd_vel = rospy.Publisher('/cmd_vel', Twist, queue_size=5)
        
        # How fast will we update the robot's movement?
        rate = 50
        
        # Set the equivalent ROS rate variable
        r = rospy.Rate(rate)
        
        # Set the forward linear speed to 0.15 meters per second 
        linear_speed = 0.1
        
        # Set the travel distance in meters
        goal_distance = 1.0

       

        # Initialize the tf listener
        self.tf_listener = tf.TransformListener()
        
        # Give tf some time to fill its buffer
        rospy.sleep(2)
        
        # Set the odom frame
        self.odom_frame = '/odom'
        
        # Find out if the robot uses /base_link or /base_footprint
        try:
            self.tf_listener.waitForTransform(self.odom_frame, '/base_footprint', rospy.Time(), rospy.Duration(1.0))
            self.base_frame = '/base_footprint'
        except (tf.Exception, tf.ConnectivityException, tf.LookupException):
            try:
                self.tf_listener.waitForTransform(self.odom_frame, '/base_link', rospy.Time(), rospy.Duration(1.0))
                self.base_frame = '/base_link'
            except (tf.Exception, tf.ConnectivityException, tf.LookupException):
                rospy.loginfo("Cannot find transform between /odom and /base_link or /base_footprint")
                rospy.signal_shutdown("tf Exception")  
        
        # Initialize the position variable as a Point type
        position = Point()
            
        # Initialize the movement command
        move_cmd = Twist()
            
        # Set the movement command to forward motion
        move_cmd.linear.x = linear_speed
            
        # Get the starting position values     
        (position, rotation) = self.get_odom()
                        
        x_start = position.x
        y_start = position.y
            
        # Keep track of the distance traveled
        distance = 0
            
        # Enter the loop to move along a side
        while distance < goal_distance and not rospy.is_shutdown():
            # Publish the Twist message and sleep 1 cycle         
            self.cmd_vel.publish(move_cmd)
                
            r.sleep()
        
            # Get the current position
            (position, rotation) = self.get_odom()
                
            # Compute the Euclidean distance from the start
            distance = sqrt(pow((position.x - x_start), 2) + 
                            pow((position.y - y_start), 2))
	    
		

        # Stop the robot before the rotation
        move_cmd = Twist()
        self.cmd_vel.publish(move_cmd)
        rospy.sleep(1)
            
          
        
    def get_odom(self):
        # Get the current transform between the odom and base frames
        try:
            (trans, rot)  = self.tf_listener.lookupTransform(self.odom_frame, self.base_frame, rospy.Time(0))
        except (tf.Exception, tf.ConnectivityException, tf.LookupException):
            rospy.loginfo("TF Exception")
            return

        return (Point(*trans), (0,0,0))
        
    def shutdown(self):
        # Always stop the robot when shutting down the node.
        rospy.loginfo("Stopping the robot...")
        self.cmd_vel.publish(Twist())
        rospy.sleep(1)
 
if __name__ == '__main__':
    try:
        go_straight()
    except:
        rospy.loginfo("go_straight node terminated.")
