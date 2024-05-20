
// Problem link - https://leetcode.com/problems/longest-increasing-subsequence/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> dp;

int LIS_TopDownDP(int i){
    // Base case: if ith index 'i' is at 0
    if (i == 0) return 1;
    
    // if(dp[i]) is already calculated then return dp[i]
    if(dp[i] != -1) return dp[i];

    // there will be atleast 1 increasing subsequence in array always
    int res = 1;

    for (int j = 0; j <= i - 1; j++){
        if (arr[j] < arr[i]){
            res = max(res, 1 + LIS_TopDownDP(j));
        }
    }
    dp[i] = res;
    return res;
}

int LIS_BottomUpDP(){
    dp.resize(arr.size()+1);
    
    for(int i=0; i<arr.size(); i++){
        // Base case: if ith index 'i' is at 0
        if (i == 0) dp[i] = 1;

        else{
            // there will be atleast 1 increasing subsequence in array always
            int res = 1;
            for (int j = 0; j <= i - 1; j++){
                if (arr[j] < arr[i]){
                    res = max(res, 1 + dp[j]);
                }
            }
            dp[i] = res;
        }
    }

    // calculate final result
    int ans = numeric_limits<int>::min();
    for(int i=0; i<arr.size(); i++){
        ans = max(ans, dp[i]);
    }
    return ans;
}

int lengthOfLIS(vector<int>& nums) {
    arr = nums;
    return LIS_BottomUpDP();
}

int lengthOfLIS1(vector<int>& nums) {
    arr = nums;
    dp.assign(nums.size()+1, -1);

    int ans = numeric_limits<int>::min();
    for(int i=0; i<nums.size(); i++){
        ans = max(ans, LIS_TopDownDP(i));
    }
    return ans;
}

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    // vector<int> nums = {0,1,0,3,2,3};
    // vector<int> nums = {1,3,6,7,9,4,10,5,6};
    // vector<int> nums = {7,7,7,7,7,7,7};

    cout<<lengthOfLIS(nums)<<endl;
    return 0;
}