import random
import time
import threading

import rclpy # ROS library
from rclpy.node import Node

import std_msgs.msg
import sensor_msgs.msg

from cv_bridge import CvBridge # To convert to open cv image

import cv2
import numpy as np


class CameraPublisher(Node):

    def __init__(self):
        super().__init__('RPI_Node')

        self.br = CvBridge()

        self.frame_rate = 50 # Max framerate

        # Subscribing to an image topic over the network causes framerate to drop from about 20 to about 10 fps.
        self.publisher_src_frame = self.create_publisher(sensor_msgs.msg.Image, 'camera/src_frame', 10) # Raw image
      
        self.lock_color = threading.Lock() # For safe sharing of the color config variables between the main loop and the callback.
        self.enable = threading.Condition() # To make the main loop wait passively for the correct mode.
        self.lock_mode = threading.Lock() # For safe sharing of the self.mode variable between the main loop and the callback.
        self.mode = 0
        
        self.i = 0 # Count interations in the main loop

        self.cam = cv2.VideoCapture(0) # Initialise the video device
               
    def loop(self):
        while rclpy.ok():
                      
            t0 = time.perf_counter()

            self.i += 1
            
            # Image capture
            succes, frame = self.cam.read()
            if not succes:
                print("failed to grab frame")
                return
            
            if self.i % 10 == 0 :
                self.publisher_src_frame.publish(self.br.cv2_to_imgmsg(cv2.cvtColor(frame, cv2.COLOR_BGR2RGB), encoding="rgb8"))

            delta_time = time.perf_counter()-t0 # Time to run entire loop
            time_sleep = 1/self.frame_rate-delta_time # Time left for chosen framerate
            if time_sleep > 0 :
                time.sleep(time_sleep)

def main(args=None):
    rclpy.init(args=args)

    camera_publisher = CameraPublisher()
    # Starts the loop in a thread because rclpy.spin is blocking (never comes back) and needs to be called for the callbacks subscriptions to work.
    threading.Thread(target = camera_publisher.loop).start()
    rclpy.spin(camera_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    camera_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
