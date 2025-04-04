# Beer-O-Meter 🍺

## Overview
This project uses open source technology to measure and display the flow of beer through the tubes of a draft machine. By integrating an Arduino Mega, a flow sensor (XXX), nine Neomatrix 8x8 panels, an RFID reader, and an electronic valve, the system provides real-time insights into the amount of beer dispensed. This solution addresses the common challenge of tracking beer usage, offering a clear and accurate measurement that was previously unavailable.

## Features
- **Real-Time Flow Measurement**: Continuously monitors beer flow using a dedicated sensor.
- **Dynamic Visual Display**: Utilizes nine Neomatrix 8x8 LED panels to present live flow data in an engaging format.
- **User Identification**: Incorporates an RFID reader for user-specific tracking or session management.
- **Automated Control**: Employs an electronic valve to regulate beer flow based on measured data.
- **Open Source & Customizable**: All hardware designs and software code are available for community enhancement and adaptation.

## Components Used
- **Arduino Mega**: Acts as the central microcontroller to coordinate sensor readings, display updates, and control the valve.
- **Flow Sensor XXX**: Accurately measures the flow rate of beer through the draft machine’s tubes.
- **Neomatrix 8x8 Panels (9 pieces)**: LED matrices that visually represent the flow of beer, making the data easy to understand at a glance.
- **RFID Reader**: Facilitates user identification or session-specific data logging.
- **Electronic Valve**: Controls the beer flow, enabling automated management and safety measures.

## System Architecture
The system operates by collecting data from the flow sensor, which is then processed by the Arduino Mega. The processed data is displayed on the LED matrix panels, providing an intuitive visualization of the beer dispensed. Additionally, the RFID reader enables tracking of individual sessions or users, and the electronic valve is used to modulate the beer flow as needed.

## Arduino Code
The heart of this project is the Arduino code, which manages:
- **Sensor Initialization**: Sets up the flow sensor, RFID reader, LED panels, and electronic valve.
- **Data Acquisition**: Reads and processes the flow sensor’s output in real time.
- **Data Display**: Drives the Neomatrix panels to visualize the amount of beer dispensed.
- **User Interaction**: Integrates RFID-based user identification for tailored data logging.
- **Flow Control**: Activates the electronic valve based on pre-defined thresholds to ensure controlled dispensing.

*(For complete details, please refer to the Arduino sketch included in the repository.)*

![diagram](https://github.com/sepse/beer-o-meter/blob/main/Graphics/diagram.jpg)

## Installation & Usage

1. **Hardware Setup**:
   - **Connect the Components**: Assemble the Arduino Mega, flow sensor, RFID reader, electronic valve, and nine Neomatrix 8x8 panels according to the provided wiring diagram.
   - **Mounting**: Secure the LED panels in the desired layout for optimal visual display.

2. **Software Setup**:
   - **Install Libraries**: Ensure that all required Arduino libraries are installed.
   - **Upload the Code**: Open the provided Arduino sketch in the Arduino IDE and upload it to your Arduino Mega.

3. **Operation**:
   - **Power On**: Once all components are connected and the code is uploaded, power on the system.
   - **Start Measuring**: The system will immediately begin monitoring the beer flow and displaying the data on the LED panels.
   - **User Interaction**: Use the RFID cards (if applicable) to initiate or log sessions.

## Potential Enhancements & Future Work
- **Data Logging & Analysis**: Integrate an SD card module or network connection to record historical data and analyze trends.
- **Remote Monitoring**: Add wireless connectivity to enable remote monitoring and control via a web or mobile application.
- **Enhanced User Interface**: Develop an intuitive app interface for real-time monitoring and detailed analytics.
- **Calibration & Optimization**: Further calibrate the flow sensor for enhanced accuracy under varying operating conditions.

## Community & Contributions
This project is fully open source, and contributions are highly encouraged! Whether you’re interested in refining the code, improving the hardware design, or adding new features, your input is welcome. Please feel free to fork the repository, submit issues, or send pull requests.

---

Cheers to innovative technology and smarter beer dispensing! 🍻
