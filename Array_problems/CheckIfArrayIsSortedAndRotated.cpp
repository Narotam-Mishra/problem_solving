
// Problem link - https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2026-05-23

#include<bits/stdc++.h>
using namespace std;

// Brute Force
bool check1(vector<int>& nums) {
    int n = nums.size();

    vector<int> sorted(n, 0);
    // step 1 - try every possible rotation amount r (0..n-1)
    // for an array of size n are 0..n-1. We'll use r<n to avoid extra work.
    for(int r=0; r<n; r++){
        int idx = 0;
        // step 2 - build 'sorted' as the array rotated left by r positions.
        for(int i=r; i<n; i++){
            sorted[idx++] = nums[i];
        }

        for(int i=0; i<r; i++){
            sorted[idx++] = nums[i];
        }

        // step 3 - check if rotated array 'sorted' is non-decreasing
        bool isSorted = true;
        // iterate to n-1 to avoid out-of-bounds when checking i+1
        for(int i=0; i<n-1; i++){
            if(sorted[i] > sorted[i+1]){
                isSorted = false;
                break;
            }
        }

        // step 4 - return true immediately if is sorted
        if(isSorted){
            return true;
        }
    }
    
    // step 5 - otherwise return false
    return false;
}

// Better Approach
bool check2(vector<int>& nums) {
    // get the size of the array
    int n = nums.size();

    // step 1 - create a copy of the original array
    vector<int> sorted(nums);

    // step 2 - sort the copy to get the sorted version
    sort(sorted.begin(), sorted.end());
    
    // step 3 - try every possible rotation amount r (0..n-1)
    for(int r=0; r<n; r++){
        // step 4 - assume the rotation at position r is valid
        bool isSorted = true;
        
        // step 5 - check if rotating nums by r positions matches the sorted array
        for(int i=0; i<n; i++){
            if(sorted[i] != nums[(i+r) % n]){
                // step 6 - if any element doesn't match, this rotation is invalid
                isSorted = false;
                break;
            }
        }

        // step 7 - if we found a valid rotation, return true immediately
        if(isSorted) return true;
    }
    
    // step 8 - if no valid rotation found, return false
    return false;
}

// most optimal
bool check(vector<int>& nums) {
    // get the size of the array
    int n = nums.size();

    // keep track of peak counter to count number of "breaks" where nums[i] > nums[i+1]
    int peak = 0;
    
    // step 1 - iterate through each element and check if it's greater than the next element
    for(int i=0; i<n; i++){
        // using modulo to wrap around from last element to first
        if(nums[i] > nums[(i+1) % n]){
            // step 2 - increment peak count when a decreasing point is found
            peak++;
        }
    }

    // step 3 - a sorted and rotated array should have exactly one "break" point
    return peak == 1 ? true : false;
}

int main(){
    vector<int> nums = {3,4,5,1,2};

    // vector<int> nums = {2,1,3,4};

    // vector<int> nums = {1,2,3};
    bool res = check(nums);
    res ? cout<<"true" : cout<<"false";
    return 0;
}