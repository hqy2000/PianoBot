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

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
const string midiNotes[128] = {"C0","C#0","D0","D#0","E0","F0","F#0","G0","G#0","A0","A#0","B0","C1","C#1","D1","D#1","E1","F1","F#1","G1","G#1","A1","A#1","B1","C2","C#2","D2","D#2","E2","F2","F#2","G2","G#2","A2","A#2","B2","C3","C#3","D3","D#3","E3","F3","F#3","G3","G#3","A3","A#3","B3","C4","C#4","D4","D#4","E4","F4","F#4","G4","G#4","A4","A#4","B4","C5","C#5","D5","D#5","E5","F5","F#5","G5","G#5","A5","A#5","B5","C6","C#6","D6","D#6","E6","F6","F#6","G6","G#6","A6","A#6","B6","C7","C#7","D7","D#7","E7","F7","F#7","G7","G#7","A7","A#7","B7","C8","C#8","D8","D#8","E8","F8","F#8","G8","G#8","A8","A#8","B8","C9","C#9","D9","D#9","E9","F9","F#9","G9","G#9","A9","A#9","B9","C10","C#10","D10","D#10","E10","F10","F#10","G10"};
struct note{
    int time;
    int frequency;
    int length;
};
vector<int> availableKeys = {55,57,60,62,64,65,67,69,71,72,73,74,76,78,79,81,83,85,86};
vector<int> moveBackNotes = {10,13,17};
vector<int> duplicatedNotes = {17,18};
const int interval = 25; // The interval of the midi
const bool addOne = true; // Add one to check stop (set to true when the duration has figures like 499 249 etc)
const bool removeBlank = false; // Remove the blank part at the front
const bool displayMatrix = true; // Display the matrix of the notes
const bool outputKeysNeeded = true; // Output the keys it needed to play the whole song
int returnKeys(int frequency,vector<int> frequencies);
bool findKeys(int key);
bool keyAvailable(int key);
int main() {
    freopen("/Users/hqy/Documents/Github/ESAP17-Robotics-Keyboard/Converter/examples/hongri.middle","r",stdin);
    freopen("/Users/hqy/Documents/Github/ESAP17-Robotics-Keyboard/Converter/examples/hongri.out","w",stdout);
    int time,notes,length;
    int maximum = 0;
    int blank = 1048576;
    int count;
    vector<note> scores;
    vector<int> frequencies;
    while(cin>>time>>notes>>length){
        //if(keyAvailable(notes)) {
            //cout<<notes<<endl;
            if(length == 0){

                bool exist = false;
                for (int i = 0; i < frequencies.size(); i++) {
                    if (notes == frequencies[i]) {
                        exist = true;
                    }
                }
                if (!exist) {
                    frequencies.push_back(notes);
                }
            } else {
                if (addOne)
                    length++;
                length = length / interval;
                time = time  / interval ;
                if (time < blank) {
                    blank = time;
                }
                note a = {
                        .frequency = notes,
                        .time = time,
                        .length = length,
                };
                scores.push_back(a);
                if (length + time > maximum) {
                    maximum = length + time;
                }
                bool exist = false;
                for (int i = 0; i < frequencies.size(); i++) {
                    if (notes == frequencies[i]) {
                        exist = true;
                    }
                }
                if (!exist) {
                    frequencies.push_back(notes);
                }
            //}
        }
    }
    sort(frequencies.begin(), frequencies.end());
    if(removeBlank) {
        maximum -= blank;
        for(int i=0;i<scores.size();i++)
            scores[i].time -= blank;
    }
    bool matrix[maximum][frequencies.size()];
    memset(matrix,false,sizeof(matrix));
    for(int i=0;i<scores.size();i++){
        int key = returnKeys(scores[i].frequency,frequencies);
        //cout<<key<<endl;
        for(int j=scores[i].time;j<scores[i].time+scores[i].length-1;j++){
            matrix[j][key] = true;
        }
    }
    cout<<"//BEGIN AUTO-GENERATED ZONE"<<endl;
    if(displayMatrix){
        for(int i=0;i<maximum;i++){
            for(int j=0;j<frequencies.size();j++){
                if(!findKeys(j)) {
                    if (matrix[i][j] == true)
                        cout << "1";
                    else
                        cout << "0";
                }
            }
            for(int j=0;j<moveBackNotes.size();j++){
                if (matrix[i][moveBackNotes[j]] == true)
                    cout << "1";
                else
                    cout << "0";
            }
            cout<<endl;
        }
    }
    cout<<"const int noteInterval = "<<interval<<";"<<endl;
    cout<<"int keys = "<<frequencies.size()<<";"<<endl;
    cout<<"const int length = "<<maximum<<";"<<endl;
    cout<<"const bool PROGMEM notes["<<maximum<<"]["<<frequencies.size()<<"] = {";
    //int count = 0;
    for(int i=0;i<maximum;i++){
        for(int j=0;j<frequencies.size();j++){
            if(!findKeys(j)) {
                if (matrix[i][j] == true)
                    cout << "true" << ", ";
                else
                    cout << "false" << ", ";
            }
        }
        for(int j=0;j<moveBackNotes.size();j++){
            if (matrix[i][moveBackNotes[j]] == true)
                cout << "true" << ", ";
            else
                cout << "false" << ", ";
        }
        //cout<<endl;
    }
    cout<<"};"<<endl;
    if(outputKeysNeeded){
        cout<<"//Keys needed:";
        for(int i=0;i<frequencies.size();i++)
            if(!findKeys(i))
                if(frequencies[i]<128 && frequencies[i]>0)
                    cout<<midiNotes[frequencies[i]]<<" ";
                else
                    cout<<(frequencies[i] / 1000.0)<<" ";
        for(int j=0;j<moveBackNotes.size();j++){
            if(frequencies[moveBackNotes[j]]<128 && frequencies[moveBackNotes[j]]>0)
                cout<<midiNotes[frequencies[moveBackNotes[j]]]<<" ";
            else
                cout<<(frequencies[moveBackNotes[j]] / 1000.0)<<" ";
        }
        cout<<endl;
    }
    cout<<"//END AUTO-GENERATED ZONE"<<endl;
    //cout<<maximum;
    return 0;
}
bool findKeys(int key){
    for(int i=0; i< moveBackNotes.size(); i++){
        if (key == moveBackNotes[i])
            return true;
    }
    return false;
}
int returnKeys(int frequency,vector<int> frequencies){
    for(int i=0;i<=frequencies.size();i++){
        if(frequencies[i] == frequency)
            return i;
    }
}
bool keyAvailable(int key){
    //cout<<key<<endl;
    for(int i=0;i<19;i++){
        if(key == availableKeys[i])
            return true;

    }
    return false;
}