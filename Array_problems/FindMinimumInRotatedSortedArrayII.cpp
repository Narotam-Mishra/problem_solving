
// Problem link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/?envType=daily-question&envId=2026-05-16

#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();

    // step 1 - search space starts with the whole array.
    int s = 0, e = n-1;
    int mid;

    // step 2 - store the index of the best minimum candidate seen so far.
    int resIdx = 0;
    while(s <= e){
        // step 3 - remove duplicate values from the left & right boundaries.
        while(s < e && nums[s] == nums[s+1]){
            s++;
        }
        while(e > s && nums[e] == nums[e-1]){
            e--;
        }

        // step 4 - pick the middle element without risking integer overflow.
        mid = s + (e - s)/2;

        // step 5 - update the answer if the middle element is smaller
        if(nums[mid] < nums[resIdx]){
            resIdx = mid;
        }

        // step 6 - check if nums[mid] is greater than nums[e], the minimum must
        // lie in the right half because the rotation point is after mid.
        if(nums[mid] > nums[e]){
            s = mid + 1;
        }else{
            // otherwise, the right side is sorted, so the minimum is at mid
            // or somewhere to the left. Since mid is already checked above,
            // continue searching before mid.
            e = mid - 1;
        }
    }

    // step 7 - return the value at the best minimum index found.
    return nums[resIdx];
}

int main(){
    // vector<int> nums = {1,3,5};

    // vector<int> nums = {3,1};

    vector<int> nums = {10,1,10,10,10};
    cout<<findMin(nums);
    return 0;
}
