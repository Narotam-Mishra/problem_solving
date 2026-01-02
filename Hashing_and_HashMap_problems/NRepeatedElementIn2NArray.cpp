
// Problem link - https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/?envType=daily-question&envId=2026-01-02

#include<bits/stdc++.h>
using namespace std;

int repeatedNTimes1(vector<int>& nums) {
    // step 1: create an unordered_map to store the frequency of each number
    unordered_map<int, int> map;

    // step 2: iterate through the array and track frequencies
    for (int num : nums) {
        map[num]++;
        // if a number appears more than once, return it
        if (map[num] > 1) {
            return num;
        }
    }
    // this case should never occur
    return -1;
}

int repeatedNTimes(vector<int>& nums) {
    // find size of nums
    int n = nums.size();

    // step 1 - start from index 2 because we want to compare
    // nums[i] with nums[i-1] and nums[i-2]
    for(int i=2; i<n; i++){
        // case 1 - same element appears consecutively
        if(nums[i] == nums[i-1]){
            return nums[i];
        }

        // case 2 - same element appears with one gap
        if(nums[i] == nums[i-2]){
            return nums[i];
        }
    }

    // step 2 : Edge case - If not found in the loop, the repeated element must be at the end 
    return nums.back();
}

int main(){
    vector<int> nums = {1,2,3,3};

    // vector<int> nums = {2,1,2,5,3,2};

    // vector<int> nums = {5,1,5,2,5,3,5,4};
    cout<<repeatedNTimes(nums)<<endl;
}