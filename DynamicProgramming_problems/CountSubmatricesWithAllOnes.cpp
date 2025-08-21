
// Problem link - https://leetcode.com/problems/count-submatrices-with-all-ones/?envType=daily-question&envId=2025-08-21

#include<bits/stdc++.h>
using namespace std;

int numSubmat(vector<vector<int>>& mat) {
    // find row and column size of matrix
    int row = mat.size();
    int col = mat[0].size();

    // step 1 - precompute consecutive 1s for each row
    // consecutive[r][c] = number of consecutive 1s starting from (r,c) going right
    for (int r = 0; r < row; r++) {
        for (int c = col - 2; c >= 0; c--) {
            if (mat[r][c] == 1) {
                mat[r][c] += mat[r][c + 1];
            }
        }
    }

    // store total count of valid submatrices with 1
    int count = 0;

    // step 2 - iterate through every possible top-left corner position
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            // step 3 - tracks the minimum width in `minWidth` as we go down rows
            // initially, it's the consecutive 1s available in the starting row
            int minWidth = mat[r][c];

            // step 4 - extend rectangle downward from current top-left (r,c)
            for (int d = r; d < row; d++) {
                // if current row has no 1s starting from column c, stop
                if (mat[d][c] == 0) {
                    break;
                }

                // step 5 - update minimum width
                minWidth = min(minWidth, mat[d][c]);

                // step 6 - add rectanges such that minWidth represents number of different
                // widths possible
                // for a rectangle from row r to d, we can have widths 1, 2, ..., minWidth
                count += minWidth;
            }
        }
    }

    // step 7 - return total count of valid submatrices with 1
    return count;
}

int main(){
    // vector<vector<int>> mat = {{1,0,1},{1,1,0},{1,1,0}};

    vector<vector<int>> mat = {{0,1,1,0},{0,1,1,1},{1,1,1,0}};
    cout<<numSubmat(mat);
    return 0;
}