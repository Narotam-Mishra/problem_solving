
// Problem link - https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums, int k) {
    // step 1 - calculate total sum of `nums` array
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    // step 2 - find remainder when divided by `k`
    int remainder = totalSum % k;

    // step 3 - if already divisble, return 0
    if (remainder == 0)
        return 0;

    // we need exactly 'remainder' operations to make sum divisible by k
    // we just need to reduce the total sum by 'remainder'
    // step 4 - hence return `remainder`
    return remainder;
}

int main(){
    // vector<int> nums = {3,9,7};
    // int k = 5;

    // vector<int> nums = {4,1,3};
    // int k = 4;

    vector<int> nums = {3,2};
    int k = 6;
    cout<<minOperations(nums, k);
    return 0;
}