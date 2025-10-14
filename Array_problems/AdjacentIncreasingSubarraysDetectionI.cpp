
// Problem link - https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/?envType=daily-question&envId=2025-10-14

#include<bits/stdc++.h>
using namespace std;

bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    // find size of `nums`
    int n = nums.size();

    // step 1 - check for edge case : if array is too small to contain two subarrays of length `k`
    if (n < 2 * k) return false;

    // step 2 - create an array to store which positions have strictly increasing subarrays
    vector<bool> increasing(n - k + 1, false);

    // step 3 - build incresing array
    for (int i = 0; i < n - k + 1; i++) {
        bool isIncreasing = true;

        // check if subarray starting at `i` is strictly increasing
        for (int j = i; j < i + k - 1; j++) {
            if (nums[j] >= nums[j + 1]) {
                isIncreasing = false;
                // early exit if there is non-increasing pair
                break;
            }
        }

        increasing[i] = isIncreasing;
    }

    // step 4 - check for two adjacent subarray with no overlap
    for (int i = 0; i <= n - 2 * k; i++) {
        if (increasing[i] && increasing[i + k]) {
            // step 5 - return true immediately if such pair exist
            return true;
        }
    }

    // otherwise no such pair exist, return false
    return false;
}

int main(){
    // vector<int> nums = {2,5,7,8,9,2,3,4,3,1};
    // int k = 3;

    // vector<int> nums = {1,2,3,4,4,4,4,5,6,7};
    // int k = 5;

    vector<int> nums = {5,8,-2,-1};
    int k = 2;
    bool res = hasIncreasingSubarrays(nums, k);
    res ? cout<<"true" : cout<<"false";
    return 0;
}