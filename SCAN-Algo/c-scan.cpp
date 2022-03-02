#include <bits/stdc++.h>
using namespace std;


class CScanAlgorithm{
    unordered_set<int>inputs;
    int currentPosition;
    int maxService;
    int minService;
    int totalTracks;
    bool direction;
    public:
    CScanAlgorithm(vector<int>input,int currentTrack,int total,bool dir){
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
                    for(j = currentPosition ; j < maxService; j++){
                        if(inputs.find(j) != inputs.end()){
                            cout << "Servicing input " << j << endl;
                            inputs.erase(j);
                        }
                    }
                    while(j >= minService){
                        if(inputs.find(j) != inputs.end()){
                            cout << "Servicing input " << j << endl;
                            inputs.erase(j); 
                        }
                        j--;
                    }
                }
            else{
                int j = currentPosition;
                while(j >= minService){
                    if(inputs.find(j) != inputs.end()){
                        cout << "Servicing input " << j << endl;
                        inputs.erase(j);
                    }
                    j--;
                }
                for(j = 0 ; j < maxService; j++){
                    if(inputs.find(j) != inputs.end()){
                        cout << "Servicing input " << j << endl;
                        inputs.erase(j);
                    }
                }
            }   
        }
    }
    int calculateDistance(){
        if(direction) return maxService - currentPosition + (maxService - minService);
        return (currentPosition - minService) + (maxService - minService);
    }
};

int main(){
    vector<int>inputs = {53,95,193,64,24,16,40};
    int currentPosition = 50;
    int total = 200;
    bool direction = true;
    CScanAlgorithm sc(inputs,currentPosition,total,direction);
    sc.runScan();
    int ans = sc.calculateDistance();
    cout << "Total distance moved by the track is " << ans <<endl;
    return 0;
}
