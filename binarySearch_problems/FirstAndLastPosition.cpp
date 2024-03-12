
// Problem link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLowerBound(vector<int>& arr, int x){
        int s = 0, e = arr.size() - 1;
        int ans = arr.size();

        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr[mid] < x){
                s = mid + 1;
            }else{
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }
    int findUpperBound(vector<int>& arr, int x){
        int s = 0, e = arr.size() - 1;
        int ans = arr.size();

        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr[mid] <= x){
                s = mid + 1;
            }else{
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = findLowerBound(nums, target);
        vector<int> ans(2);

        if(lb == nums.size() || nums[lb] != target){
            ans[0] = -1;
            ans[1] = -1;
        }else{
            int ub = findUpperBound(nums, target);
            ans[0] = lb;
            ans[1] = ub - 1;
        }
        return ans;
    }
};