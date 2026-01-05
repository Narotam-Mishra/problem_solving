
// Problem link - https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05

#include<bits/stdc++.h>
using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // step 1 - find overall absolute sum of matrix's values
    long long totalSum = 0;
    int negativesCount = 0;
    int minAbsVal = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // step 2 - count negative numbers
            if(matrix[i][j] < 0){
                negativesCount++;
            }

            // keep track of minimum absolute value in matrix
            minAbsVal = min(minAbsVal, abs(matrix[i][j]));
            
            // calculate overall running sum of absolute values
            totalSum += abs(matrix[i][j]);
        }
    }

    // step 3 - check if count of negatives is even or not
    if(negativesCount % 2 == 0){
        // return overall sum in case of even negatives count
        return totalSum;
    }

    // step 4 - if odd negatives, we must flip one negative number to positive
    // subtract 2*minAbsVal because: once to remove it from sum, once to flip its sign
    return totalSum - 2 * minAbsVal;
}

int main(){
    // vector<vector<int>> matrix = {{1,-1},{-1,1}};

    vector<vector<int>> matrix = {{1,2,3},{-1,-2,-3},{1,2,3}};
    cout<<maxMatrixSum(matrix);
    return 0;
}