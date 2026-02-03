
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

int minCost1(vector<vector<int>>& grid, int k) {
    // find size of row and column of grid
    m = grid.size();
    n = grid[0].size();

    // assign value to memoization table
    memo.assign(m, vector<vector<int>>(n, vector<int>(k+1,-1)));

    // step 1 - solve recursilvely and return
    return solveRec(0, 0, 0, k, grid);
}

int minCost(vector<vector<int>>& grid, int k) {
    // step 1 - initialize grid dimensions
    int m1 = grid.size();
    int n1 = grid[0].size();

    // step 2 - create DP table with INT_MAX, set destination cost to 0
    vector<vector<int>> dp(m1, vector<int>(n1, INT_MAX));
    dp[m1-1][n1-1] = 0;

    // step 3 - find maximum grid value to size teleportCost array
    int maxVal = 0;
    for(auto &row : grid){
        for(int &val : row){
            maxVal = max(maxVal, val);
        }
    }

    // step 4 - track minimum cost to reach any cell with each value
    vector<int> teleportCost(maxVal+1, INT_MAX);

    // step 5 - iterate k times to explore k teleportation options
    for(int t=0; t<=k; t++){
        // step 5a - fill DP table bottom-right to top-left
        for(int i=m1-1; i>=0; i--){
            for(int j=n1-1; j>=0; j--){
                // move down cost
                if(i + 1 < m1){
                    dp[i][j] = min(dp[i][j], grid[i+1][j] + dp[i+1][j]);
                }

                // move right cost
                if(j+1 < n1){
                    dp[i][j] = min(dp[i][j], grid[i][j+1] + dp[i][j+1]);
                }

                // teleport to any cell with value <= current value
                if(t > 0){
                    dp[i][j] = min(dp[i][j], teleportCost[grid[i][j]]);
                }
            }
        }

        // step 5b - update teleportCost for each grid value
        for(int i=0; i<m1; i++){
            for(int j=0; j<n1; j++){
                teleportCost[grid[i][j]] = min(teleportCost[grid[i][j]], dp[i][j]);
            }
        }

        // step 5c - propagate costs for values in increasing order (prefix minimum)
        for(int i=1; i<teleportCost.size(); i++){
            teleportCost[i] = min(teleportCost[i], teleportCost[i-1]);
        }
    }

    // step 6 - return minimum cost from start to destination
    return dp[0][0];
}

int main(){
    vector<vector<int>> grid = {{1,3,3},{2,5,4},{4,3,5}};
    int k = 2;

    // vector<vector<int>> grid = {{1,2},{2,3},{3,4}};
    // int k = 1;
    cout<<minCost(grid, k);
    return 0;
}