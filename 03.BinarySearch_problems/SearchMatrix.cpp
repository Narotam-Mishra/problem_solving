
// Problem link - https://leetcode.com/problems/search-a-2d-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int s = 0, e = m*n - 1;

        while(s <= e){
            int mid = s + (e - s)/2;
            int rowIdx = (int)mid/n, colIdx = mid%n;
            if(target == matrix[rowIdx][colIdx]){
                return true;
            }else if(target > matrix[rowIdx][colIdx]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return false;
    }
};