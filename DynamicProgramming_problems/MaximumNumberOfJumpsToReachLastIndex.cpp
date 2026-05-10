
// Problem link - https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/?envType=daily-question&envId=2026-05-10

#include<bits/stdc++.h>
using namespace std;

int n;

int solveRec(int i, vector<int>& nums, int target, vector<int>& memo){
    // base case: reached target
    if(i == n-1) return memo[i] = 0;

    // if result is precomputed then return
    if(memo[i] != INT_MIN){
        return memo[i];
    }

    // recursive case: iterate on each valid index
    int res = INT_MIN;
    for(int j=i+1; j<n; j++){
        // compute result
        if(abs(nums[i] - nums[j]) <= target){
            int temp = 1 + solveRec(j, nums, target, memo);
            res = max(res, temp);
        }
    }

    return memo[i] = res;
}

int maximumJumps(vector<int>& nums, int target) {
    n = nums.size();

    // keep track of memoized value
    vector<int> memo(n+1, INT_MIN);

    // step 1 - solve recursively and return result
    int res = solveRec(0, nums, target, memo);
    return res < 0 ? -1 : res;
}

int main(){
    // vector<int> nums = {1,3,6,4,1,2};
    // int target = 2;

    // vector<int> nums = {1,3,6,4,1,2};
    // int target = 3;

    vector<int> nums = {1,3,6,4,1,2};
    int target = 0;
    cout<<maximumJumps(nums, target);
    return 0;
}