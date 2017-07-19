/*
    https://github.com/mmlmml1/ESAP17-Robotics-Keyboard
    
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
 */
 

#define TRACE 0
#define INFO 1
#define NOTICE 2
#define WARNING 3
#define LOG_LEVEL 0
#define NONE -1
#define START 0
#define PAUSE 1
#define RESUME 2
#define STOP 3
#define MANUAL 4
#define NOTE 5
#define keyDataPin D0
#define keyClockPin D2
#define keyLatchPin D1
#define numberDataPin D5
#define numberClockPin D7
#define numberLatchPin D6
#define LCDDigit 2
#define boardtime unsigned long
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
using namespace std;
//The length of binary number which can be converted
const int mask[] = {16777216,8388608,4194304,2097152,1048576,524288,262144,131072,65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};
const int last_iterator = sizeof(mask) / 4 - 1;
const char* ssid = "modlab1";
const char* password = "ESAP2017";
const bool isWifiEnabled = false;

const IPAddress ip = IPAddress(192,168,1,73);
const IPAddress defaultGateway = IPAddress(192,168,1,1);
const IPAddress subnetMask = IPAddress(255,255,255,0);
const int UDPPort = 2808;
//BEGIN AUTO-GENERATED ZONE
const int noteInterval = 50;
const int keys = 19;
const int length = 190;
const bool PROGMEM notes[190][19] = {true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, };
//Keys needed:0 C#0 D0 D#0 E0 F0 F#0 G0 G#0 A0 A#0 B0 C1 C#1 D1 D#1 E1 F1 F#1 
//END AUTO-GENERATED ZONE


class _7SegmentsDisplay{
  private:
    void decodeLetters(char letters[],byte *bArray){
      for(int i = 0; i < LCDDigit ; i++){
        switch(letters[i]){
          case '0':
            // 1 2 3 4 5 6 7 8
            // 1 1 1 1 1 0 1 0 
            bArray[i] = 250;
            break;
          case '1':
            // 1 2 3 4 5 6 7 8
            // 0 1 0 1 0 0 0 0
            bArray[i] = 80;
            break;
          case '2':
            // 1 2 3 4 5 6 7 8
            // 1 0 0 1 1 1 1 0
            bArray[i] = 158;
            break;
          case '3':
            // 1 2 3 4 5 6 7 8
            // 1 1 0 0 1 1 1 0
            bArray[i] = 206;
            break;
          case '4':
            // 1 2 3 4 5 6 7 8
            // 0 1 1 1 0 1 0 0
            bArray[i] = 116;
            break;
          case '5':
            // 1 2 3 4 5 6 7 8
            // 0 1 1 0 1 1 1 0
            bArray[i] = 110;
            break;
          case '6':
            // 1 2 3 4 5 6 7 8
            // 1 1 1 0 1 1 1 0
            bArray[i] = 238;
            break;
          case '7':
            // 1 2 3 4 5 6 7 8
            // 0 1 0 1 1 0 0 0
            bArray[i] = 88;
            break;
          case '8':
            // 1 2 3 4 5 6 7 8
            // 1 1 1 1 1 1 1 0
            bArray[i] = 254;
            break;
          case '9':
            // 1 2 3 4 5 6 7 8
            // 0 1 1 1 1 1 1 0
            bArray[i] = 126;
            break;
        }
      }
      
    }

    virtual void displayLetters(byte bArray[]){
      digitalWrite(numberLatchPin, LOW);
      for(int i = 0; i< LCDDigit; i ++){
        shiftOut(numberDataPin, numberClockPin, LSBFIRST, bArray[i]);
      }
      digitalWrite(numberLatchPin, HIGH);
    }
  public:
    virtual void displayLCDs(char letters[]){
      byte bArray[LCDDigit];
      this->decodeLetters(letters, bArray);
      this->displayLetters(bArray);
    }
};

class RegisterAndCommunicationController{
  private:
    int toTen(char array[],int strlen,const int mask[],int last_iterator)
    {
        int temp=0;
        for(int i=strlen-1;i>=0;i--)
            temp+=(1&(array[i]-'0'))*mask[last_iterator--];
        return temp;
    }
    int convertDataFromDavid(bool bArray[], int arraySize){
      if(arraySize % 8 != 0){
        int newSize = arraySize + 8 - (arraySize % 8);
        bool newB[newSize];
        for(int i = 0; i < newSize; i++){
          if(i < arraySize)
            newB[i] = bArray[i];
          else
            newB[i] = false;
        }
        char tenChar[newSize];
        this->toBi(newB, newSize, tenChar);
        return this->toTen(tenChar ,newSize , mask, last_iterator);
      }
      char tenChar[arraySize];
      this->toBi(bArray, arraySize, tenChar);
      return this->toTen(tenChar, arraySize, mask, last_iterator);
    }
    //Bool array to the char array
    void toBi(bool bArray[], int size, char *result)
    {
      for(int i = 0; i < size; i++){
        if(bArray[i])
          result[i] = '1';
        else
          result[i] = '0';
      }
    }
    
  public:
    //Convert data sent from David's program(bool array) to the binary number(to integer)
    virtual bool magic(bool bArray[]){
      int arrSize = keys;
      int val = this->convertDataFromDavid(bArray, arrSize);
      digitalWrite(keyLatchPin, LOW);
      shiftOut(keyDataPin, keyClockPin, LSBFIRST, val);
      //Serial.println(sizeof(bArray));
      if(keys > 8)
        shiftOut(keyDataPin, keyClockPin, LSBFIRST, (val >> 8));
      if(keys > 16)
        shiftOut(keyDataPin, keyClockPin, LSBFIRST, (val >> 16));
      digitalWrite(keyLatchPin, HIGH);
    }
};

class ScoresController {
  private:
    const int diffTime = noteInterval - 15;
    const int interval = noteInterval;
    boardtime startTime = 0;
    boardtime lastUpdatedTime = 0;
    bool isPlaying = false;
    bool useInternalNotes = true;
    bool lastOfflineNotes[keys];
    RegisterAndCommunicationController *output  = new RegisterAndCommunicationController();
    _7SegmentsDisplay *display = new _7SegmentsDisplay();
    virtual void getNotesArrayFromPROGRAM(bool *note, int row){
      for(int i=0; i<keys; i++){
        note[i] = pgm_read_byte(& notes[row][i]);
      }
    }
    
    virtual void getNotes(bool *note, boardtime currentTime){
      if(!useInternalNotes){
        for(int i=0;i<keys;i++){
          note[i] = lastOfflineNotes[i];
          //Serial.print(note[i]);
          
        }
        //Serial.println(" ");
        return;
      }
      int currentRound = (int)((currentTime - this->startTime) / this->interval);
      int timeInterval = (currentTime - this->startTime) - currentRound * interval; 
      bool currentNote[keys];
      this->getNotesArrayFromPROGRAM(currentNote, currentRound);
      //Serial.println(currentRound);
      if(timeInterval <= diffTime && currentRound != 0){
        bool lastNote[keys];
        this->getNotesArrayFromPROGRAM(lastNote, currentRound - 1);
        bool finalNote[keys]; 
        for(int i=0;i<keys;i++){
          if(lastNote[i] == true && currentNote[i] == false){
            note[i] = true;
          } else {
            note[i] = currentNote[i];
          }
        }
      } else {
        for(int i=0;i<keys;i++){
          note[i] = currentNote[i];
        }
      }
      return;
    }

    virtual void debug(int level, string name, string message){
      digitalWrite(LED_BUILTIN, HIGH);
      string type;
      switch(level){
        case TRACE:
          type = "TRACE";
          break;
        case INFO:
          type = "INFO";
          break;
        case NOTICE:
          type = "NOTICE";
          break;
        case WARNING:
          type = "WARNING";
          break;
        default:
          type = "UNKNOWN";
          break;
      }
      if(level >= LOG_LEVEL){
        message = "[" + type + "][" + name + "]" +  message;
        const char *charMessage = message.c_str();
        Serial.println(charMessage);
      } 
      digitalWrite(LED_BUILTIN, LOW);
    }

    //Display notes
    virtual void diplayLetters(char letters[]){
      display->displayLCDs(letters);
    }

    virtual void getDigitToDisplay(bool notes[], char *cArray){
      int count = 0;
      for(int i=0 ;i<keys; i++){
        if(notes[i]){
          //Serial.println(i);
          cArray[count] = '0' + (i+1) % 10;
          count ++;
        }
        if(count >= LCDDigit)
            break;
      }
    }

    virtual void getLettersToDisplay(char letters[], char *cArray){
      for(int i=0 ;i<LCDDigit; i++){
        cArray[i] = letters[i];
      }
    }
    
  public:
    virtual void periodUpdate(){
      boardtime currentTime = millis();
      char lettersToDisplay[LCDDigit];
      if(this->isPlaying){ //playing
        this->lastUpdatedTime = currentTime;
        bool note[keys];
        this->getNotes(note, currentTime);
        output->magic(note);
        memset(lettersToDisplay, '-', sizeof(lettersToDisplay));
        this->getDigitToDisplay(note, lettersToDisplay);
        
        string mes = "";
        for(int i = 0; i<keys; i++){
          if(note[i])
            mes.append("1");
          else
            mes.append("0");
        }
        this->debug(TRACE, "BINARY_OUTPUT",mes);
        if((currentTime - this->startTime) > length * this->interval && useInternalNotes){
          this->stopPlaying();
          this->startPlaying();  
          this->debug(INFO, "STATUS", "Restarting");
        }
      } else {
        if(this->lastUpdatedTime != 0){ //pausing
          this->startTime += currentTime - this->lastUpdatedTime;
          this->lastUpdatedTime = currentTime;
          this->getLettersToDisplay("PA", lettersToDisplay);
        } else { //stoping
          this->getLettersToDisplay("ST", lettersToDisplay);
        }
      }
      this->display->displayLCDs(lettersToDisplay);
    } 
    virtual void passBy(bool note[]){
      if(!this->useInternalNotes)
        Serial.println("notes recieved");
        for(int i=0; i<keys; i++){
          lastOfflineNotes[i]=note[i];
        }
    }
    virtual void startPlaying(){
      this->useInternalNotes = true;
      this->startTime = millis();
      this->lastUpdatedTime = millis();
      this->isPlaying = true;
      this->debug(INFO, "STATUS", "Playing");
    }
    virtual void pausePlaying(){
      if(this->isPlaying && this->useInternalNotes){
        //this->lastUpdatedTime = 0;
        this->isPlaying = false;
        this->debug(INFO, "STATUS", "Pausing");
      }
    }
    virtual void resumePlaying(){
      if(!this->isPlaying && this->useInternalNotes){
        this->isPlaying = true;
        this->debug(INFO, "STATUS", "Resuming");
      }
    }
    virtual void stopPlaying(){
      if(this->useInternalNotes){
        this->isPlaying = false;
        this->lastUpdatedTime = 0;
        this->debug(INFO, "STATUS", "Stoping");
      }
    }
    virtual void manuallyPlaying(){
      this->stopPlaying();
      this->useInternalNotes = false;
      this->isPlaying = true;
      this->debug(INFO, "STATUS", "Manual");
    }
};
WiFiServer server(80);
class WirelessController {
  private:
    WiFiUDP UDPServer;
    const static int packetSize = 64; 
    byte packetBuffer[packetSize];
     
    int phraseData(bool* noteData){
      int instruction = NONE;
      int cb = UDPServer.parsePacket();
      if (cb){
        UDPServer.read(packetBuffer, packetSize);
        switch(packetBuffer[0]){
          case 'A':
            instruction = START;
            break;
          case 'B':
            instruction = PAUSE;
            break;
          case 'C':
            instruction = RESUME;
            break;
          case 'D':
            instruction = STOP;
            break;
          case 'E':
            instruction = MANUAL;
            break;
          case 'F':
            instruction = NOTE;
            for(int i = 1; i<keys+1; i++){
              if(packetBuffer[i] == '0')
                noteData[i-1] = false;
              if(packetBuffer[i] == '1')
                noteData[i-1] = true;
            }
            break;
          default:
            break;
        }
      }
      if(instruction == NONE){
        if(this->phraseDataFromHTML(noteData))
            instruction = NOTE;
      }
      return instruction;
    }

    bool phraseDataFromHTML(bool *noteData){
      WiFiClient client = server.available();
      if (!client)    return false;
      while(!client.available())  delay(1);
      String request =
      client.readStringUntil('\r');
      int index = request.indexOf("/code");
      int endIndex = request.indexOf("HTTP");
      int count = 0;
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<html><body><h1>Select the keys you want to play:</h1><input type='checkbox' id='1'>1<input type='checkbox' id='2'>2<input type='checkbox' id='3'>3<input type='checkbox' id='4'>4<input type='checkbox' id='5'>5<input type='checkbox' id='6'>6<input type='checkbox' id='7'>7<input type='checkbox' id='8'>8<input type='checkbox' id='9'>9<input type='checkbox' id='10'>10<input type='checkbox' id='11'>11<input type='checkbox' id='12'>12<input type='checkbox' id='13'>13<input type='checkbox' id='14'>14<input type='checkbox' id='15'>15<input type='checkbox' id='16'>16<input type='checkbox' id='17'>17<input type='checkbox' id='18'>18<input type='checkbox' id='19'>19<br/><br/><input type='button' onclick='return submit();' value='SUBMIT'><script>    function submit(){        var string = ;        for(var i=1;i<=19;i++){            if(document.getElementById(i).checked == true)                string = string + '1';            else                string = string + '0';        }        xhttp = new XMLHttpRequest();        xhttp.open('GET','/code'+string,true);        xhttp.send(null);        console.log(string);        return false;    }</script></body></html>");
      client.flush();
      if(index != -1){
        for(int i = index + 5; i< endIndex - 1; i++){
          if(request[i] == '0')
            noteData[count] = false;
          else
            noteData[count] = true;
          count++;
        }
        return true;
      } else {
        return false;
      } 
    }
  
  public:
    void setup(){
      WiFi.begin(ssid, password);
      WiFi.config(ip, defaultGateway, subnetMask);
      while (WiFi.status() != WL_CONNECTED) {
        ESP.wdtFeed();
        delay(1000);
        Serial.println("...");
      } 
      UDPServer.begin(UDPPort);
      server.begin();
    }
    void getInstructions(ScoresController *score){
      int instruction;
      bool notes[keys];
      memset(notes,false,sizeof(notes));
      switch(this->phraseData(notes)){
        case START:
          score->startPlaying();
          break;
        case PAUSE:
          score->pausePlaying();
          break;
        case RESUME:
          score->resumePlaying();
          break;
        case STOP:
          score->stopPlaying();
          break;
        case MANUAL:
          score->manuallyPlaying();
          break;
        case NOTE:
          score->passBy(notes);
          break;
        default:
          break;
      }
    }
};

ScoresController *myScore;
WirelessController *wifi;
void checkPause();
void setup() {
  Serial.begin(115200);
  pinMode(keyDataPin, OUTPUT);
  pinMode(keyClockPin, OUTPUT);
  pinMode(keyLatchPin, OUTPUT);
  pinMode(numberDataPin, OUTPUT);
  pinMode(numberClockPin, OUTPUT);
  pinMode(numberLatchPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  myScore = new ScoresController();
  ESP.wdtDisable();
  Serial.println("Ready?");
  if(isWifiEnabled){
    wifi = new WirelessController();
    wifi->setup();
    Serial.println("Ready.");
    myScore->stopPlaying();
  } else {
    myScore->startPlaying();
  }
  
}
void loop() {
  //unsigned long now = millis();
  if(isWifiEnabled){
    wifi->getInstructions(myScore);
  }
  myScore->periodUpdate();
  //checkPause();
  ESP.wdtFeed();
  //Serial.println(millis()-now);
}

/*
void checkPause() {
  if(analogRead(A0) > 500){
    myScore->decodeInstruction("START");
  } else {
    myScore->decodeInstruction("STOP");
  }
}
*/




