
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    // step 1: create sets from the input arrays
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    // step 2: find elements unique to nums1
    vector<int> uniqueToNums1;
    for (int num : set1) {
        if (set2.find(num) == set2.end()) {
            uniqueToNums1.push_back(num);
        }
    }

    // step 3: find elements unique to nums2
    vector<int> uniqueToNums2;
    for (int num : set2) {
        if (set1.find(num) == set1.end()) {
            uniqueToNums2.push_back(num);
        }
    }

    // step 4: return the result as a vector of two vectors
    return {uniqueToNums1, uniqueToNums2};
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
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    vector<vector<int>> res = findDifference(nums1, nums2);
    print2DVector(res);
    return 0;
}