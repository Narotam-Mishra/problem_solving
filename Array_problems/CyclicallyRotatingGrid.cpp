
// Problem link - https://leetcode.com/problems/cyclically-rotating-a-grid/description/?envType=daily-question&envId=2026-05-09

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    // find number of rows and colums
    int m = grid.size();
    int n = grid[0].size();

    // step 1 - find number of layers to traverse
    int layers = min(m/2,n/2);

    // step 2 - traverse each layer
    for(int l=0; l<layers; l++){
        // keep track of layer elements
        vector<int> nums;

        // step 3 - find top-bottom and left-right layer number
        int top = l;
        int bottom = m - l - 1;
        int left = l;
        int right = n - l - 1;

        // top row traversal (left to right)
        for(int j=left; j<=right; j++){
            nums.push_back(grid[top][j]);
        }

        // top right column traversal (top+1 to bottom-1)
        for(int i=top+1; i<=bottom-1; i++){
            nums.push_back(grid[i][right]);
        }

        // bottom row traversal (right to left)
        for(int j=right; j>=left; j--){
            nums.push_back(grid[bottom][j]);
        }

        // bottom left column (bottom to top)
        for(int i=bottom-1; i>=top+1; i--){
            nums.push_back(grid[i][left]);
        }

        // step 4 - rotate nums k-times
        // normalize k
        int len = nums.size();
        int normalizedK = k % len;

        rotate(begin(nums), begin(nums) + normalizedK, end(nums));

        // step 5 - after rotation copy back numbers to grid
        int idx = 0;

        // fill top row (left to right)
        for(int j=left; j<=right; j++){
            grid[top][j] = nums[idx++];
        }

        // fill top right column (top+1 to bottom-1)
        for(int i=top+1; i<=bottom-1; i++){
            grid[i][right] = nums[idx++];
        }
        
        // fill bottom row (right to left)
        for(int j=right; j>=left; j--){
            grid[bottom][j] = nums[idx++];
        }

        // fill bottom left column (bottom to top)
        for(int i=bottom-1; i>=top+1; i--){
            grid[i][left] = nums[idx++];
        }
    }

    // step 6 - return final rotated grid
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
    // vector<vector<int>> grid = {{40,10},{30,20}};
    // int k = 1;

    vector<vector<int>> grid = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int k = 2;
    vector<vector<int>> res = rotateGrid(grid, k);
    print2DVector(res);
    return 0;
}