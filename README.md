# ESAP17-Robotics-Keyboard
## Authors
Tom Liu & Qingyang Hu
## Introduction
This is the code for our final project in University of Pennsylvania ESAP Robotics program - a robot which can play keyboard.
## Dependencies
* [madsci1016/Arduino-EasyTransfer](https://github.com/madsci1016/Arduino-EasyTransfer)
## How to use
1. Compile the Converter. Edit the freopen file name to your music sheet. If the program cannot open the file, please include the path in the filename string. The input data style should be {startTime[mS]} {Freqduration[Hz]} {duration[mS]}. There are two examples in the examples folder.
2. Copy all the content from the .out file to the arduino source code file. It should be about 5 lines starting with //START AUTO-GENERATED ZONE and ending with //END AUTO-GENERATED ZONE. Remember to delete old generated lines.
3. Edit the pins to your board.
4. Upload and have fun!
## Circuit

## Software License
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
## Document License
    Copyright (C)  Tom Liu & Qingyang Hu
    Permission is granted to copy, distribute and/or modify this document
    under the terms of the GNU Free Documentation License, Version 1.3
    or any later version published by the Free Software Foundation;
    with no Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts.
    A copy of the license is included in the section entitled "GNU
    Free Documentation License".
