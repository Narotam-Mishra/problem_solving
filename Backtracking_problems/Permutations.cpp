
// Problem link - https://leetcode.com/problems/permutations/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& nums, int startIndex, vector<vector<int>>& res) {
    // base case: if all elemnts have been placed
    if (startIndex == nums.size()) {
        // step 1 - make a copy of current state
        res.push_back(nums);
        return;
    }

    // step 2 - try each remaining element at the current position
    for (int i = startIndex; i < nums.size(); i++) {
        // step 3 - swap current element to the position we're filling
        swap(nums[startIndex], nums[i]);

        // step 4 - recurively permute remaining elements
        backtrack(nums, startIndex + 1, res);

        // step 5 - swap back to restore original state
        swap(nums[startIndex], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    // store result in `res` array
    vector<vector<int>> res;

    // step 6 - intiate recursive call
    backtrack(nums, 0, res);

    // step 7 - return result `res`
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
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = permute(nums);
    print2DVector(res);
    return 0;
}