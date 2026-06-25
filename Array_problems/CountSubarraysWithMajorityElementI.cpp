
// Problem link - https://leetcode.com/problems/count-subarrays-with-majority-element-i/description/?envType=daily-question&envId=2026-06-25

#include<bits/stdc++.h>
using namespace std;

int countMajoritySubarrays(vector<int>& nums, int target) {
    // get array size
    int n = nums.size();

    // keep track of final result in `res`
    int res = 0;

    // step 1 - iterate on each subarray
    for(int i=0; i<n; i++){
        // keep track of number of occurrences of 'target'
        int cnt = 0;
        for(int j=i; j<n; j++){
            // step 2 - if the new element equals target, increment its count
            if(nums[j] == target) cnt++;

            // keep track of current subarray size
            int subSize = j-i+1;

            // step 3 - check if target appears strictly more than half of the elements
            if(cnt > subSize/2){
                // increment final result, `res`
                res++;
            }
        }
    }

    // step 4 - return final result, `res`
    return res;
}

int main(){
    // vector<int> nums = {1,2,2,3};
    // int target = 2;

    // vector<int> nums = {1,1,1,1};
    // int target = 1;

    vector<int> nums = {1,2,3};
    int target = 4;
    cout<<countMajoritySubarrays(nums, target);
    return 0;
}