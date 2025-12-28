
// Problem link - https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/?envType=daily-question&envId=2025-12-28

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Using Brute Force Approach
int countNegatives1(vector<vector<int>>& grid) {
    // find row and column size
    int m = grid.size();
    int n = grid[0].size();

    // step 1 - iterate on grid
    int negativeCount = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            // step 2 - check if the number is negative or not
            if(grid[i][j] < 0){
                // increment count
                negativeCount++;
            }
        }
    }

    // step 3 - return negative numbers count
    return negativeCount;
}

// Approach 2 - Optimal Approach using Binary search
int countNegatives2(vector<vector<int>>& grid) {
    // store negative numbers count 
    int negativeNumsCount = 0;

    // step 1 - find first negative element index
    for(auto &row : grid){
        int n = row.size();
        int negativeNumIdx = upper_bound(begin(row), end(row), 0, greater<int>()) - begin(row);
        negativeNumsCount += (n - negativeNumIdx);
    }

    // step 2 - return negative numbers count
    return negativeNumsCount;
}

int countNegatives(vector<vector<int>>& grid) {
    // find grid's row and column size
    int m = grid.size();
    int n = grid[0].size();

    // start from bottom-left of grid
    int row = m-1, col = 0;

    // step 1 - traverse grid using staircase approach
    int negativeNumsCount = 0;
    while(row >= 0 && col < n){
        // check if current element is non-neagtive,
        if(grid[row][col] >= 0){
            // move right
            col++;
        }else{
            // if current number is negative, count negative numbers
            // all elements to the right are also negative
            negativeNumsCount += (n - col);
            // move to row above
            row--;
        }
    }

    // step 2 - return total count of negative numbers
    return negativeNumsCount;
}

int main(){
    // vector<vector<int>> grid = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};

    vector<vector<int>> grid = {{3,2},{1,0}};
    cout<<countNegatives(grid);
    return 0;
}