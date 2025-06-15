
// Problem link - https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/?envType=problem-list-v2&envId=sliding-window

#include<bits/stdc++.h>
using namespace std;

int minimumRecolors(string blocks, int k) {
    int n = blocks.size();

    // step 1 - count white blocks in first window of `k-size`
    int whiteCount = 0;
    for(int i=0; i<k; i++){
        if(blocks[i] == 'W'){
            whiteCount++;
        }
    }

    // step 2 - initialize minimum operations with first window
    int minOperations = whiteCount;

    // step 3 - slide the window across the remaining string starting from `k`
    for(int i=k; i<n; i++){
        // step 4 - remove leftmost character from window if that is white `W`
        if(blocks[i-k] == 'W'){
            whiteCount--;
        }

        // step 5 - add new chracter to the rightmost window, if that is white `W`
        if(blocks[i] == 'W'){
            whiteCount++;
        }

        // step 6 - update minimum operations
        minOperations = min(minOperations, whiteCount);

        // early termination
        if(minOperations == 0){
            break;
        }
    }

    // step 7 - return minimum operations, `minOperations`
    return minOperations;
}

int main(){
    // string blocks = "WBBWWBBWBW"; 
    // int k = 7;

    string blocks = "WBWBBBW"; 
    int k = 2;
    cout<<minimumRecolors(blocks, k)<<endl;
    return 0;
}