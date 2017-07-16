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
using namespace std;
struct note{
    int time;
    int frequency;
    int length;
};
const int interval = 40; // The interval of the midi
const bool addOne = false; // Add one to check stop (set to true when the duration has figures like 499 249 etc)
const bool removeBlank = true; // Remove the blank part at the front
const bool displayMatrix = false; // Display the matrix of the notes
int returnKeys(int frequency,vector<int> frequencies);
int main() {
    freopen("/Users/hqy/Documents/Github/ESAP17-Robotics-Keyboard/Converter/examples/your_name.in","r",stdin);
    freopen("/Users/hqy/Documents/Github/ESAP17-Robotics-Keyboard/Converter/examples/your_name.out","w",stdout);
    int time,notes,length;
    int maximum = 0;
    int blank = 1048576;
    int count;
    vector<note> scores;
    vector<int> frequencies;
    while(cin>>time>>notes>>length){
        if(addOne)
            length ++;
        length = length / interval;
        time = time / interval;
        if(time<blank) {
            blank = time;
        }
        note a = {
                .frequency = notes,
                .time = time,
                .length = length,
        };
        scores.push_back(a);
        if(length+time>maximum){
            maximum = length+time;
        }
        bool exist = false;
        for(int i=0; i< frequencies.size(); i++){
            if(notes == frequencies[i]){
                exist = true;
            }
        }
        if(!exist){
            frequencies.push_back(notes);
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
    if(displayMatrix){

        for(int i=0;i<maximum;i++){
            for(int j=0;j<=frequencies.size()-1;j++){
                if(matrix[i][j] == true)
                    cout<<"1";
                else
                    cout<<"0";
            }
            cout<<endl;
        }
    }
    //cout<<"keys"<<frequencies.size()-
    cout<<"//BEGIN AUTO-GENERATED ZONE"<<endl;
    cout<<"const int noteInterval = "<<interval<<";"<<endl;
    cout<<"const int keys = "<<frequencies.size()<<";"<<endl;
    cout<<"const int length = "<<maximum<<";"<<endl;
    cout<<"const bool PROGMEM notes["<<maximum<<"]["<<frequencies.size()<<"] = {";
    for(int i=0;i<maximum;i++){
        for(int j=0;j<=frequencies.size()-1;j++){
            if(matrix[i][j] == true)
                cout<<"true"<<", ";
            else
                cout<<"false"<<", ";
        }
        //cout<<endl;
    }
    cout<<"};"<<endl;
    cout<<"//END AUTO-GENERATED ZONE"<<endl;
    //cout<<maximum;
    return 0;
}
int returnKeys(int frequency,vector<int> frequencies){
    for(int i=0;i<=frequencies.size();i++){
        if(frequencies[i] == frequency)
            return i;
    }
}