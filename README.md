# HexapodArduinoUpgrade
> Modernization of “Hexapod mobile robot” control system with use of hardware platform Arduino.

**Project goal**
>Control system replacement with PBasic language syntax mapping, that allows for proper interaction between Arduino and servo drive
>LynxMotion SSC-32. 
 
**Project overview**

[![INSERT YOUR GRAPHIC HERE](https://zapodaj.net/images/5ef540cbcaf3b.jpg)]()

Scheme 1. Old control system based on LynxMotion Mini-ABB.

[![INSERT YOUR GRAPHIC HERE](https://zapodaj.net/images/2424a1766f610.jpg)]()

Scheme 2. New control system based on Arduino Leonardo.

[![INSERT YOUR GRAPHIC HERE](https://zapodaj.net/images/ed166b3ae763e.jpg)]()

Photo 1. Hexapod.

[![INSERT YOUR GRAPHIC HERE](https://zapodaj.net/images/1e25ceb3ac588.jpg)]()

Scheme 3. General scheme of hexapod (numbers from 0 to 11 are modeling servos)

## Table of Contents

- [Installation](#installation)
- [Content](#content)
- [Contributing](#contributing)
- [Support](#support)
- [License](#license)

## Installation

1. [Download Arduino IDE](https://www.arduino.cc/en/main/software)
2. Download files from HexapodArduinoUpgrade repository
3. Connect your Arduino (default hardware version is Leonardo)
4. Compile and Run

## Content

**Hexapod.h**
> Header file with declaration of consts and Hexapod class with variables and methods.

**Hexapod.cpp**
> Implementation file with implementation of Hexapod class methods.

**HexapodArduinoUpgrade.cpp**
> Arduino source file with example of working program based on Hexapod library.

## Contributing
For any problems, comments, or feedback please create an issue here on GitHub.

## Support
Contact with me on [my webside](https://adasko18.github.io/)

## License

- **[MIT license](http://opensource.org/licenses/mit-license.php)**
