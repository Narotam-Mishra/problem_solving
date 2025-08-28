
// Problem link - https://leetcode.com/problems/sort-matrix-by-diagonals/?envType=daily-question&envId=2025-08-28

#include<bits/stdc++.h>
using namespace std;

void processDiagonals(int si, int sj, vector<vector<int>>& grid) {
    int n = grid.size();
    int i = si, j = sj;

    // collect values along current diagonal
    vector<int> vals;
    while (i < n && j < n) {
        vals.push_back(grid[i][j]);
        i++; j++;
    }

    // decice sorting order based on diagonal key diff = si - sj
    int diff = si - sj;
    if (diff >= 0) {
        // bottom-left & main diagonal --> descending order sorting
        sort(vals.begin(), vals.end(), greater<int>());
    }
    else {
        // top right --> ascending order sorting
        sort(vals.begin(), vals.end());
    }

    // write sorted values back along diagonal
    i = si; j = sj;

    int index = 0;
    while (i < n && j < n) {
        grid[i][j] = vals[index++];
        i++;
        j++;
    }
}

vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    // find size of grid
    int n = grid.size();

    // step 1 - first, diagonals starting from top row (0, col)
    for (int c = 0; c < n; c++) {
        // step 2 - process digonal along top right
        processDiagonals(0, c, grid);
    }

    // step 3 - then, diagonals starting from first column (row, 0),
    // skipping row 0 to avoid duplicate main diagonal
    for (int r = 1; r < n; r++) {
        // step 4 - process digonal along bottom-left
        processDiagonals(r, 0, grid);
    }

    // step 5 - return final diagonal sorted grid
    return grid;
}

void print2DVector(vector<vector<int>>& matrix){
    cout << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < matrix.size() - 1) cout << ",";
    }
    cout << "]" << std::endl;
}

int main(){
    // vector<vector<int>> grid = {{1,7,3},{9,8,2},{4,5,6}};

    // vector<vector<int>> grid = {{0,1},{1,2}};

    vector<vector<int>> grid = {{1}};
    vector<vector<int>> res = sortMatrix(grid);
    print2DVector(res);
    return 0;
}