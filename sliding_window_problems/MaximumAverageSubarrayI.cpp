
// Problem link - https://leetcode.com/problems/maximum-average-subarray-i/description/?envType=problem-list-v2&envId=sliding-window

#include<bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    // edge case: if array length is less than k
    int n = nums.size();
    if (n < k) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return (double)sum / n;
    }

    // step 1 - calculate sum of first k-elements of array
    int currSum = 0;
    for (int i = 0; i < k; i++) {
        currSum += nums[i];
    }

    // step 2 - initialize maximum sum `maxSum`
    int maxSum = currSum;

    // step 3 - slide the window through rest of array
    // start from index k and go till end
    for (int i = k; i < n; i++) {
        currSum = currSum - nums[i - k] + nums[i];

        // step 4 - update maximum sum if current sum is larger
        maxSum = max(maxSum, currSum);
    }

    // step 5 - return maximum average (sum divided by k)
    return (double)maxSum / k;
}

int main(){
    // vector<int> nums = {1,12,-5,-6,50,3};
    // int k = 4;

    vector<int> nums = {5};
    int k = 1;
    cout<<findMaxAverage(nums, k)<<endl;
    return 0;
}