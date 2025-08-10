
// Problem link - https://leetcode.com/problems/minimum-distance-to-the-target-element/description/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int getMinDistance(vector<int>& nums, int target, int start) {
    // find length of `nums` array
    int n = nums.size();

    // step 1 - iterate on `nums` array
    int minAbs = INT_MAX;
    for (int i = 0; i < n; i++) {
        // step 2 - check if target exist
        if (nums[i] == target) {
            // step 3 - find absolute value of (i - start)
            int currAbsVal = abs(i - start);

            // step 4 - update minimum absolute value
            if (currAbsVal < minAbs) {
                minAbs = currAbsVal;
            }
        }
    }

    // step 5 - return minimum absolute value
    return minAbs;
}

int main(){
    // vector<int> nums = {1,2,3,4,5};
    // int target = 5, start = 3;

    // vector<int> nums = {1};
    // int target = 1, start = 0;

    // vector<int> nums = {1,1,1,1,1,1,1,1,1,1};
    // int target = 1, start = 0;

    vector<int> nums = {1,1,1,1,1,1,1,1,1,1};
    int target = 1, start = 9;
    cout<<getMinDistance(nums, target, start);
    return 0;
}