
// Problem link - https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/?envType=problem-list-v2&envId=sliding-window

#include<bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int>& nums, int k) {
    // store minimum possible difference in `minDiff`
    int minDiff = INT_MAX;

    // step 1 - edge case : if k is 1, difference is always 0
    if (k == 1)
        return 0;

    // step 2 - sort the array so that close values are next to each other
    sort(nums.begin(), nums.end());

    // step 3 - iterate on array elements in window of size-k
    for (int i = 0; i <= nums.size() - k; i++) {
        // take the current window of size k over the sorted array
        int windowMin = nums[i];
        int windowMax = nums[i + k - 1];

        // step 4 - find difference and update minimum difference
        int diff = windowMax - windowMin;
        minDiff = min(minDiff, diff);
    }

    // step 5 - return the smallest difference found
    return minDiff;
}

int main(){
    // vector<int> nums = {90};
    // int k = 1;

    vector<int> nums = {9,4,1,7};
    int k = 2;
    cout<<minimumDifference(nums, k);
    return 0;
}