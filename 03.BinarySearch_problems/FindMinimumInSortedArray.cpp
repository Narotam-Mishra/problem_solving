
// Problem link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums){
    // check for edge case
    int len = nums.size(), ans = INT_MAX;
    if (len == 1)
        return nums[0];
    else{
        int s = 0, e = len - 1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            // identify sorted array
            if (nums[s] <= nums[mid]){
                // first element from the sorted array will be one probable ans
                ans = min(ans, nums[s]);
                // discard left half and look in right for better ans
                s = mid + 1;
            }
            else{
                ans = min(ans, nums[mid]);
                // discard right half and look in left for better ans
                e = mid - 1;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int ans = findMin(nums);
    cout<<ans<<endl;
    return 0;
}