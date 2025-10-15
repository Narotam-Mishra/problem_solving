
// Problem link - https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/?envType=daily-question&envId=2025-10-14

#include<bits/stdc++.h>
using namespace std;

bool hasIncreasingSubarrays1(vector<int>& nums, int k) {
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

// utility function to check if array is strictly increasing
bool isIncreasing(vector<int>& nums, int s, int e){
    for(int i=s+1; i<e; i++){
       if(nums[i] <= nums[i-1]){
        return false;
       }
    }
    return true;
}

bool hasIncreasingSubarrays2(vector<int>& nums, int k) {
    // find size of `nums` array
    int n = nums.size();

    // step 1 - iterate on each number of `nums`
    for(int s=0; s+2*k<=n; s++){
        // step 2 - check is the first subarray is strictly incresing or not       
        bool isFirstSubarrayIncreasing = isIncreasing(nums, s, s+k);

        // step 2 - check is the second subarray is strictly incresing or not
        bool isSecondSubarrayIncresing = isIncreasing(nums, s+k, s+2*k);

        // step 3 - check if both conditions satisfy
        if(isFirstSubarrayIncreasing && isSecondSubarrayIncresing){
            // step 4 - return true immediately if both conditions satisfy
            return true;
        }
    }

    // otherwise return false
    return false;
}

bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    // find size of `nums` array
    int n = nums.size();

    // currRun: length of current strictly increasing sequence
    // prevRun: length of previous strictly increasing sequence
    int currRun = 1, prevRun = 0;

    // step 1 - iterate on each number of `nums` 
    for(int i=1; i<n; i++){
        // step 2 - check if current number is greater than previous number
        if(nums[i] > nums[i-1]){
            // extend current increasing run
            currRun++;
        }
        else{
            // step 3 - current run breaks, save it as previous and reset current
            prevRun = currRun;
            currRun = 1;
        }

        // step 4 - case 1 : two adjacent subarrays of length k within the current run
        // so, we can split currRun into two equal or nearly equal parts
        // hence we can return true
        if(currRun/2 >= k){
            return true;
        }

        // step 5 - case 2 : one subarray at end of previous run, one at start of current run
        // check if minimum of current run(currRun) and previous run(prevRun) is >= `k`
        // so, we can return true in this case as well
        if(min(currRun, prevRun) >= k){
            return true;
        }
    }

    // otherwise return false
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