
// Problem link - https://leetcode.com/problems/special-array-i/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

bool isArraySpecial(vector<int>& nums) {
    int n = nums.size();
    // check edge case
    if (n == 1)
        return true;

    // step 1 - iterate on each adjacent pairs
    for (int i = 1; i < n; i++) {
        // step 2 - if adjacent pair is not odd and even then return false immediately
        if (((nums[i - 1] & 1) == 1) && ((nums[i] & 1) == 1) || ((nums[i - 1] & 1) == 0) && ((nums[i] & 1) == 0)) {
            return false;
        }
    }

    // step 3 - otherwise return true
    return true;
}

int main(){
    // vector<int> nums = {1};

    // vector<int> nums = {2,1,4};

    // vector<int> nums = {4,3,1,6};

    vector<int> nums = {2,10};
    bool res = isArraySpecial(nums);
    res ? cout<<"true" : cout<<"false";
    return 0;
}