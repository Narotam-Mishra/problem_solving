
// Problem link - https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& nums, int target) {
    // store count of pairs in `count`
    int count = 0;

    // step 1 - iterate on each pair of `nums` array
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // step 2 - check if `nums[i] + nums[j] < target`
            if (nums[i] + nums[j] < target) {
                // increment the counter
                count++;
            }
        }
    }

    // step 3 - return counter `count`
    return count;
}

int main(){
    // vector<int> nums = {-1,1,2,3,1};
    // int target = 2;

    vector<int> nums = {-6,2,5,-2,-7,-1,3};
    int target = -2;
    cout<<countPairs(nums, target);
    return 0;
}