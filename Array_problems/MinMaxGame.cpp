
// Problem link - https://leetcode.com/problems/min-max-game/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int minMaxGame(vector<int>& nums) {
    // store current length of `nums` array
    int currLen = nums.size();

    // step 1 - repeat the process until `nums` array length greater than 1
    while (currLen > 1) {
        // step 2 - since length is always power of 2, division is exact
        int newLen = currLen / 2;

        // step 3 - process each pair and build new array as per given condition
        for (int i = 0; i < newLen; i++) {
            // first element of pair
            int leftNum = nums[2 * i];

            // second element of pair
            int rightNum = nums[2 * i + 1];

            // step 4 - apply min-max rule based on index
            if (i % 2 == 0) {
                nums[i] = min(leftNum, rightNum);
            }
            else {
                nums[i] = max(leftNum, rightNum);
            }
        }

        // step 5 - shrink array by its new length `newLen`
        currLen = newLen;
    }

    // step 6 - return last number
    return nums[0];
}

int main(){
    // vector<int> nums = {1,3,5,2,4,8,2,2};

    vector<int> nums = {3};
    cout<<minMaxGame(nums);
    return 0;
}