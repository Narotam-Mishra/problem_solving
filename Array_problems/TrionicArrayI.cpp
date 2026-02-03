
// Problem link - https://leetcode.com/problems/trionic-array-i/?envType=daily-question&envId=2026-02-03

#include<bits/stdc++.h>
using namespace std;

bool isTrionic(vector<int>& nums) {
    int n = nums.size();

    // keep track of each num in nums
    int i = 0;

    // step 1 - check increasing sequence
    while(i+1 < n && nums[i] < nums[i+1]){
        i++;
    }

    // step 2 - check we reached end without finding incresing and decresing sequence
    if(i == 0 || i == n-1){
        // return false immediately
        return false;
    } 

    // step 3 - check decresing sequence
    while(i+1 < n && nums[i] > nums[i+1]){
        i++;
    }

    // step 4 - check we reached end without finding incresing and decresing sequence
    if(i == n-1){
        return false;
    }

    // step 5 - check increasing sequence again
    while(i+1 < n && nums[i] < nums[i+1]){
        i++;
    }

    // step 6 - return true if we have reached end
    // otherwise return false
    return i == n-1 ? true : false;
}

int main(){
    // vector<int> nums = {1,3,5,4,2,6};

    vector<int> nums = {2,1,3};
    bool res = isTrionic(nums);
    res ? cout<<"true" : cout<<"false";
    return 0;
}