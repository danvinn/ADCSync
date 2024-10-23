# CCT GUI Setup Application

## Overview
The CCT GUI Setup Application is a Qt-based desktop application designed for visualizing and interacting with sensor data. This project demonstrates a system for collecting and transmitting sensor data from a VN-100 IMU/AHRS to a host laptop. The system utilizes an STM32F446RE microcontroller as the central processing unit, an HM-10 Bluetooth Low Energy (BLE) module for wireless communication, and an nRF52840 microcontroller as a gateway between the BLE network and the host laptop.

![C&DH Hardware Process](https://github.com/danvinn/ADCSync/blob/main/img/cdh_flow.drawio.png)

![C&DH High-Level State Machine](https://github.com/danvinn/ADCSync/blob/main/img/stateMachine.png)

## Features
- **Sensor Diagnostics**: Verifies sensor integrity with a checksum check.
- **Real-time Data Plotting**: Displays angular momentum over time using QCustomPlot.
- **Data Download**: Allows users to download sensor data in CSV format.

## Installation
1. Download the `CCT Setup.exe` created using Inno Setup Wizard.
2. Follow the installation instructions to set up the application on your system.

## Usage
- Click **Run Sensor Diagnostic** to initiate a checksum verification.
- Click **Start System** to begin data collection and visualization.
- Click **Stop System** to halt data collection and clear the plots.
- Click **Download Data** to retrieve the current data as a CSV file.

## Dependencies
- Qt framework
- QCustomPlot library

## Contributing
Contributions are welcome! Please submit a pull request or open an issue for suggestions.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
