
// Problem link - https://leetcode.com/problems/longest-balanced-subarray-i/description/?envType=daily-question&envId=2026-02-10

#include<bits/stdc++.h>
using namespace std;

int longestBalanced(vector<int>& nums) {
    // find size of `nums`
    int n = nums.size();

    // keep track of longest balanced subarray
    int maxLen = 0;

    // step 1 - iterate on each num of `nums`
    for(int i=0; i<n; i++){
        unordered_set<int> oddNums, evenNums;
        // step 2 - iterate on each subarray
        for(int j=i; j<n; j++){
            // step 3 - store even and odd numbers
            if(nums[j] % 2 == 0){
                evenNums.insert(nums[j]);
            }else{
                oddNums.insert(nums[j]);
            }

            // step 4 - check if the size size of odd and even numbers are same
            if(evenNums.size() == oddNums.size()){
                // then find maximum balanced subarray length
                maxLen = max(maxLen, j-i+1);
            }
        }
    }

    // step 5 - return longest balanced subarray length
    return maxLen;
}

int main(){
    vector<int> nums = {2,5,4,3};

    // vector<int> nums = {3,2,2,5,4};

    // vector<int> nums = {1,2,3,2};
    cout<<longestBalanced(nums);
    return 0;
}