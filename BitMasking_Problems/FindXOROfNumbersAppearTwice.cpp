
// Problem link - https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/description/?envType=problem-list-v2&envId=bit-manipulation\

#include<bits/stdc++.h>
using namespace std;

int duplicateNumbersXOR(vector<int>& nums) {
    // sort the array in non-decreasing order
    sort(nums.begin(), nums.end());

    // initialize the XOR result as 0
    int xorRes = 0;

    // traverse through the sorted array and check for duplicates
    for (int i = 1; i < nums.size(); i++) {
        // if the current number is the same as the previous one, XOR it with the result
        if (nums[i] == nums[i - 1]) {
            xorRes ^= nums[i];
            // skip the next element as it's already considered a duplicate
            i++;
        }
    }
    return xorRes;
}

int main(){
    vector<int> nums = {1, 2, 1, 3};
    cout<<duplicateNumbersXOR(nums);
    return 0;
}