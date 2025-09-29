
// Problem link - https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/?envType=daily-question&envId=2025-09-29

#include<bits/stdc++.h>
using namespace std;

// global dp for precomputed values
int dp[51][51];

// recursive helper function
int minScoreTriangulationHelper(vector<int>& values, int i, int j){
    // step 1 - base case : for triangle we need atleast 3 points
    if(j - i + 1 < 3){
        return 0;
    }

    // if answer is already calculated then return its value
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // store final result in `res`
    int res = INT_MAX;

    // step 2 - calculate weight for each triangle in `weight`
    for(int k=i+1; k<j; k++){
        // step 3 - recursively solve triangulation
        int weight = values[i] * values[j] * values[k] + minScoreTriangulationHelper(values, i, k) + minScoreTriangulationHelper(values, k, j);

        // step 4 - update minimum result
        res = min(res, weight);
    }

    // step 5 - return final result `res`
    return dp[i][j] = res;
}

int minScoreTriangulation(vector<int>& values) {
    // initialize dp array to -1
    memset(dp, -1, sizeof(dp));

    // find size of values
    int n = values.size();

    // solve recursively and return the value
    return minScoreTriangulationHelper(values, 0, n-1);
}

int main(){
    // vector<int> values = {1,2,3};

    // vector<int> values = {3,7,4,5};

    vector<int> values = {1,3,1,4,1,5};
    cout<<minScoreTriangulation(values);
    return 0;
}

