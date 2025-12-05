
// Problem link - https://leetcode.com/problems/count-partitions-with-even-sum-difference/?envType=daily-question&envId=2025-12-05

#include<bits/stdc++.h>
using namespace std;

int countPartitions(vector<int>& nums) {
    int n = nums.size();

    // step 1 - find prefix sum of `nums`
    vector<int> prefixSum(n, 0);
    prefixSum[0] = nums[0];
    for(int i=1; i<n; i++){
        prefixSum[i] = prefixSum[i-1] + nums[i];
    }

    // step 2 - count partition
    int c = 0;
    int total = prefixSum[n-1];
    for(int i=0; i<n-1; i++){
        // find left sum
        int leftSum = prefixSum[i];

        // find right sum
        int rightSum = total - leftSum;

        // calculate difference, `diff`
        int diff = leftSum - rightSum;

        // check if diff is even or not
        if((diff & 1) == 0){
            // count partitions
            c++;
        }
    }

    // step 3 - return count valid partitions, `c`
    return c;
}

int main(){
    // vector<int> nums = {10,10,3,7,6};

    // vector<int> nums = {1,2,2};

    vector<int> nums = {2,4,6,8};
    cout<<countPartitions(nums);
    return 0;
}