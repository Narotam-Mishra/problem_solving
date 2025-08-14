
// Problem link - https://leetcode.com/problems/transpose-matrix/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    // find row `m` and column `n` length of matrix
    int m = matrix.size();
    int n = matrix[0].size();

    // step 1 - store result in `res` matrix
    vector<vector<int>> res(n, vector<int>(m));

    // step 2 - iterate on matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // step 3 - find transpose matrix, i.e, matrix[i][j] = matrix[j][i]
            res[j][i] = matrix[i][j];
        }
    }

    // step 4 - return resultant tranposed matrix `res`
    return res;
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
    // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    vector<vector<int>> matrix = {{1,2,3},{4,5,6}};
    vector<vector<int>> res = transpose(matrix);
    print2DVector(res);
    return 0;
}