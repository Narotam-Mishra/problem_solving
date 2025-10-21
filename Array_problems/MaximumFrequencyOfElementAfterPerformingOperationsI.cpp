
// Problem link - https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/?envType=daily-question&envId=2025-10-21

#include<bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& nums, int k, int numOperations) {
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

int main(){
    vector<int> nums = {1,4,5};
    int k = 1, numOperations = 2;
    cout<<maxFrequency(nums, k, numOperations);
    return 0;
}