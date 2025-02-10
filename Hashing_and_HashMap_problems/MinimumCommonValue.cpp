
// Problem link : https://leetcode.com/problems/minimum-common-value/description/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

int getCommon(vector<int>& nums1, vector<int>& nums2) {
    // step 1 - intialize two pointers for both arrays `nums1` & `nums2`
    int i = 0, j = 0;

    // step 2 - iterate both arrays using two pointers
    while (i < nums1.size() && j < nums2.size()) {
        // if both numbers are equal
        if (nums1[i] == nums2[j]) {
            // then we found the smallest common integer
            return nums1[i];
        }
        else if (nums1[i] < nums2[j]) {
            // move pointer in nums1 forward
            i++;
        }
        else {
            // move pointer in nums2 forward
            j++;
        }
    }

    // step 3 - otherwise return -1
    return -1;
}

int main(){
    // vector<int> nums1 = {1, 2, 3};
    // vector<int> nums2 = {2, 4};

    vector<int> nums1 = {1, 2, 3, 6};
    vector<int> nums2 = {2, 3, 4, 5};
    cout<<getCommon(nums1, nums2)<<endl;
    return 0;
}