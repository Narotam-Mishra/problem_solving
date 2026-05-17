
// Problem link - https://leetcode.com/problems/jump-game-iii/description/?envType=daily-question&envId=2026-05-17

#include<bits/stdc++.h>
using namespace std;

int n;

bool solveRec(vector<int>& arr, int i){
    // base case 1 - check for invalid index
    // check if we already visited
    if(i < 0 || i >= n || arr[i] < 0){
        return false;
    }

    // base case 2 - check if we reach 0 then return true
    if(arr[i] == 0) return true;

    // mark visited by negating the value to prevent revisiting
    arr[i] *= -1;

    // recursive case: try jumping in both directions (forward and backward)
    // p1: jump forward by `i + arr[i]` steps
    // p2: jump backward by `i - arr[i]` steps
    bool p1 = solveRec(arr, i + arr[i]);
    bool p2 = solveRec(arr, i - arr[i]);

    // return true if we 0 from either path
    return p1 || p2;
}

bool canReach(vector<int>& arr, int start) {
    // find size of `arr`
    n = arr.size();

    // step 1 - solve recursively and return
    return solveRec(arr, start);
}

int main(){
    // vector<int> arr = {4,2,3,0,3,1,2};
    // int start = 5;

    // vector<int> arr = {4,2,3,0,3,1,2};
    // int start = 0;

    vector<int> arr = {3,0,2,1,2};
    int start = 2;
    bool res = canReach(arr, start);
    res ? cout<<"true" : cout<<"false";
    return 0;
}