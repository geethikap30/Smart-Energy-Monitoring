# Smart-Energy-Monitoring

This project implements a Smart Energy Monitoring System using NodeMCU, ACS712 Current Sensor, and ThingSpeak for real-time monitoring of energy consumption. The system reads current data, calculates power usage, and sends it to the ThingSpeak IoT platform, where you can visualize the energy consumption on a dashboard. It also allows efficient energy management by monitoring and analyzing usage patterns.

## Features
- **Real-Time Monitoring:** Continuously tracks current and power consumption in real-time.
- **Data Logging:** Sends current and power data to ThingSpeak for analysis and visualization.
- **Energy Management:** Helps in understanding and managing energy usage patterns.
## Hardware Components
- **NodeMCU ESP8266:** Microcontroller with WiFi capability to send data to ThingSpeak.
- **ACS712 Current Sensor:** Measures the current drawn by the connected appliances.
- Resistors, LEDs, Wires (optional for indicating energy thresholds).
## Software Requirements
- **Arduino IDE:** For programming the NodeMCU.
- **ThingSpeak API Key:** Required to send data to your ThingSpeak account.
