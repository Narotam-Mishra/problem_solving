
// Problem link - https://leetcode.com/problems/maximum-product-of-three-numbers/?envType=problem-list-v2&envId=array

/*
Two possible scenarios for maximum product:
1. Three largest positive numbers: nums[n-1] * nums[n-2] * nums[n-3]
2. Two smallest negative numbers * largest positive: nums[0] * nums[1] * nums[n-1]
(since negative * negative = positive, and we want the largest positive result)
*/

#include<bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int>& nums) {
    int n = nums.size();

    // step1 - sort `nums` array
    sort(nums.begin(), nums.end());

    // step 2 - calculate maximum product of three maximum positive numbers
    long long int prod1 = nums[n - 1] * nums[n - 2] * nums[n - 3];

    // step 3 - calculate maximum product of two smallest negative numbers and a
    // largest positive number
    long long int prod2 = nums[0] * nums[1] * nums[n - 1];

    // step 4 - return the maximum product
    return (int)max(prod1, prod2);
}

int main(){
    // vector<int> nums = {1,2,3};

    // vector<int> nums = {1,2,3,4};

    vector<int> nums = {-1,-2,-3};
    cout<<maximumProduct(nums);
    return 0;
}