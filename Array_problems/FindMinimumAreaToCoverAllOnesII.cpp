
// Problem link - https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/?envType=daily-question&envId=2025-08-23

#include<bits/stdc++.h>
using namespace std;

// utility function to rotate grid
vector<vector<int>> rotateGrid(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();

    // after 90° clockwise rotation: new_rows = original_cols, new_cols = original_rows
    vector<vector<int>> rotatedGrid(n, vector<int>(m));

    // Rotation transformation: (i,j) -> (j, m-1-i)
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            rotatedGrid[j][m-i-1] = grid[i][j];
        }
    }

    // return rotated grid
    return rotatedGrid;
}

// utility function to calculate minimum bounding rectangle area for a set of points
int getMinimumRectangularAreaFromGrid(int sr, int er, int sc, int ec, vector<vector<int>>& grid){
    // get row and column size
    int m = grid.size();
    int n  = grid[0].size();

    // initialize bounds to invalid values to detect if any 1's exist
    int minRow = m, maxRow = -1;
    int minCol = n, maxCol = -1;

    // process the specified region to find bounding box of all 1's
    for(int i=sr; i<er; i++){
        for(int j=sc; j<ec; j++){
            if(grid[i][j] == 1){
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);

                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }

    // edge case - if no 1's found in this region, return 0 
    if(maxRow == -1) return 0;

    // calculate and return minimum area of bounding rectangle
    return (maxRow - minRow + 1) * (maxCol - minCol + 1);
}

int minimumSumHelper(vector<vector<int>>& grid){
    // get row and column size
    int m = grid.size();
    int n  = grid[0].size();

    // store minimum possible sum of the area of three rectangles in `ans`
    int ans = INT_MAX;

    /**
     * Case 1 & 2: Mixed horizontal-vertical splits
     * 
     * we try all possible ways to make one horizontal cut and one vertical cut
     * this creates 3 regions in two different arrangements:
     * 
     * Case 1: ⊥ shape        Case 2: ⊤ shape
     * +-------+-------+      +-------+-------+
     * |   TOP PART    |      |  TL   |   TR  |
     * +-------+-------+      +-------+-------+
     * |  BL   |   BR  |      |   BOTTOM      |
     * +-------+-------+      +-------+-------+
     */

    // try all horizontal cut positions
    for(int rowSplit=1; rowSplit<m; rowSplit++){
        // try all vertical cut positions
        for(int colSplit=1; colSplit<n; colSplit++){

            // case 1: top full-width, bottom split vertically (⊥ shape)
            int topPart = getMinimumRectangularAreaFromGrid(0, rowSplit, 0, n, grid);
            int bottomLeft = getMinimumRectangularAreaFromGrid(rowSplit, m, 0, colSplit, grid);
            int bottomRight = getMinimumRectangularAreaFromGrid(rowSplit, m, colSplit, n, grid);
            ans = min(ans, topPart + bottomLeft + bottomRight);

            // case 2: top split vertically, bottom full-width (⊤ shape)
            int topLeft = getMinimumRectangularAreaFromGrid(0, rowSplit, 0, colSplit, grid);
            int topRight = getMinimumRectangularAreaFromGrid(0, rowSplit, colSplit, n, grid);
            int bottomPart = getMinimumRectangularAreaFromGrid(rowSplit, m, 0, n, grid);
            ans = min(ans, topLeft + topRight + bottomPart);
        }
    }

    /**
     * Case 3: three horizontal strips (≡ shape)
     * 
     * +---------------+
     * |   TOP PART    |
     * +---------------+
     * |  MIDDLE PART  |
     * +---------------+
     * |  BOTTOM PART  |
     * +---------------+
     * 
     * we need 2 horizontal cuts to create 3 horizontal strips
     */

    // first horizontal cut position
    for(int s1=1; s1<m; s1++){ 
        // second horizontal cut position (must be below first) 
        for(int s2=s1+1; s2<m; s2++){
            int topPart = getMinimumRectangularAreaFromGrid(0, s1, 0, n, grid);
            int middlePart = getMinimumRectangularAreaFromGrid(s1, s2, 0, n, grid);
            int bottomPart = getMinimumRectangularAreaFromGrid(s2, m, 0, n, grid);

            ans = min(ans, topPart + middlePart + bottomPart);
        }
    }

    return ans;
}

// there are only 6 fundamental ways to divide any rectangle into 3 non-overlapping pieces
int minimumSum(vector<vector<int>>& grid) {
    // step 1 - try the original orientation
    // case 1: top full-width, bottom split vertically (⊥ shape)
    // case 2: top split vertically, bottom full-width (⊤ shape)
    // case 3 - Three horizontal strips (≡ shape)
    int res = minimumSumHelper(grid);

    // step 2 - rotate grid 90° clockwise and try again
    // this handles Case 4: Three vertical strips (|||)
    // after rotation, vertical strips become horizontal strips
    vector<vector<int>> rotatedGrid = rotateGrid(grid);

    // step 3 - calculate minimum area of rotated grid
    res = min(res, minimumSumHelper(rotatedGrid));

    // step 4 - return minimum possible sum of the area of these rectangles
    return res;
}

int main(){
    // vector<vector<int>> grid = {{1,0,1},{1,1,1}};

    vector<vector<int>> grid = {{1,0,1,0},{0,1,0,1}};
    cout<<minimumSum(grid);
    return 0;
}