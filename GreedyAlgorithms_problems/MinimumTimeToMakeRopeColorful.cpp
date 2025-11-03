
// Problem link - https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2025-11-03

#include<bits/stdc++.h>
using namespace std;

int minCost(string colors, vector<int>& neededTime) {
    int n = colors.size();

    int minTime = 0;
    int prevMax = 0;

    for(int i=0; i<n; i++){
        // for new balloon
        if(i>0 && colors[i] != colors[i-1]){
            prevMax = 0;
        } 

        int curr = neededTime[i];

        minTime += min(prevMax, curr);

        prevMax = max(prevMax, curr);
    }

    return minTime;
}

int main(){
    // string colors = "abaac"; 
    // vector<int> neededTime = {1,2,3,4,5};

    // string colors = "abc"; 
    // vector<int> neededTime = {1,2,3};

    string colors = "aabaa"; 
    vector<int> neededTime = {1,2,3,4,1};
    cout<<minCost(colors, neededTime);
    return 0;
}