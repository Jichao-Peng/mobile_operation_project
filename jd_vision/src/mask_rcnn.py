#!/usr/bin/env python
# license removed for brevity

# import caffe2
from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
# from __future__ import unicode_literals

from collections import defaultdict
import argparse
import cv2  # NOQA (Must import before importing caffe2 due to bug in cv2)
import glob
import logging
import os
import sys
import time

from caffe2.python import workspace

from detectron.core.config import assert_and_infer_cfg
from detectron.core.config import cfg
from detectron.core.config import merge_cfg_from_file
from detectron.utils.io import cache_url
from detectron.utils.logging import setup_logging
from detectron.utils.timer import Timer
import detectron.core.test_engine as infer_engine
import detectron.datasets.dummy_datasets as dummy_datasets
import detectron.utils.c2 as c2_utils
import detectron.utils.vis as vis_utils

# import ros message
import roslib
# roslib.load_manifest('opencv_bridge')
import rospy
import time
from sensor_msgs.msg import Image, CameraInfo, JointState
from std_msgs.msg import String
from jd_vision.msg import *
import message_filters

# import cv and cvbridge
import cv2
from cv_bridge import CvBridge, CvBridgeError

# import UR robot
import roslib
roslib.load_manifest('ur_driver')
from ur_driver.deserializeRT import RobotStateRT
from ur_msgs.msg import *
import time, sys, threading, math
import copy
import datetime
import socket, select
import struct
import traceback, code
import SocketServer



c2_utils.import_detectron_ops()

# OpenCL may be enabled by default in OpenCV3; disable it because it's not
# thread safe and causes unwanted GPU memory allocations.
cv2.ocl.setUseOpenCL(False)


def parse_args():
    parser = argparse.ArgumentParser(description='End-to-end inference')
    parser.add_argument(
        '--cfg',
        dest='cfg',
        help='cfg model file (/path/to/model_config.yaml)',
        default='/home/aemc/catkin_ws/src/jd_vision/detectron/configs/12_2017_baselines/e2e_mask_rcnn_R-101-FPN_1x.yaml',
        type=str
    )
    parser.add_argument(
        '--wts',
        dest='weights',
        help='weights model file (/path/to/model_weights.pkl)',
        default='/home/aemc/catkin_ws/src/jd_vision/detectron/model/coco_jd_09_15/model_final.pkl',
        type=str
    )
    parser.add_argument(
        '--output-dir',
        dest='output_dir',
        help='directory for visualization jpg',
        default='/home/aemc/catkin_ws/src/jd_vision/detectron/output_dir',
        type=str
    )
    parser.add_argument(
        '--image-ext',
        dest='image_ext',
        help='image file name extension (default: jpg)',
        default='jpg',
        type=str
    )
    parser.add_argument(
        '--always-out',
        dest='out_when_no_box',
        help='output image even when no object is found',
        action='store_true'
    )
    parser.add_argument(
        '--im_or_folder',
        dest='im_or_folder',
        help='image or folder of images',
        default='/home/aemc/catkin_ws/src/jd_vision/detectron/demo',
    )
    parser.add_argument(
        '--output-ext',
        dest='output_ext',
        help='output image file format (default: jpg)',
        default='jpg',
        type=str
    )

    return parser.parse_args()


class Segmentor:

    def __init__(self):
        rospy.init_node('Mask_RCNN', anonymous=True)
        workspace.GlobalInit(['caffe2', '--caffe2_log_level=0'])
        setup_logging(__name__)

        self.args = parse_args()

        self.pose = [0, 0, 0, 0, 0, 0]

        # publish
        self.frame_pub = rospy.Publisher("frame", Frame, queue_size=1)

        # cv_bridge
        self.rgb_bridge = CvBridge()
        self.depth_bridge = CvBridge()
        self.res_bridge = CvBridge()

        # mask_rcnn
        merge_cfg_from_file(self.args.cfg)
        cfg.NUM_GPUS = 1
        self.args.weights = cache_url(self.args.weights, cfg.DOWNLOAD_CACHE)
        assert_and_infer_cfg(cache_urls=False)
        assert not cfg.MODEL.RPN_ONLY, \
            'RPN models are not supported'
        assert not cfg.TEST.PRECOMPUTED_PROPOSALS, \
            'Models that require precomputed proposals are not supported'
        self.model = infer_engine.initialize_model_from_cfg(self.args.weights)
        self.dummy_coco_dataset = dummy_datasets.get_coco_dataset()
        print("Mask_RCNN build successfully. Starting to wait for registerCallback.")

        self.tss = message_filters.ApproximateTimeSynchronizer(
            [message_filters.Subscriber("/camera/rgb/image_rect_color", Image),
             # "color"  "depth" for realsense  #"/camera/rgb/image_rect_color"
             message_filters.Subscriber("/camera/depth_registered/sw_registered/image_rect_raw", Image),
             # "/camera/depth_registered/sw_registered/image_rect_raw"
             message_filters.Subscriber("ur", RobotMsg)], 1, 0.1)

    def mask_rcnn(self, cv_image):
        im = cv_image
        timers = defaultdict(Timer)
        t = time.time()
        with c2_utils.NamedCudaScope(0):
            cls_boxes, cls_segms, cls_keyps = infer_engine.im_detect_all(
                self.model, im, None, timers=timers
            )
        logging.info('Inference time: {:.3f}s'.format(time.time() - t))
        for k, v in timers.items():
            logging.info(' | {}: {:.3f}s'.format(k, v.average_time))

        order_message = {'chip': 1, 'mil': 1, 'shampo': 1, 'cap_of_shampo': 1, 'coca_col': 1, 'biscuit': 1,
                         'toothpast': 1, 'calcium_tablet': 1, 'calcium_tablets_sticke': 1, 'sausag': 1,
                         'toothbrus': 1, 'teething_stic': 1, 'aolia': 1, 'frie': 1, 'guozhe': 1, 'boo': 1,
                         'calcium_tablets_bo': 1, 'orang': 1}
        masks_output = list()
        categories_output = list()
        vis_utils.get_mask(
            order_message,
            masks_output,
            categories_output,
            im[:, :, ::-1],  # BGR -> RGB for visualization
            cv_image,
            self.args.output_dir,
            cls_boxes,
            cls_segms,
            dataset=self.dummy_coco_dataset,
            show_class=True,
            thresh=0.7,
            ext=self.args.output_ext,
            out_when_no_box=self.args.out_when_no_box
        )
        return masks_output, categories_output

    def callback(self, rgb, depth, robot_data):
        # cv_image = cv2.imread('/home/aemc/catkin_ws/src/jd_vision/detectron/demo/1.jpg')
        cv_image = self.rgb_bridge.imgmsg_to_cv2(rgb, "bgr8")
        #cv_img_depth = self.depth_bridge.imgmsg_to_cv2(depth, "16UC1")
        print(robot_data.data.tool_vector)
        try:
            start = time.time()
            masks_output, categories_output = self.mask_rcnn(cv_image)
            end = time.time()
            cost = end-start
            print('Time for MaskRCNN: '+str(cost*1000)+'ms\n')
        except CvBridgeError as e:
            print(e)
            sys.exit()
        # publish frame:color,depth,image,mask,and robot pose
        frame = Frame()
        frame.color = self.res_bridge.cv2_to_imgmsg(cv_image, encoding="bgr8")
        frame.depth = depth
        frame.categories = categories_output
        for i in range(len(masks_output)):
            frame.masks.append(self.res_bridge.cv2_to_imgmsg(masks_output[i], encoding="passthrough"))
        frame.robot_pose = robot_data.data.tool_vector
        frame.robot_joint = robot_data.data.q_actual
        self.frame_pub.publish(frame)


def main(args):
    s = Segmentor()
    s.tss.registerCallback(s.callback)
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Shutting Down")
    cv2.destroyAllWindows()


if __name__ == '__main__':
    main(sys.argv)
