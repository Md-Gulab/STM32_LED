# STM32 7-Segment LED Interfacing

A bare-metal firmware project to interface a 7-segment display and a buzzer with the STM32F446RE (ARM Cortex-M4) microcontroller. This project demonstrates register-level GPIO configuration and manual delay implementation.

## 🚀 Features
* Register-Level Programming: Configures GPIO ports A, B, and C directly using `MODER` and `RCC` registers.
* Non-HAL Approach: Minimal use of abstraction for better understanding of MCU architecture.
* Modular Code: Clear pin mapping for segments A-G and the common pin.

## 🛠️ Hardware Requirements
* Microcontroller: STM32F446RE Nucleo-64
* Display: 7-Segment Display (Common Cathode)
* Buzzer
* Connectivity: Breadboard and Jumper wires
* Current Limiting: 220Ω Resistors

## 📌 Pin Mapping
| Segment | STM32 Pin | Register |
|:-------:|:---------:|:--------:|
| A       | PA9       | GPIOA    |
| B       | PA8       | GPIOA    |
| C       | PB4       | GPIOB    |
| D       | PB5       | GPIOB    |
| E       | PB3       | GPIOB    |
| F       | PA10      | GPIOA    |
| G       | PA5       | GPIOA    |

### 📺 Demonstration
Click the image below to watch the project demonstration on YouTube:

[![STM32 Project Demo](https://img.youtube.com/vi/uiUG7h6x89I/0.jpg)](https://youtu.be/uiUG7h6x89I)

## 💻 How to Build
1. Clone this repository: git clone https://github.com/Md-Gulab/STM32_LED.git
2. Open STM32CubeIDE.
3. Go to File -> Import -> Existing Projects into Workspace.
4. Select this project folder and click Finish.
5. Build and Flash to your Nucleo board.

👨‍💻 Author
Muhammad Gulab, 3rd Year B.Tech (ECE), Jamia Millia Islamia, New Delhi