# Wearable Sensor-Based System for Detecting Neck and Back Posture Problems


This project is designed for biomedical monitoring using STM32 and NodeMCU. It allows for wireless data collection and real-time reporting of a patient's vital signs to a local server. The project includes a combination of hardware and software components, including sensor measurements, algorithm calculations, data transmission via Wi-Fi, and a user-friendly web interface.

## Table of Contents

- [Features](#features)
- [Hardware Setup](#hardware-setup)
- [Software Setup](#software-setup)
- [Usage](#usage)
- [Calibration](#calibration)
- [API](#api)
- [Contributing](#contributing)
- [Video](#video)
- [License](#license)

## Features

- Collects data from digital and analog sensors.
- Utilizes I2C and UART for data communication between STM32 and NodeMCU.
- Displays data through a web interface with animations.
- Allows for real-time monitoring and data visualization.
- Provides a calibration feature for sensor accuracy.
- Exposes raw data in JSON format through an API.

## Hardware Setup

- STM32 is responsible for reading sensor data, performing algorithm calculations, and transmitting data to NodeMCU.
- Analog sensors are connected to STM32 through a custom-designed circuit.
- Digital sensors communicate with STM32 using I2C.
- NodeMCU receives data from STM32 via UART.
- Ensure proper wiring and connections according to the project documentation.

## Software Setup

- Flash the firmware onto both STM32 and NodeMCU boards.
- Set up a local Wi-Fi network for NodeMCU to connect to.
- Install any necessary libraries or dependencies for the microcontrollers.
- Configure the web interface and animations as needed.
- Ensure all required software components are properly installed and configured.

## Usage

1. Power on the STM32 and NodeMCU boards.
2. Wait for the devices to establish a Wi-Fi connection.
3. Access the web interface through a browser by entering the NodeMCU's IP address.
4. View real-time data, animations, and patient information.
5. Utilize the calibration feature for sensor accuracy.
6. Data is automatically sent to a local server for storage and analysis.

## Calibration

- The calibration feature allows for adjustment of sensor readings if necessary.
- Follow the on-screen instructions to calibrate each sensor.
- Calibrated data is stored for more accurate measurements.

## API

- Access raw sensor data through the API endpoint:
http://your-server-ip/data
- Data is provided in JSON format.

## Contributing

- Contributions to this project are welcome.
- Fork the repository, make your changes, and submit a pull request.

## Video

[![Video](https://img.youtube.com/vi/uOef-rk86xs/0.jpg)](https://www.youtube.com/watch?v=uOef-rk86xs)

## License

This project is licensed under the [MIT License](LICENSE).
