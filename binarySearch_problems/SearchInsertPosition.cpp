
// Problem link - https://leetcode.com/problems/search-insert-position/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLowerBound(vector<int>& arr, int x){
        int s = 0, e = arr.size()-1;
        int ans = arr.size();

        while(s <= e){
            int mid = s + (e-s)/2;
            if(x > arr[mid]){
                s = mid + 1;
            }else{
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }

    int searchInsert(vector<int>& nums, int target) {
        int lb = findLowerBound(nums, target);
        return lb;
    }
};