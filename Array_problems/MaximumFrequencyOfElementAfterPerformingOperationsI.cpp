
// Problem link - https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/?envType=daily-question&envId=2025-10-21

#include<bits/stdc++.h>
using namespace std;

int maxFrequency1(vector<int>& nums, int k, int numOperations) {
    // step 1 - find the maximum possible value after operations
    int maxSize = *max_element(begin(nums), end(nums)) + k;

    // step 2 - create frequency array to store count of each value
    vector<int> freq(maxSize + 1, 0);
    for(int &num : nums){
        freq[num]++;
    }

    // step 3 - convert frequency array to prefix sum array
    // this allows O(1) range queries: count in [L, R] = freq[R] - freq[L-1]
    for(int i=1; i<=maxSize; i++){
        freq[i] += freq[i-1];
    }

    // step 4 - try every possible target value from 0 to maxSize
    int res = 0;
    for(int target=0; target<=maxSize; target++){
        if(freq[target] == 0) continue;

        // step 5 - define the reachable range for this target
        int l = max(0, target - k);
        int r = min(maxSize, target + k);

        // step 6 - count total elements in the reachable range using prefix sum
        int totalCount = freq[r] - (l > 0 ? freq[l-1] : 0);

        // step 7 - count elements already at target (no operation needed)
        int targetCount = freq[target] - (target > 0 ? freq[target-1] : 0);

        // step 8 - calculate required operations
        int reqOperations = totalCount - targetCount;

        // step 9 - calculate achievable frequency
        int maxFreq = targetCount + min(reqOperations, numOperations);

        // update result `res` with maximum frequency
        res = max(res, maxFreq);
    }

    // step 10 - return final result `res`
    return res;
}

int maxFrequency(vector<int>& nums, int k, int numOperations) {
    // step 1 - find the maximum possible value after operations
    int maxSize = *max_element(begin(nums), end(nums)) + k;

    // using difference array for range updates
    // diff[i] will store +1 at range start and -1 at range end + 1
    // size is maxSize+2 to handle diff[maxSize+1] safely
    vector<int> diff(maxSize+2, 0);
    
    // frequency map to store count of each original value
    unordered_map<int, int> freq;

    // step 2 - mark reachable ranges for each element
    for(int i=0; i<nums.size(); i++){
        // count frequency
        freq[nums[i]]++;

        // calculate the range this element can reach with operations
        int l = max(nums[i] - k, 0);
        int r = min(nums[i] + k, maxSize);

        // use difference array technique for O(1) range update
        diff[l]++;
        diff[r+1]--;
    }

    // step 3 - try each possible target value 
    int res = 0;
    for(int target=0; target<=maxSize; target++){
        // convert difference array to actual counts via prefix sum
        diff[target] += (target > 0 ? diff[target-1] : 0);

        // get count of elements already at target (no operation needed)
        int targetFreq = freq[target];

        // calculate how many other elements can reach this target
        // diff[target] includes all elements (both at target and can reach target)
        // so we subtract elements already at target to get those needing operations
        int reqOperations = diff[target] - targetFreq;

        // calculate achievable frequency for this target
        int maxFreq = min(reqOperations, numOperations);

        // total frequency = elements already at target + modified elements
        res = max(res, targetFreq + maxFreq);
    }

    // step 4 - return final result `res`
    return res;
}

int main(){
    // vector<int> nums = {1,4,5};
    // int k = 1, numOperations = 2;

    vector<int> nums = {5,11,20,20};
    int k = 5, numOperations = 1;
    cout<<maxFrequency(nums, k, numOperations);
    return 0;
}