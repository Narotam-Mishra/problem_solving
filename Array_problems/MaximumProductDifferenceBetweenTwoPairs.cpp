
// Problem link - https://leetcode.com/problems/maximum-product-difference-between-two-pairs/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

// Brute Force Appraoch
int maxProductDifference1(vector<int>& nums) {
    // get length of `nums` array
    int n = nums.size();

    // step 1 - sort `nums` array in ascending order
    sort(nums.begin(), nums.end());

    // step 2 - get first two minimum numbers from `nums`
    int minNum1 = nums[0];
    int minNum2 = nums[1];

    // step 3 - get first two maximum numbers from `nums`
    int maxNum1 = nums[n - 1];
    int maxNum2 = nums[n - 2];

    // step 4 - find and return maximum product difference `maxProdDiff`
    int maxProdDiff = (maxNum1 * maxNum2) - (minNum1 * minNum2);
    return maxProdDiff;
}

// Efficient Appraoch
int maxProductDifference(vector<int>& nums) {
    // find maximum and minimum numbers
    int maxNum1 = INT_MIN, maxNum2 = INT_MIN;
    int minNum1 = INT_MAX, minNum2 = INT_MAX;

    // step 1 - find the two largest and two smallest numbers in one pass
    for(int num : nums){
        // update largest numbers
        if(num > maxNum1){
            maxNum2 = maxNum1;
            maxNum1 = num;
        }else if(num > maxNum2){
            maxNum2 = num;
        }

        // update smallest numbers
        if(num < minNum1){
            minNum2 = minNum1;
            minNum1 = num;
        }else if(num < minNum2){
            minNum2 = num;
        }
    }

    // step 2: calculate and return the maximum product difference
    return (maxNum1 * maxNum2) - (minNum1 * minNum2);
}

int main(){
    vector<int> nums = {5,6,2,7,4};

    // vector<int> nums = {4,2,5,9,7,4,8};
    cout<<maxProductDifference(nums)<<endl;
}