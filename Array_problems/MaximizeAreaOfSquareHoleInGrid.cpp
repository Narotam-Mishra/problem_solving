
// Problem link - https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/?envType=daily-question&envId=2026-01-15

#include<bits/stdc++.h>
using namespace std;

int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
    // sort the input arrays
    sort(hBars.begin(), hBars.end());
    sort(vBars.begin(), vBars.end());

    // keep track of longest consecutive horizontal and vertical bars
    int maxConsecutiveHBar = 1, maxConsecutiveVBar = 1;

    // step 1 - first find length of longest consecutive horizontal bars
    int currConsecutiveHBars = 1;
    for(int i=1; i<hBars.size(); i++){
        if(hBars[i] - hBars[i-1] == 1){
            currConsecutiveHBars++;
        }else{
            currConsecutiveHBars = 1;
        }
        maxConsecutiveHBar = max(maxConsecutiveHBar, currConsecutiveHBars);
    }

    // step 2 - first find length of longest consecutive vertical bars
    int currConsecutiveVBars = 1;
    for(int i=1; i<vBars.size(); i++){
        if(vBars[i] - vBars[i-1] == 1){
            currConsecutiveVBars++;
        }else{
            currConsecutiveVBars = 1;
        }
        maxConsecutiveVBar = max(maxConsecutiveVBar, currConsecutiveVBars);
    }

    // step 3 - find side square formed
    int side = min(maxConsecutiveHBar, maxConsecutiveVBar) + 1;

    // step 4 - return maximum area
    return side * side;
}

int main(){
    // int n = 2, m = 1;
    // vector<int> hBars = {2,3}, vBars = {2};

    // int n = 1, m = 1;
    // vector<int> hBars = {2}, vBars = {2};

    int n = 2, m = 3;
    vector<int> hBars = {2,3}, vBars = {2,4};
    cout<<maximizeSquareHoleArea(n ,m, hBars, vBars);
    return 0;
}