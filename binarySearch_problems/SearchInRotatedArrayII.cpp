
// Problem link - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

#include<bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target){
    int low = 0, high = nums.size() - 1;

    while (low <= high){
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return true;

        // if duplicates numbers exist
        if (nums[low] == nums[mid] && nums[mid] == nums[high]){
            low++;
            high--;
            continue;
        }

        // identify the sorted half of array
        // and perform BS on it
        if (nums[low] <= nums[mid]){
            if (nums[low] <= target && target <= nums[mid]){
                // discard right half of array
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if (nums[mid] <= target && target <= nums[high]){
                // discard left half of array
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return false;
}

int main(){
    vector<int> arr = {2,5,6,0,0,1,2};
    int target = 0;
    bool ans = search(arr, target);
    cout<<ans<<endl;
    return 0;
}