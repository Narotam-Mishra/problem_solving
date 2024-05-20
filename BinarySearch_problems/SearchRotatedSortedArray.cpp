
// Problem link - https://leetcode.com/problems/search-in-rotated-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;

    while(s <= e) {
        int mid = s + (e - s)/2;

        if(nums[mid] == target) return mid;

        // find sorted half of array in perform BS on it
        // left half is sorted so discard right half of array
        if(nums[s] <= nums[mid]){
            // check if mid is in between s to mid
            if(nums[s] <= target && target <= nums[mid]){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        // right half is sorted so discard left half of array
        }else{
            // check if mid is in between mid to end
            if(nums[mid] <= target && target <= nums[e]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0;
    int ans = search(arr, target);
    cout<<ans<<endl;
    return 0;
}