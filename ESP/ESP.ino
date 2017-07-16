
/*
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
 
#define boardtime unsigned long
#define TRACE 0
#define INFO 1
#define NOTICE 2
#define WARNING 3
#define LOG_LEVEL 0
#define dataPin D0
#define clockPin D2
#define latchPin D1
//17-19 are the GPIOs that control the black keys
#define o17 D5
#define o18 D6
#define o19 D7
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdlib>
#include <EasyTransfer.h>
using namespace std;
//The length of binary number which can be converted
const int mask[] = {1048576,524288,262144,131072,65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};
const int last_iterator = sizeof(mask) / 4 - 1;

//BEGIN AUTO-GENERATED ZONE
const int keys = 5;
const int length = 260;
const bool notes[260][5] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, };
//END AUTO-GENERATED ZONE

class RegisterAndCommunicationController{
  private:
    // The class used to communicate with another board
    EasyTransfer ET; 
    struct SEND_DATA_STRUCTURE{
      // The number that will be displayed in the first led
      int16_t led1;
      // The number that will be displayed in the second led
      int16_t led2;
      // The duation of displaying
      int16_t ledduration;
    };
    SEND_DATA_STRUCTURE data;
    // Char array to decimal number
    int toTen(char array[],int strlen,const int mask[],int last_iterator)
    {
        int temp=0;
        for(int i=strlen-1;i>=0;i--)
            temp+=(1&(array[i]-'0'))*mask[last_iterator--];
        return temp;
    }
    int convertDataFromDavid(bool bArray[], int arraySize){
      if(arraySize % 8 != 0){
        int newSize = arraySize + 8 % arraySize;
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
    virtual bool magic(bool bArray[], int duration){
      int arrSize = keys;
      int val = this->convertDataFromDavid(bArray, arrSize);
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, val);
      // If we need more than 8 keys
      shiftOut(dataPin, clockPin, LSBFIRST, (val >> 8));
      digitalWrite(latchPin, HIGH);
      data.led1 = -1;
      data.led2 = -1;
      for(int i = 0; i < arrSize; i++){
        if(bArray[i]){
          data.led1 = i+1;
          break;
        }
      } 
      for(int i = data.led1-1; i < arrSize; i++){
        if(data.led1==-1)
          break;
        if(bArray[i]){
          data.led2 = i+1;
          break;
        }
      }
      data.ledduration = duration;
      //send the data
      //ET.sendData();
    }

    
};

class ScoresController {
  private:
    const int diffTime = 40;
    const int interval = 50;
    boardtime startTime = 0;
    boardtime lastUpdatedTime = 0;
    bool isPlaying = false;
    RegisterAndCommunicationController *output  = new RegisterAndCommunicationController();
    virtual void getNotesArrayFromPROGRAM(bool *note, int row){
      for(int i=0; i<keys; i++){
        note[i] = pgm_read_byte(& notes[row][i]);
      }
    }
    
    virtual void getNotes(bool *note, boardtime currentTime){
      int currentRound = (int)((currentTime - this->startTime) / this->interval);
      int timeInterval = (currentTime - this->startTime) - currentRound * 50; 
      bool currentNote[keys];
      this->getNotesArrayFromPROGRAM(currentNote, currentRound);
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
    }

    virtual void debug(int level, string name, string message){
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
    }

    
   
  public:
    virtual void startPlaying(){
      this->startTime = millis();
      this->isPlaying = true;
      this->debug(INFO, "STATUS", "Playing");
    }
    virtual void pausePlaying(){
      if(this->isPlaying){
        //this->lastUpdatedTime = 0;
        this->isPlaying = false;
        this->debug(INFO, "STATUS", "Pausing");
      }
      
    }
    virtual void resumePlaying(){
      if(!this->isPlaying){
        this->isPlaying = true;
        this->debug(INFO, "STATUS", "Resuming");
      }
    }
    virtual void stopPlaying(){
      this->isPlaying = false;
      this->lastUpdatedTime = 0;
      this->debug(INFO, "STATUS", "Stoping");
    }
    virtual void periodUpdate(){
      boardtime currentTime = millis();
      if(this->isPlaying){ //playing
        bool note[keys];
        this->getNotes(note, currentTime);
        output->magic(note, 10);
        this->lastUpdatedTime = currentTime;
        string mes = "";
        for(int i = 0; i<keys; i++){
          if(note[i])
            mes.append("1");
          else
            mes.append("0");
        }
        this->debug(TRACE, "BINARY_OUTPUT",mes);
        
      } else {
        if(this->lastUpdatedTime != 0){ //pausing
          this->startTime += currentTime - this->lastUpdatedTime;
          this->lastUpdatedTime = currentTime;
        } else { //stoping
        }
      }
      if((currentTime - this->startTime) > length * 50){
        this->stopPlaying();
        this->startPlaying();
        this->debug(INFO, "STATUS", "Restarting");
      }
    };
};

ScoresController *myScore;
void checkPause();
void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  myScore = new ScoresController();
  ESP.wdtDisable();
  Serial.begin(115200);
  myScore->startPlaying();
}
void loop() {
  myScore->periodUpdate();
  checkPause();
  ESP.wdtFeed();
}
void checkPause() {
  if(analogRead(A0) > 500){
    myScore->pausePlaying();
  } else {
    myScore->resumePlaying();
  }
}




