# Braille Watch with 8x8 LED Matrix Display

This project focuses on creating a Braille watch using an 8x8 LED matrix and an Arduino board, providing a tactile representation of time in Braille characters for visually impaired individuals.

# Overview

The Braille watch utilizes an Arduino board connected to an 8x8 LED matrix to display time in Braille characters. It retrieves time data from an RTC module and converts it into Braille format for display on the LED matrix.

# Features

- Tactile Display: Utilizes an 8x8 LED matrix to present time information in Braille characters.
- Real-time Clock Integration: Fetches accurate time from an RTC module.
- User Interaction: Allows for setting time or navigating through different modes using buttons.
- Low Power Consumption: Designed for efficient power usage to extend battery life.

# Materials Used
- Arduino board (Arduino Uno or similar)
- 8x8 LED Matrix (MAX7219 or equivalent)
- Real-time clock (RTC) module (DS3231 or similar)
- Pushbuttons for user interaction
- Resistors, capacitors, and connecting wires
- Power source (battery or USB power)

# Dependencies
- MaxMatrix library: Used to control the 8x8 LED matrix.
- RTC library: For interfacing with the real-time clock module.
- Custom Braille conversion functions (specific to the project).

# Setup

- Connect Components:
  - Wire the 8x8 LED matrix to the Arduino board following the pin configuration for the MAX7219 or equivalent.
  - Connect the RTC module to the Arduino using appropriate pins.
  - Include pushbuttons for user interaction and setting adjustments.

- Install Libraries:
  - Install the MaxMatrix and RTC libraries from the provided links.
  - Include any custom Braille conversion functions in the Arduino sketch.

- Upload Code:
  - Upload the Arduino sketch (provided in the repository) to the Arduino board.

- Assemble the Watch:
  - Arrange the components in a watch-like enclosure, ensuring user accessibility to buttons and the LED matrix.

# Usage
- Power on the Braille watch.
- Use the buttons to set the time or navigate through different modes (if available).
- The time in Braille characters will be displayed on the 8x8 LED matrix.

# Customization
Feel free to modify the code to add additional features, customize the display format, or enhance user interaction based on individual preferences.

# Contributing
Contributions are welcomed! Fork this repository, make changes, and submit pull requests to improve the project.
