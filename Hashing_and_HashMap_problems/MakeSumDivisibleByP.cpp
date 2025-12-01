
// Problem link - https://leetcode.com/problems/make-sum-divisible-by-p/?envType=daily-question&envId=2025-11-30

#include<bits/stdc++.h>
using namespace std;

int minSubarray(vector<int>& nums, int p) {
    // step 1 - find sum of array's element
    int sum = 0;
    for(int num : nums){
        sum = (sum + num) % p;;
    }

    int target = sum % p;

    // check if sum is alredy divisible by `p`
    if(target == 0){
        return 0;
    }

    // step 2 - store previous sum 
    unordered_map<int, int> mp;
    int curr = 0;
    mp[0] = -1;

    int n = nums.size();

    // step 3 - find remain value in map
    int res = n;
    for(int j=0; j<n; j++){
        curr = (curr + nums[j]) % p;
        int remainVal = (curr - target + p) % p;

        if(mp.find(remainVal) != mp.end()){
            res = min(res, j - mp[remainVal]);
        }

        mp[curr] = j;
    }

    // step 4 - return final answer
    return res == n ? -1 : res;
}

int main(){
    // vector<int> nums = {3,1,4,2};
    // int p = 6;

    // vector<int> nums = {6,3,5,2};
    // int p = 9;

    vector<int> nums = {1,2,3};
    int p = 3;
    cout<<minSubarray(nums, p);
    return 0;
}