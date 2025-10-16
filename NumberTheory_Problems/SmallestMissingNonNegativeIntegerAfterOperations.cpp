
// Problem link - https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/?envType=daily-question&envId=2025-10-16

#include<bits/stdc++.h>
using namespace std;

int findSmallestInteger(vector<int>& nums, int value) {
    // map to store frequency of each remainder when divided by 'value'
    // as adding/subtracting 'value' doesn't change the remainder
    unordered_map<int, int> modMap;

    // step 1 - count frequency of each remainder
    for(int &num : nums){
        // handle negative numbers properly
        // formula: ((num % value) + value) % value ensures positive remainder
        int rem = ((num % value) + value) % value;
        modMap[rem]++;
    }

    // step 2 - find the maximum MEX by greedily assigning smallest values
    int mex = 0;
    
    // try to form consecutive integers starting from 0
    // for each number `mex`, check if we have an element with remainder (mex % value)
    while(modMap[(mex % value)] > 0){
        // use one element with this remainder to form 'mex'
        modMap[(mex % value)]--;
        mex++;
    }

    // step 3 - return the first integer we couldn't form (the MEX)
    return mex;
}

int main(){
    // vector<int> nums = {1,-10,7,13,6,8};
    // int value = 5;

    vector<int> nums = {1,-10,7,13,6,8};
    int value = 7;
    cout<<findSmallestInteger(nums, value);
    return 0;
}