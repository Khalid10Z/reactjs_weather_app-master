**CAN Sensor Network Project**  
*September 2024 - October 2024*  
*Affiliated with the National Engineering School of Brest (ENIB)*  

📡 **Introduction:** This project aims to develop a distributed sensor network using the CAN bus as the communication backbone. The goal was to retrieve data from multiple sensors on a host PC via a CAN bus. The sensors, connected to ST-Nucleo microcontrollers, transmit data via CAN frames for real-time display on a GUI.<br>

🔧 **System Architecture:**  
- **3x STM32-Nucleo F411RE Boards**  
- CAN bus for inter-board communication  
- Multiple specialized sensors and one actuator: 🎮 *Dynamixel Servo Motor + Anemometer*, 💡 *Environmental Sensors* (light, pressure, humidity), 🔄 *IMU Module* (accelerometer + gyroscope).<br>

🎯 **Board Distribution:**  
- **Board 1 - Motor Control:** *Robotis Dynamixel Servo Motor*, *SOMFY Anemometer*.  
- **Board 2 - Environment:** *VL6180X (light/distance)*, *LPS22HB (pressure)*, *HTS221 (humidity)*.  
- **Board 3 - Navigation:** *MPU9250 (IMU)*.<br>

💻 **Software Aspects:**  
- CAN Communication  
- GUI with Qt C++  
- SQLite Database  
- I2C, UART Protocols  
- Real-time data handling.<br>

📊 **Results Achieved:**  
- Multi-sensor data acquisition  
- Real-time visualization  
- Data storage  
- Robust communication  
- User-friendly interface.<br>

This project combines networking, sensors, and user interfaces to create a complete IoT system!
