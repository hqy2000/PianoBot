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
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

//BEGIN AUTO-GENERATED ZONE
const int keys = 5;
const int length = 260;
const bool notes[260][5] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, true, false, false, false, false, false, false, };
//END AUTO-GENERATED ZONE



class ScoresController {
  private:
    const int diffTime = 40;
    const int interval = 50;
    boardtime startTime = 0;
    boardtime lastUpdatedTime = 0;
    bool isPlaying = false;
    
    virtual void getNotesArrayFromPROGRAM(bool *note, int row){
      for(int i=0; i<keys; i++){
        note[i] = pgm_read_byte(& notes[row][i]);
      }
    }
    
    virtual void getNotes(bool *note, boardtime currentTime){
      int currentRound = (int)((currentTime - this->startTime) / this->interval);
      int timeInterval = (currentTime - this->startTime) - currentRound * 50; 
      //Serial.println(currentRound);
      bool currentNote[keys];
      this->getNotesArrayFromPROGRAM(currentNote, currentRound);
      if(timeInterval <= diffTime && currentRound != 0){
        bool lastNote[keys];
        this->getNotesArrayFromPROGRAM(lastNote, currentRound - 1);
        //Serial.println(lastNote[0]);
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
          //Serial.print(this->startTime);
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

void setup() {
  myScore = new ScoresController();
  ESP.wdtDisable();
  Serial.begin(115200);
  myScore->startPlaying();
}

void loop() {
  myScore->periodUpdate();
  checkPause();
  ESP.wdtFeed();
  //delay(10);
}

void checkPause() {
  if(analogRead(A0) > 500){
    myScore->pausePlaying();
  } else {
    myScore->resumePlaying();
  }
}




