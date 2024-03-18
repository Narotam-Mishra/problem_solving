
// Problem link - https://leetcode.com/problems/find-peak-element/description/

#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums){
    int len = nums.size();
    if (len == 1)
        return 0;
    else if (nums[0] > nums[1])
        return 0;
    else if (nums[len - 1] > nums[len - 2])
        return len - 1;
    else{
        int l = 1, r = len - 2;
        while (l <= r){
            int mid = (l + r) / 2;
            // check mid for peak element
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] > nums[mid + 1]){
                // discard right half array
                r = mid - 1;
            }
            else{
                // otherwise discard left half of array
                l = mid + 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,1,3,5,6,4};
    int ans = findPeakElement(arr);
    cout<<ans<<endl;
    return 0;
}