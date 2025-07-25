
// Problem link - https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& nums, int k) {
    // store count of required pairs in `count`
    int count = 0;

    // step 1 - iterate on each pairs of nums array
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // step 2 - check if nums[i] == nums[j] and (i * j) is divisible by k
            if (nums[i] == nums[j] && (i * j) % k == 0) {
                // increment count
                count++;
            }
        }
    }

    // step 3 - return the number of such pairs
    return count;
}

int main(){
    // vector<int> nums = {3,1,2,2,2,1,3};
    // int k = 2;

    vector<int> nums = {1,2,3,4};
    int k = 1;
    cout<<countPairs(nums, k)<<endl;
    return 0;
}