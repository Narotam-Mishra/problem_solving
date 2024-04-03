
// Problem link - https://leetcode.com/problems/triangle/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix;
vector<vector<int>> dp;

int findMinPathSumTopDownDP(int row, int col){
    // Base case: if row is last row then return current element
    if(row == matrix.size()-1) return matrix[row][col];

    // if dp[row][col] is already calculated then return dp[row][col]
    if(dp[row][col] != -1) return dp[row][col];

    // Recursive Case : recursively calculate the minimum path sum
    int ans = matrix[row][col] + min(findMinPathSumTopDownDP(row+1, col), findMinPathSumTopDownDP(row+1, col+1));
    dp[row][col] = ans;
    return ans;
}

int minimumTotal(vector<vector<int>>& triangle) {
    matrix = triangle;
    int n = matrix.size();
    dp.resize(n, vector<int>(n, -1));
    return findMinPathSumTopDownDP(0,0);
}

int main(){
    vector<vector<int>> triangle = {{2},{3, 4}, {6, 5, 7},{4, 1, 8, 3}};
    cout<<minimumTotal(triangle)<<endl;
    return 0;
}