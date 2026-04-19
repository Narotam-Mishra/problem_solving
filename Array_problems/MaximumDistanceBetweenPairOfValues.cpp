
// Problem link - https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/?envType=daily-question&envId=2026-04-19

#include<bits/stdc++.h>
using namespace std;

int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    // get the sizes of both arrays
    int m = nums1.size();
    int n = nums2.size();

    // keep track of maximum distance
    int maxD = 0;

    // using two pointers, one for each array
    int i = 0, j = 0;

    // step 1 - iterate through both arrays using the two-pointer technique
    while (i < m && j < n) {
        // step 2 - check If nums1[i] > nums2[j], we need to move the pointer for nums1 forward
        // because we can't use this i for future j's as the condition nums1[i] <= nums2[j] won't hold
        if (nums1[i] > nums2[j]) {
            i++;
        } else {
            // step 3 - check If nums1[i] <= nums2[j], calculate the distance j - i and update maxD if larger
            maxD = max(maxD, j - i);
            // step 4 - move the pointer for nums2 forward to check for larger distances with the same i
            j++;
        }
    }
    // Step 5 - return the maximum distance found
    return maxD == 0 ? 0 : maxD;
}

int main(){
    // vector<int> nums1 = {55,30,5,4,2}, nums2 = {100,20,10,10,5};

    // vector<int> nums1 = {2,2,2}, nums2 = {10,10,1};

    vector<int> nums1 = {30,29,19,5}, nums2 = {25,25,25,25,25};
    
    cout << maxDistance(nums1, nums2);
    return 0;
}