#include <bits/stdc++.h>
using namespace std;

//check if all the processes are finished
bool allTrue(vector<bool>&finished){
    for(auto i : finished){
        if(i == false) return false;
    }
    return true;
}
//function to implement bankers algorithm
string bankersAlgorithm(vector<vector<int>>&allocated,vector<vector<int>>&maxNeed,vector<int>&resources){
    int r = resources.size();
    int n = allocated.size();
    vector<int>columnSum(n,0);
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < n ; j++){
              columnSum[i] += allocated[j][i];
        }
    }
    //calculate the number of each resource that is available
    vector<int>available(r);
    for(int i = 0 ; i < r ; i++){
        available[i] = resources[i] - columnSum[i];
        //if the availability of a resource is negative, it means its not enough
        if(available[i] < 0){
            return "Not enough resources\n";
        }
    }
    string ans = "";
    //now we will calculate need
    vector<vector<int>>need;
    for(int i = 0 ; i < n ; i++){
        vector<int>temp(r);
        for(int j = 0 ; j < r; j++){
            temp[j] = maxNeed[i][j] - allocated[i][j];
        }
        need.push_back(temp);
    }
    //to keep track of finished processes
    vector<bool>finished(r,false);
    string res = "";
    //till all processes are not finished or deadlock is detected
    while(allTrue(finished) == false){
        int numberOfProcessesFinishedInPass = 0;
        for(int i = 0 ; i < n ; i++){
            bool flag = true;
            if(!finished[i]){
                for(int j = 0 ; j < r ; j++){
                   if(available[j] < need[i][j]){
                       flag = false;
                       break;
                   }
                }
                if(flag){
                    finished[i] = true;
                    for(int j = 0 ; j < allocated[i].size(); j++){
                        available[j] += allocated[i][j];
                    }
                    res += "P" + to_string(i) + " ";    
                    numberOfProcessesFinishedInPass++;         
                }
            }
        }
        //if one pass is over and we have not serviced atleast 1 process,
        //the system is in deadlock
        if(numberOfProcessesFinishedInPass == 0) return "Deadlock detected\n";
    }
    return res;
}

int main(){
    vector<vector<int>>allocated = {{0,1,0},{4,0,0},{3,0,2},{2,1,1},{0,0,2}};
    vector<vector<int>>maxNeed = {{7,2,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    vector<int>resources = {10,5,7};
    string result = bankersAlgorithm(allocated,maxNeed,resources);
    cout<<result<<endl;

    return 0;
}
