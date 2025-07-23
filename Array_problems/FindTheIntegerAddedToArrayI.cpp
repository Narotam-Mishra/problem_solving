
// Problem link - https://leetcode.com/problems/find-the-integer-added-to-array-i/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

int addedInteger(vector<int>& nums1, vector<int>& nums2) {
    // step 1: assume the first element is the minimum initially
    int min1 = nums1[0], min2 = nums2[0];

    // step 2: find the actual minimum value in nums1
    for (int num : nums1) {
        min1 = min(min1, num);
    }

    // step 3: find the actual minimum value in nums2
    for (int num : nums2) {
        min2 = min(min2, num);
    }

    // step 4 - retun the difference between min2 and min1 is the added integer `x`
    return min2 - min1;
}

int main(){
    // vector<int> nums1 = {2,6,4}, nums2 = {9,7,5};

    // vector<int> nums1 = {10}, nums2 = {5};

    vector<int> nums1 = {1,1,1,1}, nums2 = {1,1,1,1};
    cout<<addedInteger(nums1, nums2);
    return 0;
}