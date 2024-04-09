
// Problem link - https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

// Approach - using Bottom Up DP

#include<bits/stdc++.h>
using namespace std;

vector<long> arr;
vector<unordered_map<long, long>> dp;

int findNumOfArithmeticSlicesIIBottomUpDP(){
    int size = arr.size();

    // Initialize an array of maps to store key value configurations for dynamic programming
    dp.resize(size);
    for(int i=0; i<size; i++){
        dp[i] = unordered_map<long, long>();
    }

    int ans = 0;
    for(int i=1; i<size; i++){
        for(int j=0; j<i; j++){
            // calculate common difference diff
            long diff = arr[i] - arr[j];
            // Check whether the map of index 'j' has difference 'diff' as the key
            if(dp[j].count(diff)){
                ans += dp[j][diff];
                if(dp[i].count(diff)){
                    // Update the count of slices for index 'i' and difference 'diff'
                    dp[i][diff] = 1 + dp[i][diff] + dp[j][diff];
                }else{
                    // Initialize the count of slices for index 'i' and difference 'diff'
                    dp[i][diff] = 1 + dp[j][diff];
                }
            }else{
                if(dp[i].count(diff)){
                    dp[i][diff] = 1 + dp[i][diff];
                }else{
                    dp[i][diff] = 1;
                }
            }
        }
    }
    // return ans
    return ans;
}

int numberOfArithmeticSlices(vector<int>& nums) {
    arr.resize(nums.size());
    for(int i=0; i<nums.size(); i++){
        arr[i] = (long)nums[i];
    }
    return findNumOfArithmeticSlicesIIBottomUpDP();
}

int main(){
    vector<int> nums = {2,4,6,8,10};
    cout<<numberOfArithmeticSlices(nums)<<endl;
    return 0;
}