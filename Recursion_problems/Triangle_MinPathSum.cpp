
// Problem link - https://leetcode.com/problems/triangle/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix;

int findMinPathSumRec(int row, int col){
    // Base case: if row is last row then return current element
    if(row == matrix.size()-1) return matrix[row][col];

    // Recursive Case : recursively calculate the minimum path sum
    return matrix[row][col] + min(findMinPathSumRec(row+1, col), findMinPathSumRec(row+1, col+1));
}

int minimumTotal(vector<vector<int>>& triangle) {
    matrix = triangle;
    return findMinPathSumRec(0,0);
}

int main(){
    vector<vector<int>> triangle = {{2},{3, 4}, {6, 5, 7},{4, 1, 8, 3}};
    cout<<minimumTotal(triangle)<<endl;
    return 0;
}