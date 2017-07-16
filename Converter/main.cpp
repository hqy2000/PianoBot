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
int returnKeys(int frequency,vector<int> frequencies);
int main() {
    freopen("/Users/hqy/Documents/Github/ESAP17-Robotics-Keyboard/Converter/examples/happy_birthday.in","r",stdin);
    freopen("/Users/hqy/Documents/Github/ESAP17-Robotics-Keyboard/Converter/examples/happy_birthday.out","w",stdout);
    int time,notes,length;
    int maximum = 0;
    int count;
    vector<note> scores;
    vector<int> frequencies;
    while(cin>>time>>notes>>length){
        length ++;
        length = length / 50;
        time = time / 50;
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
    bool matrix[maximum][frequencies.size()];
    memset(matrix,false,sizeof(matrix));
    for(int i=0;i<scores.size();i++){
        int key = returnKeys(scores[i].frequency,frequencies);
        //cout<<key<<endl;
        for(int j=scores[i].time;j<scores[i].time+scores[i].length-1;j++){
            matrix[j][key] = true;
        }
    }
    //cout<<"keys"<<frequencies.size()-
    cout<<"//BEGIN AUTO-GENERATED ZONE"<<endl;
    cout<<"const int keys = "<<frequencies.size()<<";"<<endl;
    cout<<"const int length = "<<maximum<<";"<<endl;
    cout<<"const PROGMEM bool notes["<<maximum<<"]["<<frequencies.size()<<"] = {";
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