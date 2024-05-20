
// Problem link - https://leetcode.com/problems/split-array-largest-sum/description/

#include<bits/stdc++.h>
using namespace std;

bool isBestWayToSplitArrayWithMidSubArray(vector<int>& arr, int mid, int k){
    int sc = 0, runningSum = 0;
    for(int i=0; i<arr.size(); i++){
        // if sub array running sum is greater than mid
        // increment the subArray counter, sc
        if(runningSum + arr[i] > mid){
            sc++;
            runningSum = 0;
        }
        runningSum += arr[i];
    }
    // increment sub array counter, sc for last running subArray sum, runningSum
    sc++;
    return sc <= k;
}

int splitArray(vector<int>& nums, int k) {
    int maxNum = -1, totalSum = 0;

    for(int num : nums){
        maxNum = max(maxNum, num);
        totalSum += num;
    }

    // since we have to find the minimized largest sum of the split (in sub array)
    // hence the search space will be from low = maxNum (maximum number in array) to high = totalSum (total sum of array)
    int low = maxNum, high = totalSum;
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(isBestWayToSplitArrayWithMidSubArray(nums, mid, k)){
            // found first probable answer as mid
            ans = mid;
            // since we have to find the minimized largest sum of the split
            // hence we discard right half of search space
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {7,2,5,10,8};
    int k = 2;
    int ans = splitArray(arr, k);
    cout<<ans<<endl;
    return 0;
}