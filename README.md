# smart-Vehicle-Parking-Project

# 🚗🔻Smart Vehicle Parking System!🔻🚗

Hello everyone, I'm thrilled to introduce my recent project, the Smart Vehicle Parking System. This project was a comprehensive journey from requirement gathering to final implementation, and I'm proud to share the details with you.

## 🔧 Project Overview:
Throughout this project, I had the opportunity to apply my expertise in embedded systems and software development to create an innovative system that epitomizes the synergy of UART technologies, SPI protocols, and user-centric dashboards, all working in tandem to streamline parking management.

An essential aspect of this project was implementing the Agile Scrum methodology using Jira software. I divided the project into epics, each with functional software, user stories, and tasks. Using four sprints for the project's first release, I leveraged iterative development to ensure each phase was a reflection of precision and innovation.

## Video Preview:
Watch the video below to see the Smart Vehicle Parking System in action:

[![Smart Vehicle Parking System Video](https://github.com/mohamed-belall/smart-Vehicle-Parking-Project/assets/77551534/ac895918-48d2-4e72-9aec-6ac7967f724a)](https://www.linkedin.com/posts/mohamed-belal-%F0%9F%87%B5%F0%9F%87%B8-355316218_agile-scrum-jira-activity-7199492523088572416-ZhKV?utm_source=share&utm_medium=member_desktop)


## System Components:
| ECU | Description | Drivers | Functions |
| --- | ----------- | ------- | --------- |
| **ECU1: ATMEGA32** | Manages the entrance gate | **MCAL**: UART, SPI, PWM, GPIO, EXTI <br> **HAL**: RFID, PIR, LCD, Servomotor, Buzzer | LCD Display, RFID Reader, Servo Motor, PIR Sensor, LED Indicators, Buzzer |
| **ECU2: ATMEGA32** | Manages the exit gate | **MCAL**: UART, SPI, PWM, GPIO, EXTI <br> **HAL**: RFID, PIR, Servomotor | RFID Reader, Servo Motor, PIR Sensor |
| **ECU3: STM32F103C6T8** | Manages the admin dashboard | **MCAL**: USART, SPI, RCC, GPIO, EXTI <br> **HAL**: 7Segment, Keypad, LCD | Password Protection, Admin Functions, Connectivity with ECU1 & ECU2 |

## Detailed System Functionality:
### 1. Entrance Gate (ECU1: ATMEGA32):
- **LCD Display**: Displays messages to the user.
- **RFID Reader**: Reads card IDs (simulated with Terminal and UART).
- **Servo Motor**: Controls the gate's opening and closing.
- **PIR Sensor**: Prevents gate closure if a vehicle is underneath.
- **LED Indicators**:
  - **Red LED**: Signals unauthorized ID entry.
  - **Green LED**: Signals authorized ID entry.
- **Buzzer**: Sounds an alert in case of unauthorized ID entry.

### 2. Exit Gate (ECU2: ATMEGA32):
- **RFID Reader**: Reads card IDs (simulated with Terminal and UART).
- **Servo Motor**: Controls the gate's opening and closing.
- **PIR Sensor**: Prevents gate closure if a vehicle is underneath.

### 3. Admin Dashboard (ECU3: STM32F103C6T8):
- **Password Protection**: Ensures only authorized personnel can access the system.
- **Admin Functions**:
  - **Add ID**: Allows addition of new user IDs.
  - **Delete ID**: Allows deletion of specific user IDs.
  - **Delete All IDs**: Clears all stored user IDs.
  - **View IDs**: Displays all stored user IDs.
- **Connectivity**: ECU1 and ECU2 are connected to ECU3 via SPI, sending ID information for verification and receiving actions based on authorization status.

## Development Process:
### Agile Scrum Methodology:
- **Epics**: Major functional areas of the project.
- **User Stories**: Detailed requirements within each epic.
- **Tasks**: Specific work items to be completed.
- **Sprints**: Four iterative development cycles to ensure continuous improvement and timely delivery.

## Technologies and Tools Used:
- **Microcontrollers**: ATMEGA32, STM32F103C6T8
- **Communication Protocols**: UART, SPI
- **Sensors and Actuators**: RFID Reader, PIR Sensor, Servo Motor
- **Indicators**: LCD Display, LED Indicators, Buzzer
- **Development Tools**: Jira for Agile project management
- **Programming Languages**: C/C++

## Conclusion
The Smart Vehicle Parking System represents a cohesive integration of embedded system technologies to enhance parking management efficiency. By leveraging Agile methodologies and robust hardware-software interaction, this project delivers a user-friendly and secure parking solution.

Thank you for taking the time to learn about my project. I hope you find it as exciting and innovative as I do!
