
// Problem link - https://leetcode.com/problems/reshape-the-matrix/description/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    // find row and column size of input matrix `mat`
    int m = mat.size();
    int n = mat[0].size();

    // step 1 - check for edge case : if total element differ then reshap is not possible
    if (m * n != r * c) {
        return mat;
    }

    // store final result in `reshaped` matrix
    vector<vector<int>> reshaped(r, vector<int>(c));

    // step 2 - fill the new `reshaped` matrix 
    // single linear pass over all elements (row-major order)
    for (int k = 0; k < m * n; k++) {
        // step 3 - calculate original position in matrix `mat`
        int originalRow = k / n;
        int originalColumn = k % n;

        // step 4 - find new position in reshaped matrix
        int newRow = k / c;
        int newColumn = k % c;

        // move the element
        reshaped[newRow][newColumn] = mat[originalRow][originalColumn];
    }

    // step 5 - return reshaped matrix `reshaped`
    return reshaped;
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
    // vector<vector<int>> mat = {{1,2},{3,4}};
    // int r = 1, c = 4;

    vector<vector<int>> mat = {{1,2},{3,4}};
    int r = 2, c = 4;
    vector<vector<int>> res = matrixReshape(mat, r, c);
    print2DVector(res);
    return 0;
}