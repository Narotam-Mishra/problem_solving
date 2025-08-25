
// Problem link - https://leetcode.com/problems/diagonal-traverse/?envType=daily-question&envId=2025-08-25

#include<bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    // find row and column size
    int m = mat.size();
    int n = mat[0].size();

    // store final diagonal elements in result `res`
    vector<int> res(m * n, 0);
    int index = 0;

    // step 1 - traverse each digonal of matrix `mat`
    for(int ds=0; ds<m+n-1; ds++){
        vector<int> currentDiagonal;

        // step 2 - find all element in current diagonal where `i + j = diagonal sum (ds)`
        for(int i=0; i<m; i++){
            int j = ds - i;

            // step 3 - check calculated column index is valid or not
            if(j<n && j>=0){
                currentDiagonal.push_back(mat[i][j]);
            }
        }

        // step 4 - alternate the direction of traversal for each diagonal
        // odd diagonals (1, 3, 5...): traverse top-right to bottom-left
        // even diagonals (2, 4, 6...): traverse bottom-left to top-right
        if(ds % 2 == 0){
            reverse(currentDiagonal.begin(), currentDiagonal.end());
        }

        // step 5 - add diagonal elements to result `res`
        for(int num : currentDiagonal){
            res[index++] = num;
        }
    }

    // step 6 - return result `res`
    return res;
}

void printVector(vector<int>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    // vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};

    vector<vector<int>> mat = {{1,2},{3,4}};
    vector<int> res = findDiagonalOrder(mat);
    printVector(res);
    return 0;
}