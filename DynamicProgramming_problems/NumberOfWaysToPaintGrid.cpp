
// Problem link - https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/?envType=daily-question&envId=2026-01-03

#include<bits/stdc++.h>
using namespace std;

// defined all valid color states for a row
vector<string> states = {"RYG","RGY","RYR","RGR","YRG","YGR","YGY","YRY","GRY","GYR","GRG","GYG"};

// modulo value
const int mod = 1e9 + 7;

// memo for memoization
// memo[n][state] stores number of ways for `n` rows with previous row = state
vector<vector<int>> memo;

int solveRec(int n, int pr){
    // base case - if no row left to paint,
    // then count 1 valid configuration
    if(n == 0){
        return 1;
    }

    // return precomputed value
    if(memo[n][pr] != -1){
        return memo[n][pr];
    }
    
    int res = 0;

    // try all curent row states
    string lastCC = states[pr];
    for(int cr=0; cr<12; cr++){
        if(cr == pr) continue;

        string currPattern = states[cr];
        bool conflict = false;

        // check vertical conflicts
        for(int c=0; c<3; c++){
            if(currPattern[c] == lastCC[c]){
                conflict = true;
                break;
            }
        }

        // check if there no conflict and compute number of ways
        if(!conflict){
            res = (res + solveRec(n-1, cr)) % mod;
        }
    }

    // memoize and return
    return memo[n][pr] = res;
}

int numOfWays(int n) {
    memo.resize(n, vector<int>(12,-1));
    int ans = 0;

    // step 1 - try all possible first-row pattern
    for(int i=0; i<12; i++){
        // step 2 - perform computation using recursion
        ans = (ans + solveRec(n-1, i)) % mod;
    }

    // step 3 - return final answer, `ans`
    return ans;
}

int main(){
    // int n = 1;

    int n = 5000;
    cout<<numOfWays(n);
    return 0;
}