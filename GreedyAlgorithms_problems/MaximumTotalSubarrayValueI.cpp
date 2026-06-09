
// Problem link - https://leetcode.com/problems/maximum-total-subarray-value-i/?envType=daily-question&envId=2026-06-09

#include<bits/stdc++.h>
using namespace std;

long long maxTotalValue(vector<int>& nums, int k) {
    // step 1 - find global maximum in `nums`
    int globalMax = *max_element(nums.begin(), nums.end());

    // step 2 - find global minimum in `nums`
    int globalMin = *min_element(nums.begin(), nums.end());

    // step 3 - find best possible value for single subarray
    // that will be (globalMax - globalMin)
    long long bestValue = (long long)(globalMax - globalMin);

    // step 4 - since we can pick the same subarray k times,
    // the optimal strategy is always to repeat the best subarray
    return bestValue * k;
}

int main(){
    // vector<int> nums = {1,3,2};
    // int k = 2;

    vector<int> nums = {4,2,5,1};
    int k = 3;
    cout<<maxTotalValue(nums, k);
    return 0;
}