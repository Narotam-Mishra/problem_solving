
// Problem link - https://leetcode.com/problems/increment-submatrices-by-one/description/?envType=daily-question&envId=2025-11-14

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    // using Difference Array Technique(DAT)
    vector<vector<int>> mat(n, vector<int>(n, 0));

    // step 1 - process each query
    for (auto& query : queries) {
        int row1 = query[0];
        int col1 = query[1];
        int row2 = query[2];
        int col2 = query[3];

        // step 2 - populate DAT
        for (int r = row1; r <= row2; r++) {
            mat[r][col1] += 1;

            if (col2 + 1 < n) {
                mat[r][col2 + 1] -= 1;
            }
        }
    }

    // step 3 - find cummulative sum of `mat`
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            mat[i][j] += mat[i][j - 1];
        }
    }

    // step 4 - return final result from `mat`
    return mat;
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
    // int n = 3;
    // vector<vector<int>> queries = {{1,1,2,2},{0,0,1,1}};

    int n = 2;
    vector<vector<int>> queries = {{0,0,1,1}};
    vector<vector<int>> res = rangeAddQueries(n, queries);
    print2DVector(res);
    return 0;
}