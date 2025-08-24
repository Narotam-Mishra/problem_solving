
// Problem link - https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/?envType=daily-question&envId=2025-08-24

#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums) {
    // using sliding window appraoch
    int n = nums.size();

    // left pointer of window
    int left = 0;

    // store count zeros in current window
    int zeroCount = 0;

    // store maximum length `maxLen` found so far
    int maxLen = 0;

    // step 1 - expand the window from left to right
    for (int right = 0; right < n; right++) {
        // step 2 - count zeros in current window
        if (nums[right] == 0) {
            zeroCount++;
        }

        // step 3 - if we have more than 1 zero than shrink the window from left
        while (zeroCount > 1) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }

        // step 4 - update maximum length `maxLen` founs so far
        // subtract 1 because we must delete exactly one element
        maxLen = max(maxLen, right - left + 1 - 1);
    }

    // step 5 - return maximum length of non-empty subarray containing only 1
    return maxLen;
}

int main(){
    // vector<int> nums = {1,1,0,1};

    // vector<int> nums = {0,1,1,1,0,1,1,0,1};

    vector<int> nums = {1,1,1};
    cout<<longestSubarray(nums);
    return 0;
}

