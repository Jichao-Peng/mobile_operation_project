#!/usr/bin/env python
from __future__ import print_function
from __future__ import absolute_import
from __future__ import division

import json
import logging
import os
import sys
import collections

# configure logging
logging.basicConfig(format='%(asctime)s %(levelname)s %(message)s',
                    level=logging.INFO,
                    stream=sys.stdout)
#ros and cv_bridge
import roslib
import sys
import rospy
import cv2
from std_msgs.msg import String
from cv_bridge import CvBridge, CvBridgeError
import message_filters

#UR robot
import roslib; roslib.load_manifest('ur_driver')
import time
from sensor_msgs.msg import Image, CameraInfo, JointState 
from ur_driver.deserializeRT import RobotStateRT 
from ur_msgs.msg import *
import time, sys, threading, math
import copy
import datetime
import socket, select
import struct
import traceback, code
import SocketServer

#opencv_bridge package message
from jd_vision.msg import *

#tensor flow
import numpy as np
import scipy as scp
import scipy.misc
import imp

class Segmentor:

	def __init__(self):
		rospy.init_node('FCN', anonymous=True)
		self.pose = [0,0,0,0,0,0]

		#cv_bridge 
		self.rgb_bridge = CvBridge()
		self.depth_bridge = CvBridge()
		self.res_bridge = CvBridge()
		self.tss = message_filters.ApproximateTimeSynchronizer([message_filters.Subscriber("/camera/rgb/image_rect_color",Image),     #"color"  "depth" for realsense  #"/camera/rgb/image_rect_color"
														message_filters.Subscriber("/camera/depth_registered/sw_registered/image_rect_raw",Image),   #"/camera/depth_registered/sw_registered/image_rect_raw"
															message_filters.Subscriber("ur",RobotMsg)],1,0.1)
		self.tss.registerCallback(self.callback)

	def callback(self,rgb,depth,robot_data):
		cv_image = self.rgb_bridge.imgmsg_to_cv2(rgb, "rgb8")
		cv_img_depth = self.depth_bridge.imgmsg_to_cv2(depth, "16UC1")
		cv2.imshow("Color Image", cv_image)
		cv2.waitKey(1)
		print(robot_data.data.tool_vector)

def main(args):
	s = Segmentor()
	try:
		rospy.spin()
	except KeyboardInterrupt:
		print("Shutting down")
	cv2.destroyAllWindows()

if __name__ == '__main__':
	main(sys.argv)
