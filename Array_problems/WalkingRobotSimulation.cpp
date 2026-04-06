
// Problem link - https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2026-04-06

#include<bits/stdc++.h>
using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    // step 1 - set to access obstacles quickly
    unordered_set<string> st;
    for(vector<int>& obs : obstacles){
        string key = to_string(obs[0]) + "_" + to_string(obs[1]);
        st.insert(key);
    }

    // start simulation
    int x = 0, y = 0;
    int maxDistance = 0;

    // pointing to North dir
    pair<int, int> dir = {0,1};

    // step 2 - move through each command 
    for(int i=0; i<commands.size(); i++){
        if(commands[i] == -2){
            // turn left 90 degree
            dir = {-dir.second, dir.first};
        }
        else if(commands[i] == -1){
            // turn right 90 degree
            dir = {dir.second, -dir.first};
        }else{
            // move to the direction step by step
            for(int s=0; s<commands[i]; s++){
                int newX = x + dir.first;
                int newY = y + dir.second;

                // check if newX & newY is part of obstacles
                string nextKey = to_string(newX) + "_" + to_string(newY);
                if(st.find(nextKey) != st.end()){
                    break;
                }

                x = newX;
                y = newY;
            }
        }

        // step 3 - update maximum distance
        maxDistance = max(maxDistance, x*x + y*y);
    }

    // step 4 - return final maximum distance
    return maxDistance;
}

int main(){
    // vector<int> commands = {4,-1,3}; 
    // vector<vector<int>> obstacles = {};

    // vector<int> commands = {4,-1,4,-2,4}; 
    // vector<vector<int>> obstacles = {{2, 4}};

    vector<int> commands = {6,-1,-1,6}; 
    vector<vector<int>> obstacles = {{0, 0}};
    cout<<robotSim(commands, obstacles);
    return 0;
}