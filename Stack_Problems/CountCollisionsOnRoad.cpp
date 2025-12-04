
// Problem link - https://leetcode.com/problems/count-collisions-on-a-road/description/?envType=daily-question&envId=2025-12-04

#include<bits/stdc++.h>
using namespace std;

int countCollisions(string directions) {
    int n = directions.length();
    
    // step 1 - define left & right boundary
    int i = 0;
    while(i < n && directions[i] == 'L'){
        i++;
    }

    // right boundary
    int j = n-1;
    while(j >= 0 && directions[j] == 'R'){
        j--;
    }

    // step 2 - count collisions
    int collisons = 0;
    while(i <= j){
        if(directions[i] != 'S'){
            collisons++;
        }
        i++;
    }

    // step 3 - return number of collisons
    return collisons;
}

int main(){
    string directions = "RLRSLL";

    // string directions = "LLRR";
    cout<<countCollisions(directions);
    return 0;
}