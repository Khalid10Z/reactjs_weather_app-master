#!/usr/bin/env python3

import sys
import rclpy
from rclpy.node import Node

# ROS message types
from std_msgs.msg import String
from sensor_msgs.msg import Image

# PyQt5 imports
from PyQt5 import QtCore
from PyQt5.QtCore import QTimer, Qt
from PyQt5.QtGui import QPixmap, QImage
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QWidget, QLabel, 
    QPushButton, QVBoxLayout, QHBoxLayout, 
    QGroupBox, QFormLayout, QFrame, QComboBox,
    QTabWidget, QGridLayout, QSpinBox
)

class MainWindow(QMainWindow):
    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)

        # -------------------------------------------------
        #             BASIC WINDOW SETUP
        # -------------------------------------------------
        self.setMinimumSize(800, 350)    
        self.setWindowTitle("ROS2 Command & Camera Interface")

        main_widget = QWidget()
        self.setCentralWidget(main_widget)

        # -------------------------------------------------
        #                MODE SELECTION
        # -------------------------------------------------
        mode_group = QGroupBox("Mode")
        mode_layout = QHBoxLayout()

        self.mode_combo = QComboBox()
        # itemData -> numeric modes used by the robot node
        self.mode_combo.addItem("Manual",   1)
        self.mode_combo.addItem("Random",   0)
        self.mode_combo.addItem("Tracking", 2)
        self.mode_combo.currentIndexChanged.connect(self.on_mode_changed)

        mode_layout.addWidget(QLabel("Select Mode:"))
        mode_layout.addWidget(self.mode_combo)
        mode_group.setLayout(mode_layout)

        # -------------------------------------------------
        #              MOVEMENT CONTROLS
        # -------------------------------------------------
        move_group = QGroupBox("Movement")
        
        self.btn_forward  = QPushButton("Forward")
        self.btn_backward = QPushButton("Backward")
        self.btn_left     = QPushButton("Left")
        self.btn_right    = QPushButton("Right")
        self.btn_stop     = QPushButton("Stop")

        # Connect signals to slots
        self.btn_forward.clicked.connect(lambda: self.send_move_command("forward"))
        self.btn_backward.clicked.connect(lambda: self.send_move_command("backward"))
        self.btn_left.clicked.connect(lambda: self.send_move_command("left"))
        self.btn_right.clicked.connect(lambda: self.send_move_command("right"))
        self.btn_stop.clicked.connect(lambda: self.send_move_command("stop"))
        
        # Layout in a controller style
        move_layout = QGridLayout()
        move_layout.addWidget(self.btn_forward,  0, 1)
        move_layout.addWidget(self.btn_left,     1, 0)
        move_layout.addWidget(self.btn_stop,     1, 1)
        move_layout.addWidget(self.btn_right,    1, 2)
        move_layout.addWidget(self.btn_backward, 2, 1)
        move_group.setLayout(move_layout)

        # -------------------------------------------------
        #               SPEED CONTROL INPUT
        # -------------------------------------------------
        speed_group = QGroupBox("Speed Control")
        speed_layout = QHBoxLayout()

        self.speed_input = QSpinBox()
        self.speed_input.setRange(0, 200)  # allowable speed range
        self.speed_input.setValue(100)     # default speed

        self.btn_set_speed = QPushButton("Set Speed")
        self.btn_set_speed.clicked.connect(self.send_speed_command)

        speed_layout.addWidget(QLabel("Speed:"))
        speed_layout.addWidget(self.speed_input)
        speed_layout.addWidget(self.btn_set_speed)

        speed_group.setLayout(speed_layout)

        # -------------------------------------------------
        #              ROBOT DATA DISPLAY
        # -------------------------------------------------
        data_group = QGroupBox("Robot Data")
        data_layout = QFormLayout()

        # Labels for data (RPM, Distances)
        self.label_wheel_rpm       = QLabel("0 tr/min")
        self.label_obstacle_front  = QLabel("Front: Unknown")
        self.label_obstacle_back   = QLabel("Back: Unknown")
        
        data_layout.addRow("Wheel RPM:",       self.label_wheel_rpm)
        data_layout.addRow("Obstacle Front:",  self.label_obstacle_front)
        data_layout.addRow("Obstacle Back:",   self.label_obstacle_back)
        data_group.setLayout(data_layout)
        
        # -------------------------------------------------
        #            CAMERA FEED TABS (Raw & Proc)
        # -------------------------------------------------
        camera_group = QGroupBox("Camera")
        camera_layout = QVBoxLayout()

        self.camera_tabs = QTabWidget()
        
        # "Raw Feed" tab
        self.raw_camera_label = QLabel("No Raw Feed")
        self.raw_camera_label.setFrameShape(QFrame.Box)
        self.raw_camera_label.setAlignment(Qt.AlignCenter)

        # "Processed Feed" tab
        self.processed_camera_label = QLabel("No Processed Feed")
        self.processed_camera_label.setFrameShape(QFrame.Box)
        self.processed_camera_label.setAlignment(Qt.AlignCenter)

        self.camera_tabs.addTab(self.raw_camera_label,       "Raw Feed")
        self.camera_tabs.addTab(self.processed_camera_label, "Processed Feed")

        camera_layout.addWidget(self.camera_tabs)
        camera_group.setLayout(camera_layout)
        
        # -------------------------------------------------
        #        NEW HORIZONTAL MAIN LAYOUT
        # -------------------------------------------------
        main_layout = QHBoxLayout(main_widget)
        
        # LEFT-SIDE VERTICAL LAYOUT
        left_layout = QVBoxLayout()
        left_layout.addWidget(mode_group)
        left_layout.addWidget(move_group)
        left_layout.addWidget(speed_group)
        left_layout.addStretch()

        # RIGHT-SIDE VERTICAL LAYOUT
        right_layout = QVBoxLayout()
        right_layout.addWidget(data_group)
        right_layout.addWidget(camera_group)
        right_layout.addStretch()

        main_layout.addLayout(left_layout)
        main_layout.addLayout(right_layout)

        # -------------------------------------------------
        #             ROS2 INITIALIZATION
        # -------------------------------------------------
        rclpy.init(args=None) 
        self.node = Node('py_ihm_node')

        # Publisher: single topic with "mode;speed;direction"
        self.pub_move = self.node.create_publisher(String, '/command/move', 10)

        # -------------------------------------------------
        #        SUBSCRIBE TO ROBOT DATA (DISTANCE/RPM)
        # -------------------------------------------------
        self.sub_dist_back = self.node.create_subscription(
            String,
            '/sensor/dist_back',
            self.dist_back_callback,
            10
        )

        # -------------------------------------------------
        #        SUBSCRIBE TO CAMERA (RAW FEED)
        # -------------------------------------------------
        self.sub_camera_raw = self.node.create_subscription(
            Image,
            '/camera/src_frame',  # your camera publisher topic
            self.camera_raw_callback,
            10
        )

        # Current mode (default to Manual=1)
        self.current_mode = 1
        self.last_direction = 2  # default direction
        self.update_movement_buttons()

        # -------------------------------------------------
        #               TIMERS
        # -------------------------------------------------
        self.ros_timer = QTimer()
        self.ros_timer.timeout.connect(self.on_ros_timer_tick)
        self.ros_timer.start(50)  # 20 Hz

        self.apply_stylesheet()

    # -------------------------------------------------
    #              DISTANCE BACK CALLBACK
    # -------------------------------------------------
    def dist_back_callback(self, msg: String):
        """
        Callback for the /sensor/dist_back topic which publishes 
        a string in the format: "%d;%d;%d;%d"
        
        This corresponds to:
          back_distance1 (mm); front_distance1[0] (mm); front_distance1[1] (mm); quadEncoderRPM
        """
        data_str = msg.data.strip()
        tokens = data_str.split(';')
        if len(tokens) == 4:
            try:
                back_dist_mm       = int(tokens[0])
                front_dist0_mm     = int(tokens[1])
                front_dist1_mm     = int(tokens[2])
                encoder_rpm        = int(tokens[3])

                # Update the GUI labels
                self.label_obstacle_back.setText(f"{back_dist_mm} mm")
                self.label_obstacle_front.setText(f"{front_dist0_mm} mm, {front_dist1_mm} mm")
                self.label_wheel_rpm.setText(f"{encoder_rpm} tr/min")

            except ValueError:
                print(f"[dist_back_callback] Error parsing integers from: {data_str}")
        else:
            print(f"[dist_back_callback] Unexpected data format: {data_str}")

    # -------------------------------------------------
    #               CAMERA CALLBACKS
    # -------------------------------------------------
    def camera_raw_callback(self, msg: Image):
        """
        Convert sensor_msgs/Image raw data into QPixmap and display in raw_camera_label.
        """
        try:
            qimg = QImage(msg.data, msg.width, msg.height, QImage.Format_RGB888)
            pixmap = QPixmap.fromImage(qimg)
            self.raw_camera_label.setPixmap(pixmap)
        except Exception as e:
            print(f"Error converting camera image: {e}")

    # -------------------------------------------------
    #       MODE CHANGE & AUTO-PUBLISH
    # -------------------------------------------------
    def on_mode_changed(self, index):
        """
        Triggered whenever the ComboBox selection changes.
        We automatically publish "<mode>;<speed>;2" for the newly selected mode.
        """
        self.current_mode = self.mode_combo.itemData(index)
        speed_value = self.speed_input.value()
        self.last_direction = 2  # reset direction to forward by default

        msg = String()
        msg.data = f"{self.current_mode};{speed_value};{self.last_direction}"
        self.pub_move.publish(msg)
        print(f"Auto-publishing new mode: {msg.data}")

        self.update_movement_buttons()

    def update_movement_buttons(self):
        """
        Enable movement buttons only if mode == Manual (1).
        """
        enabled = (self.current_mode == 1)
        self.btn_forward.setEnabled(enabled)
        self.btn_backward.setEnabled(enabled)
        self.btn_left.setEnabled(enabled)
        self.btn_right.setEnabled(enabled)
        self.btn_stop.setEnabled(enabled)

    # -------------------------------------------------
    #          PUBLISH MOVE (MODE;SPEED;DIRECTION)
    # -------------------------------------------------
    def send_move_command(self, direction_str):
        """
        Publishes "mode;speed;direction".
        Direction codes: backward=1, forward=2, left=3, right=4, stop=5
        """
        direction_map = {
            "backward": 1,
            "forward":  2,
            "left":     3,
            "right":    4,
            "stop":     5
        }
        direction_code = direction_map.get(direction_str, 5)
        self.last_direction = direction_code
        mode_val    = self.current_mode
        speed_value = self.speed_input.value()

        msg = String()
        msg.data = f"{mode_val};{speed_value};{direction_code}"
        self.pub_move.publish(msg)
        print(f"Publishing Move: {msg.data}")

    def send_speed_command(self):
        """
        Publishes the current mode and new speed with a default direction (forward=2).
        This allows changing speed without changing mode or direction explicitly.
        """
        mode_val = self.current_mode
        speed_value = self.speed_input.value()
        direction_code = 2  # Default to forward if just updating speed
        self.last_direction = direction_code

        msg = String()
        msg.data = f"{mode_val};{speed_value};{direction_code}"
        self.pub_move.publish(msg)
        print(f"Publishing Speed Update: {msg.data}")

    # -------------------------------------------------
    #              ROS SPIN TIMER
    # -------------------------------------------------
    def on_ros_timer_tick(self):
        # Spin the ROS node so callbacks are processed
        rclpy.spin_once(self.node, executor=None, timeout_sec=0.01)

    # -------------------------------------------------
    #       DATA & STYLESHEET (OPTIONAL)
    # -------------------------------------------------
    def apply_stylesheet(self):
        # Dark-themed modern style
        self.setStyleSheet("""
        QMainWindow {
            background-color: white;
        }
        QGroupBox {
            font-weight: bold;
            color: black;
            border: 1px solid #3e3e3e;
            border-radius: 8px;
            margin-top: 10px;
            padding: 10px;
            font-size: 16px;
        }
        QGroupBox:title {
            subcontrol-origin: margin;
            subcontrol-position: top center;
            padding: 4px;
        }
        QPushButton {
            background-color: green;
            color: #ffffff;
            border-radius: 6px;
            padding: 8px 14px;
            font-size: 14px;
            border: none;
        }
        QPushButton:hover {
            background-color: #3f7cb9;
        }
        QLabel {
            font-size: 14px;
            color: black;
        }
        QTabWidget::pane {
            border: 1px solid #3e3e3e;
            border-radius: 6px;
        }
        QTabBar::tab {
            background: #3e3e3e;
            color: #ffffff;
            padding: 6px 10px;
            border-radius: 4px;
            margin: 2px;
        }
        QTabBar::tab:selected {
            background: #4f8cc9;
        }
        QSpinBox {
            background-color: #3e3e3e;
            color: #ffffff;
            border-radius: 4px;
            padding: 2px 6px;
        }
        """)

def main(args=None):
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
