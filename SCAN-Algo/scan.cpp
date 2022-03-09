#include <bits/stdc++.h>
using namespace std;


class ScanAlgorithm{
    unordered_set<int>inputs;
    int currentPosition;
    int currentTrackHead;
    int maxService;
    int minService;
    int totalTracks;
    bool direction;
    public:
    ScanAlgorithm(vector<int>input,int currentTrack,int total,bool dir){
        maxService = *max_element(input.begin(),input.end());
        minService = *min_element(input.begin(),input.end());
        for(int i = 0 ; i < input.size(); i++){
            inputs.insert(input[i]);
        }
        this->currentPosition = currentTrack;
        this->totalTracks = total;
        this->direction = dir;
    }
    void runScan(){
        vector<int>tracks(totalTracks,0);
        bool move = direction;
            while(inputs.size()){
                if(direction){
                    int j = currentPosition;
                    currentTrackHead = currentPosition;
                    for(j = currentPosition ; j < totalTracks; j++,currentTrackHead++){
                        if(inputs.find(j) != inputs.end()){
                            cout << "Servicing input " << j << endl;
                            inputs.erase(j);
                        }
                    }
                    while(j >= 0){
                        j--;
                        currentTrackHead--;
                    }
                    for(j = 0 ; j < totalTracks && inputs.size(); j++,currentTrackHead++){
                        if(inputs.find(j) != inputs.end()){
                            cout << "Servicing Input " << j << endl;
                            inputs.erase(j);
                        }
                    }
                }
            else{
                currentTrackHead = currentPosition;
                int j = currentPosition;
                while(j >= 0){
                    if(inputs.find(j) != inputs.end()){
                        cout << "Servicing input " << j << endl;
                        inputs.erase(j);
                    }
                    currentTrackHead--;
                    j--;
                }
                for(j = 0 ; j < totalTracks; j++,currentTrackHead++){
                    if(inputs.find(j) != inputs.end()){
                        cout << "Servicing input " << j << endl;
                        inputs.erase(j);
                    }
                }
            }   
        }
    }
    int calculateDistance(){
        if(direction) return totalTracks - currentPosition + totalTracks + currentTrackHead;
        return currentPosition + totalTracks;
    }
};

int main(){
    vector<int>inputs = {176, 79, 34, 60, 92, 11, 41, 114};
    int currentPosition = 50;
    int total = 199;
    bool direction = true;
    ScanAlgorithm sc(inputs,currentPosition,total,direction);
    sc.runScan();
    int ans = sc.calculateDistance();
    cout << "Total distance moved by the track is " << ans <<endl;
    return 0;
}
