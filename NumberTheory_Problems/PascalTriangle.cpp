
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; i++) {
        vector<int> row;
        row.push_back(1);
        for (int j = 1; j <= i; j++) {
            row.push_back(row[j - 1] * (i - j + 1) / j);
        }
        res.push_back(row);
    }
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
    // int numRows = 5;

    int numRows = 1;
    vector<vector<int>> res = generate(numRows);
    print2DVector(res);
    return 0;
}