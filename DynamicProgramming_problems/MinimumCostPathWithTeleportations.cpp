
// Problem link - https://leetcode.com/problems/minimum-cost-path-with-teleportations/

#include<bits/stdc++.h>
using namespace std;

int m, n;

// memoization
vector<vector<vector<int>>> memo;

int solveRec(int i, int j, int t, int k, vector<vector<int>>& grid){
    // base case: reached destination
    if(i == m-1 && j == n-1){
        return 0;
    }

    // if result is precomputed then return result
    if(memo[i][j][t] != -1){
        return memo[i][j][t];
    }

    int res = 1e9+7;
    int currVal = grid[i][j];

    // move right (i,j) -> (i, j+1)
    if(j+1 < n){
        int next = solveRec(i, j+1, t, k, grid);
        res = min(res, grid[i][j+1] + next);
    }

    // move down (i,j) -> (i+1,j)
    if(i+1 < m){
        int next = solveRec(i+1, j, t, k, grid);
        res = min(res, grid[i+1][j] + next);
    }

    // using teleportation (i,j) -> (x,y)
    if(t < k){
        for(int x=0; x<m; x++){
            for(int y=0; y<n; y++){
                if((x != i || y != j) && grid[x][y] <= currVal){
                    res = min(res, solveRec(x, y, t+1, k, grid));
                }
            }
        }
    }

    return memo[i][j][t] = res;
}

int minCost(vector<vector<int>>& grid, int k) {
    // find size of row and column of grid
    m = grid.size();
    n = grid[0].size();

    // assign value to memoization table
    memo.assign(m, vector<vector<int>>(n, vector<int>(k+1,-1)));

    // step 1 - solve recursilvely and return
    return solveRec(0, 0, 0, k, grid);
}

int main(){
    // vector<vector<int>> grid = {{1,3,3},{2,5,4},{4,3,5}};
    // int k = 2;

    vector<vector<int>> grid = {{1,2},{2,3},{3,4}};
    int k = 1;
    cout<<minCost(grid, k);
    return 0;
}