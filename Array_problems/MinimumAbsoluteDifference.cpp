
// Problem link - https://leetcode.com/problems/minimum-absolute-difference/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    int n = arr.size();

    // store minimum absolute difference in `minDiff`
    int minDiff = INT_MAX;

    // step 1 - sort the array
    sort(arr.begin(), arr.end());

    // step 2 - check all pairs for minimum absolute difference
    for (int i = 0; i < n - 1; i++) {
        // always positive since array is sorted
        int currDiff = arr[i + 1] - arr[i];
        minDiff = min(currDiff, minDiff);
    }

    // step 3 - iterate through adjacent pairs again to find all with min difference
    vector<vector<int>> res;
    for (int i = 0; i < n - 1; i++) {
        int currDiff = arr[i + 1] - arr[i];

        // step 4 - if this pair has the minimum difference, add it to result
        if (currDiff == minDiff) {
            res.push_back({ arr[i], arr[i + 1] });
        }
    }

    // step 5 - return resultant array `res`
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
    // vector<int> arr = {4,2,1,3};

    // vector<int> arr = {1,3,6,10,15};

    vector<int> arr = {3,8,-10,23,19,-4,-14,27};
    vector<vector<int>> res = minimumAbsDifference(arr);
    print2DVector(res);
    return 0;
}