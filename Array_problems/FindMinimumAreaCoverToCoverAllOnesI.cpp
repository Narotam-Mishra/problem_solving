
// Problem link - https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/?envType=daily-question&envId=2025-08-22

#include<bits/stdc++.h>
using namespace std;

int minimumArea(vector<vector<int>>& grid) {
    // edge case: empty grid
    if (grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }

    // find row and column length
    int rows = grid.size();
    int cols = grid[0].size();

    // step 1 - initialize boundaries values to impossible values
    // this will help to detect if we actually find any 1's
    int maxRow = -1; // start with minimum impossible high value
    int minRow = rows; // start with maximum impossible high value
    int minCol = cols;
    int maxCol = -1;

    // step 2 - process entire grid to find boundaries of all 1's
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                // update row boundaries
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);

                // update column boundaries
                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }

    // step 3 - handle edge case if no 1s found in grid
    if (maxRow == -1) {
        // no rectangle needed if no 1's exist, so return 0
        return 0;
    }

    // step 4 - find width and height of rectangle
    int height = maxRow - minRow + 1;
    int width = maxCol - minCol + 1;

    // step 5 - calculate minimum area of rectangle and return
    return height * width;
}

int main(){
    // vector<vector<int>> grid = {{0,1,0},{1,0,1}};

    vector<vector<int>> grid = {{1,0},{0,0}};
    cout<<minimumArea(grid);
}