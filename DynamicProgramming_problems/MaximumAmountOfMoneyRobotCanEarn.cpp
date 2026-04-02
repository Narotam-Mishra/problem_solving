
// Problem link - https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/?envType=daily-question&envId=2026-04-02

#include<bits/stdc++.h>
using namespace std;

// for memoization
int memo[501][501][3];

int m, n;
int solveRec(vector<vector<int>>& coins, int i, int j, int np){
    // base case 1: reached the last cell
    if(i == m-1 && j == n-1){
        if(coins[i][j] < 0 && np > 0){
            // neutralise robber
            return 0;
        }
        return coins[i][j];
    }

    // base case 2
    if(i >= m || j >= n){
        return INT_MIN;
    }

    // if answer is already computed then return
    if(memo[i][j][np] != INT_MIN){
        return memo[i][j][np];
    }

    // case 1 - take current cell value
    int take = coins[i][j] + max(solveRec(coins,i+1,j,np), solveRec(coins,i,j+1,np));
    
    // case 2 - skip current cell if possible
    int skip = INT_MIN;
    if (coins[i][j] < 0 && np > 0) {
        int skipDown = solveRec(coins, i+1, j, np-1);
        int skipRight = solveRec(coins, i, j+1, np-1);

        // find maximum of skipDown & skipRight
        skip = max(skipDown, skipRight);
    }

    // return maximum of take & skip
    return memo[i][j][np] = max(take, skip);
}

int maximumAmount(vector<vector<int>>& coins) {
    // find size of row and column
    m = coins.size();
    n = coins[0].size();

    // step 1 - initialize memoization grid
    for(int i=0; i<501; i++){
        for(int j=0; j<501; j++){
            for(int k=0; k<3; k++){
                memo[i][j][k] = INT_MIN;
            }
        }
    }

    // step 2 - solve recursilvely and return
    return solveRec(coins, 0, 0, 2);
}

int main(){
    // vector<vector<int>> coins = {{0,1,-1},{1,-2,3},{2,-3,4}};

    vector<vector<int>> coins = {{10,10,10},{10,10,10}};
    cout<<maximumAmount(coins);
    return 0;
}