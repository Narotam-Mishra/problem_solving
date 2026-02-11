
// Problem link - https://leetcode.com/problems/longest-balanced-subarray-ii/?envType=daily-question&envId=2026-02-11

#include<bits/stdc++.h>
using namespace std;

int longestBalanced1(vector<int>& nums) {
    int n = nums.size();

    // treating even=1 and odd=-1
    vector<int> cumSum(n, 0);

    // keep track of longest balanced subarray length
    int maxLen = 0;

    // step 1 - iterate on each number from left to right
    unordered_map<int, int> mp;
    for(int r=0; r<n; r++){
        // step 2 - convert current number into contribution value
        // +1 for even, -1 for odd
        int val = (nums[r] % 2 == 0) ? 1 : -1;

        // step 3 - check if this number appeared before
        int prev = -1;
        if(mp.count(nums[r])){
            prev = mp[nums[r]];
        }

        // step 4 - if number appeared before,
        // remove its previous contribution from all subarrays
        if(prev != -1){
            for(int l=0; l<=prev; l++){
                cumSum[l] -= val;
            }
        }

        // step 5 - add current contribution (+1 or -1)
        // to all subarrays starting from l to r
        for(int l=0; l<=r; l++){
            cumSum[l] += val;
        }

        // step 6 - now check for any subarray [l...r]
        // whose cumulative sum becomes 0
        for(int l=0; l<=r; l++){
            if(cumSum[l] == 0){
                maxLen = max(maxLen, r-l+1);
                break;
            }
        }

        // step 7 - update last seen index of current number
        mp[nums[r]] = r;
    }

    // step 8 - return longest balanced subarray length
    return maxLen;
}

int longestBalanced(vector<int>& nums) {
        
}

int main(){
    // vector<int> nums = {2,5,4,3};

    // vector<int> nums = {3,2,2,5,4};

    vector<int> nums = {1,2,3,2};
    cout<<longestBalanced(nums);
    return 0;
}