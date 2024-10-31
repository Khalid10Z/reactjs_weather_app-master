# Introduction:
This project aims to develop a distributed sensor network using the CAN bus as the communication backbone. The goal was to retrieve data from multiple sensors on a host PC via a CAN bus. The sensors, connected to ST-Nucleo microcontrollers, transmit data via CAN frames for real-time display on a GUI.

# System Architecture:

3x STM32-Nucleo F411RE Boards
CAN bus for inter-board communication <\n>
Multiple specialized sensors and one actuator:
🎮 Dynamixel Servo Motor + Anemometer<\n>
💡 Environmental Sensors (light, pressure, humidity)<\n>
🔄 IMU Module (accelerometer + gyroscope)<\n>
🎯 Board Distribution:<\n>

Board 1 - Motor Control:

Robotis Dynamixel Servo Motor
SOMFY Anemometer
Board 2 - Environment:

VL6180X (light/distance)
LPS22HB (pressure)
HTS221 (humidity)
Board 3 - Navigation:

MPU9250 (IMU)
💻 Software Aspects:

CAN Communication
GUI with Qt C++
SQLite Database
I2C, UART Protocols
Real-time data handling
📊 Results Achieved:

Multi-sensor data acquisition
Real-time visualization
Data storage
Robust communication
User-friendly interface
This project combines networking, sensors, and user interfaces to create a complete IoT system!
