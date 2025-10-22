
// Problem link - https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/?envType=daily-question&envId=2025-10-22

#include<bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& nums, int k, int numOperations) {
    // step 1 - find the maximum possible value after operations
    int maxSize = *max_element(begin(nums), end(nums)) + k;

    // using difference map for efficient range updates
    // diff[i] will store +1 at range start and -1 at range end + 1
    map<int, int> diff;
    
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

        diff[nums[i]] += 0;
    }

    // step 3 - try each possible target value 
    int res = 0, cumSum = 0;
    for(auto it=diff.begin(); it != diff.end(); it++){
        int target = it->first;
        it->second += cumSum;

        // get count of elements already at target (no operation needed)
        int targetFreq = freq[target];

        // calculate how many other elements can reach this target
        // diff[target] includes all elements (both at target and can reach target)
        // so we subtract elements already at target to get those needing operations
        int reqOperations = it->second - targetFreq;

        // calculate achievable frequency for this target
        int maxFreq = min(reqOperations, numOperations);

        // total frequency = elements already at target + modified elements
        res = max(res, targetFreq + maxFreq);

        cumSum += it->second;
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