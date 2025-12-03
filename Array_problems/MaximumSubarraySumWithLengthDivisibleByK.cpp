
// Problem link - https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/?envType=daily-question&envId=2025-11-27

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll maxSubarraySum1(vector<int>& nums, int k) {
    int n = nums.size();
    const ll INF = LLONG_MAX;

    // find minimum prefix sum for each remainder class
    vector<ll> minPref(k, INF);
    
    // track running prefix sum
    ll prefSum = 0;
    ll res = LLONG_MIN;

    // prefix sum at index 0 is o
    minPref[0] = 0;

    // step 1 - iterate from 1 to n position to compute prefix sum
    for(int j=1; j<=n; j++){
        // find running prefix sum
        prefSum += nums[j-1];
        int rem = j % k;

        // step 2 - check if we've seen a position with same remainder before
        if(minPref[rem] != INF){
            // subarray sum = current_prefix - smallest_previous_prefix_with_same_remainder
            res = max(res, prefSum - minPref[rem]);
        }

        // step 3 - update smallest prefix seen so far 
        minPref[rem] = min(minPref[rem], prefSum);
    }

    // step 4 - return final result, res
    return res;
}

ll maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    const ll INF = LLONG_MAX;

    // find minimum prefix sum for each remainder class
    vector<ll> minPref(k, INF);

    // track running prefix sum
    ll prefSum = 0;
    ll res = LLONG_MIN;

    // prefix sum at index 0 is o
    minPref[0] = 0;

    // step 1 - iterate from 1 to n position to compute prefix sum
    for (int j = 1; j <= n; j++) {
        // find running prefix sum
        prefSum += nums[j - 1];
        int rem = j % k;

        // step 2 - check if we've seen a position with same remainder
        // before
        if (minPref[rem] != INF) {
            // subarray sum = current_prefix -
            // smallest_previous_prefix_with_same_remainder
            res = max(res, prefSum - minPref[rem]);
        }

        // step 3 - update smallest prefix seen so far
        minPref[rem] = min(minPref[rem], prefSum);
    }

    // step 4 - return final result, res
    return res;
}

int main(){
    // vector<int> nums = {1,2};
    // int k = 1;

    // vector<int> nums = {-5,1,2,-3,4};
    // int k = 2;

    vector<int> nums = {-1,-2,-3,-4,-5};
    int k = 4;
    cout<<maxSubarraySum(nums, k);
    return 0;
}