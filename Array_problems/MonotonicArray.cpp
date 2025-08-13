
// Problem link - https://leetcode.com/problems/monotonic-array/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

bool isMonotonic(vector<int>& nums) {
    // base case: arrays with 1 element is always monotonic
    if (nums.size() == 1)
        return true;

    // step 1 - track if we have seen increasing and decreasing trend in `nums` array
    bool hasIncreasing = false;
    bool hasDecresing = false;

    // step 2 - iterate on `nums` array
    for (int i = 0; i < nums.size() - 1; i++) {
        // step 3 - compare current element with next element
        if (nums[i] < nums[i + 1]) {
            hasIncreasing = true;
        }
        else if (nums[i] > nums[i + 1]) {
            hasDecresing = true;
        }

        // step 4 - early termination : if both trends exist, array is not monotonic
        if (hasIncreasing && hasDecresing) {
            return false;
        }
    }

    // step 5 - array is monotonic if we haven't seen both increasing and
    // decreasing, so return true
    return true;
}

int main(){
    // vector<int> nums = {1,2,2,3};

    // vector<int> nums = {6,5,4,4};

    vector<int> nums = {1,3,2};
    bool res = isMonotonic(nums);
    res ? cout<<"true" : cout<<"false";
    return 0;
}