
// Problem link - https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/?envType=daily-question&envId=2025-11-26

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// memoize the answer
vector<vector<vector<int>>> memo;

int solve(int r, int c, int currSum, int k, vector<vector<int>>& grid, int m, int n){
    // edge case:
    if(r >= m || c >= n) return 0;

    // base case:
    if(r == m-1 && c == n-1){
        return (currSum + grid[m-1][n-1]) % k == 0 ? 1 : 0;
    }

    // if answer is already computed then return the answer
    if(memo[r][c][currSum] != -1){
        return memo[r][c][currSum] % mod;
    }

    // recursive case: recursively move down and right respectively
    int down = solve(r+1, c, (currSum + grid[r][c]) % k, k, grid, m, n);
    int right = solve(r, c+1, (currSum + grid[r][c]) % k, k, grid, m, n);

    return memo[r][c][currSum] = (down + right) % mod;
}

int numberOfPaths(vector<vector<int>>& grid, int k) {
    // find rows and colums size of grid
    int m = grid.size();
    int n = grid[0].size();

    memo.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));

    // step 1 - solve the problem recursively
    return solve(0, 0, 0, k, grid, m, n);
}

int main(){
    // vector<vector<int>> grid  = {{5,2,4},{3,0,5},{0,7,2}}; 
    // int k = 3;

    // vector<vector<int>> grid  = {{0,0}}; 
    // int k = 5;

    vector<vector<int>> grid  = {{7,3,4,9},{2,3,6,2},{2,3,7,0}}; 
    int k = 1;
    cout<<numberOfPaths(grid, k);
    return 0;
}