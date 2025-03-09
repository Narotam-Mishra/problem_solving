
// Problem link - https://leetcode.com/problems/search-a-2d-matrix-ii/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // step 1 - initialize starting position at the top-right corner
    int row = 0;
    int col = matrix[0].size() - 1;

    // step 2 - traverse the matrix
    while (row < matrix.size() && col >= 0) {
        // step 3 -  get current element
        int current = matrix[row][col];

        // step 4 - check if current element is target
        if (current == target) {
            return true;
        }
        // step 5 - if current element is greater than target than, move left
        else if (current > target) {
            col--;
        }
        // step 6 - if current element is smaller than target, move down
        else {
            row++;
        }
    }

    // step 7 - return false if target not found
    return false;
}

int main(){
    // vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    // int target = 5;

    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 20;
    bool res = searchMatrix(matrix, target);
    res ? cout<<"true" : cout<<"false";
    return 0;
}