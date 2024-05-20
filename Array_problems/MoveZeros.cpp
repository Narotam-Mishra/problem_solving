
// Problem link - https://leetcode.com/problems/move-zeroes/description/


#include <bits/stdc++.h>
using namespace std;

// Approach - 1 (swap no-zero numbers)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                // swap
                int temp = nums[i];
                nums[i] = nums[k];
                nums[k] = temp;
                k++;
            }
        }
    }
};