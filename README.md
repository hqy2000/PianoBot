# ESAP17-Robotics-Keyboard
## Authors
Tom Liu & Qingyang Hu
## Introduction
This is the code for our final project in University of Pennsylvania ESAP Robotics program - a robot which can play keyboard.
## Dependencies
* midicsv
* [midicsv2frequency.pl](https://gist.github.com/clarkli86/9914952)
## How to use
1. Use midicsv to convert your midi file into csv file. The command line should be 'midicsv <input> <output>'. See http://manpages.ubuntu.com/manpages/zesty/man5/midicsv.5.html for detail usage.
2. Use the midicsv2frequency.pl to convert your csv into c++ input format file. The command line should be 'cat <input> | perl midicsv2frequency.pl > <output>' Please use the script inside the Converter folder, since we have slightly changed the output style. There are three examples of output files in the examples folder. PS: If the output file has negative values, use Excel to open the csv file, and then rank the data according to the "C" column with Z-A. Then it should output normal values.
3. Compile the Converter. Edit the freopen file name to your music sheet. If the program cannot open the file, please include the path in the filename string. You can change the const options to satisfy your own needs
4. Copy all the content from the .out file to the arduino source code file. It should be about 6 lines starting with //START AUTO-GENERATED ZONE and ending with //END AUTO-GENERATED ZONE. Remember to delete old generated lines.
5. Edit the pins according to your board.
6. Upload and have fun!
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
