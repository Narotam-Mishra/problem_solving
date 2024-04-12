
//Problem link -  https://leetcode.com/problems/maximum-subarray/

// Using kadane's Algorithm

#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int curSum = nums[0];
    int maxSum = nums[0];

    for(int i = 1; i < nums.size(); i++){

        // find maximum current sum
        curSum = max(nums[i], curSum + nums[i]);

        // update maximum sum
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;
    return 0;
}