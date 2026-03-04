
// Problem link - https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2026-03-04

#include<bits/stdc++.h>
using namespace std;

int numSpecial(vector<vector<int>>& mat) {
    // find row and column size
    int m = mat.size();
    int n = mat[0].size();

    // keep track row and column ones
    vector<int> rowOne(m, 0);
    vector<int> colOne(n, 0);

    // step 1 - iterate on matrix & count 1s
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 1){
                rowOne[i]++;
                colOne[j]++;
            }
        }
    }

    // step 2 - find special posiiton
    int specialCount = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 1 && rowOne[i] == 1 && colOne[j] == 1){
                specialCount++;
            }
        }
    }

    // step 3 - return special count
    return specialCount;
}

int main(){
    // vector<vector<int>> mat = {{1,0,0},{0,0,1},{1,0,0}};

    vector<vector<int>> mat = {{1,0,0},{0,1,0},{0,0,1}};
    cout<<numSpecial(mat);
    return 0;
}