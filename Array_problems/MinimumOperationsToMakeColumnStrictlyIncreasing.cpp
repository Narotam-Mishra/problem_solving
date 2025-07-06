
// Problem link - https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing/

#include<bits/stdc++.h>
using namespace std;

int minimumOperations(vector<vector<int>>& grid) {
    // calculate grid's row and column size
    int m = grid.size();
    int n = grid[0].size();

    // store minimum number of operation
    int operations = 0;

    // step 1 - loop through each column
    for (int col = 0; col < n; col++) {
        // step 2 - traverse the column from top to bottom
        for (int row = 1; row < m; row++) {
            // step 3 - check if current value is not greater than the value above it
            if (grid[row][col] <= grid[row - 1][col]) {
                // step 4 - calculate how much increment needed to make it strictly increasing
                int incrementNeeded = grid[row - 1][col] - grid[row][col] + 1;

                // step 5 - add total operations
                operations += incrementNeeded;

                // step 6 - update the current value logically
                grid[row][col] = grid[row - 1][col] + 1;
            }
        }
    }

    // step 7 - return minimum number of operation
    return operations;
}

int main(){
    // vector<vector<int>> grid = {{3,2},{1,3},{3,4},{0,1}};

    vector<vector<int>> grid = {{3,2,1},{2,1,0},{1,2,3}};
    cout<<minimumOperations(grid)<<endl;
    return 0;
}