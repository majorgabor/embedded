## OLED screen

A project to experiment with the ESP32 microcontroller and an OLED screen.

The screen displays a 4 frame animation of Pikachu running, in case the capacity sensor activated on the `GPIO 4` then a *surprised* Pikachu image is shown.

![screenshot](./docs/IMG_0910.gif)

### Hardware
- microcontroller: ESP32 devkit-V1
- OLED screen: GME12864-51

### Setup

Connection between the board and the screen:

| ESP32 Pin   | Screen Pin |
|-------------|------------|
| `3.3V`      | `VIN`      |
| `GND`       | `GND`      |
| `GPIO 22`   | `SCL`      |
| `GPIO 21`   | `SDA`      |

Additionally there is an exposed cable on the `GPIO 4`

### Dependencies
- SSD1306
- GFX