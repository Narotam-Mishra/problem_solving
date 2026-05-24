
// Problem link - https://leetcode.com/problems/jump-game-v/description/?envType=daily-question&envId=2026-05-24

#include<bits/stdc++.h>
using namespace std;

int n;

// memo[i] stores the maximum number of indices reachable starting at i
vector<int> memo;

// recursive helper with memoization.
int solveRec(int i, vector<int>& arr, int d){
    // return cached result if available
    if(memo[i] != -1) return memo[i];

    // keep track of maximum number of indices visited
    int ans = 1;

    // case 1 - explore left jumps from i (up to distance d)
    for(int j = i-1; j >= max(0, i-d); j--){
        if(arr[j] >= arr[i]) break; // blocked by higher/equal value
        ans = max(ans, 1 + solveRec(j, arr, d));
    }

    // case 2 - explore right jumps from i (up to distance d)
    for(int j = i+1; j <= min(n-1, i+d); j++){
        if(arr[j] >= arr[i]) break; // blocked
        ans = max(ans, 1 + solveRec(j, arr, d));
    }

    // cache and return
    return memo[i] = ans;
}

int maxJumps(vector<int>& arr, int d) {
    n = arr.size();

    // step 1 - initialize memo size to n and mark all as uncomputed
    memo.assign(n, -1);

    // step 2 - try starting from each index and take the best result
    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, solveRec(i, arr, d));
    }

    // step 3 - return maximum number of indices visited
    return res;
}

int main(){
    // vector<int> arr = {6,4,14,6,8,13,9,7,10,6,12};
    // int d = 2;

    // vector<int> arr = {3,3,3,3,3};
    // int d = 3;

    vector<int> arr = {7,6,5,4,3,2,1};
    int d = 1;
    cout<<maxJumps(arr, d);
    return 0;
}