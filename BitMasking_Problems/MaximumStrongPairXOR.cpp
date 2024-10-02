
// Problem link : https://leetcode.com/problems/maximum-strong-pair-xor-i/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int maximumStrongPairXor(vector<int>& nums) {
    // intialize `maxXor` to 0 to store result
    int maxXor = 0;

    // iterate on each pairs
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            // check strong pair condition
            if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) {
                // calculate XOR and find maximum XOR value
                maxXor = max(maxXor, nums[i] ^ nums[j]);
            }
        }
    }
    // return `maxXor` value
    return maxXor;
}

int main(){
    // vector<int> nums = {1,2,3,4,5};

    // vector<int> nums = {10, 100};

    vector<int> nums = {5,6,25,30};
    cout<<maximumStrongPairXor(nums);
    return 0;
}