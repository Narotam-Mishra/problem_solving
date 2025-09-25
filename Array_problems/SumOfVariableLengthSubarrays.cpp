
// Problem link - https://leetcode.com/problems/sum-of-variable-length-subarrays/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums) {
    // find size of input array `nums`
    int n = nums.size();

    // store final subarray sum in `sum`
    int sum = 0;

    // step 1 - iterate on `nums` for each index `i`
    for (int i = 0; i < n; i++) {
        // step 2 - calculate start index as per problem
        int start = max(0, i - nums[i]);

        // step 3 - add up all elements from nums[start] to nums[i]
        for (int j = start; j <= i; j++) {
            sum += nums[j];
        }
    }

    // step 4 - return final subarray sum
    return sum;
}

int main(){
    // vector<int> nums = {2,3,1};

    vector<int> nums = {3,1,1,2};
    cout<<subarraySum(nums);
    return 0;
}