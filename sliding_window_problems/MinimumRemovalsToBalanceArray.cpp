
// Problem link - https://leetcode.com/problems/minimum-removals-to-balance-array/?envType=daily-question&envId=2026-02-06

#include<bits/stdc++.h>
using namespace std;

int minRemoval(vector<int>& nums, int k) {
    int n = nums.size();

    // step 1 - sort `nums` array
    sort(nums.begin(), nums.end());

    // using sliding withow with two-pointers
    int i=0, j=0;
    int maxNum = nums[0], minNum = nums[0];

    // keep track of maximum balanced subarray
    // initially there will be atleast 1 balance subarray
    int len = 1;

    // step 2 - move throught he window
    while(j < n){
        // keep track of maximum and minimum number
        minNum = nums[i];
        maxNum = nums[j];

        // step 3 - check balance subarray condition
        while(i < j && maxNum > (long long)k * minNum){
            i++;
            minNum = nums[i];
        }

        // step 4 - updated balanced subarry length
        len = max(len, j-i+1);

        // move to next window
        j++;
    }

    // step 5 - return minimum number of elements to remove
    return n - len;
}

int main(){
    // vector<int> nums = {2,1,5};
    // int k = 2;

    // vector<int> nums = {1,6,2,9};
    // int k = 3;

    vector<int> nums = {4,6};
    int k = 2;
    cout<<minRemoval(nums, k);
    return 0;
}