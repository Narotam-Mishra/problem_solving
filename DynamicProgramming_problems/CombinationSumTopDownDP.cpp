
// Problem link - https://leetcode.com/problems/combination-sum-iv/

#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> dp;

int findNumberOfPossibleCombinationsTopDownDP(int curTarget){
    // Base case: if target become 0 then we will first way
    if (curTarget == 0) return 1;

    // if dp[curTarget] is already computed then return dp[curTarget]
    if (dp[curTarget] != -1) return dp[curTarget];

    // Recursive case: recurively calculate number of possible combinations that add up to target
    // f(target) = f(target - arr[i])

    int res = 0;
    for (int i = 0; i < arr.size(); i++){
        if (curTarget - arr[i] >= 0){
            res += findNumberOfPossibleCombinationsTopDownDP(curTarget - arr[i]);
        }
    }
    dp[curTarget] = res;
    return res;
}

// using Bottom Up DP
int findNumberOfPossibleCombinationsBottomUpDP(int target){
    dp.resize(target + 1);

    for (int curTarget = 0; curTarget <= target; curTarget++){
        // Base case: if target become 0 then we will first way
        if (curTarget == 0) dp[curTarget] = 1;

        // Recursive case: recurively calculate number of possible combinations that add up to target
        // f(target) = f(target - arr[i])
        else{
            long long res = 0;
            for (int i = 0; i < arr.size(); i++){
                if (curTarget - arr[i] >= 0){
                    res += dp[curTarget - arr[i]];
                }
            }
            dp[curTarget] = (int)res;
        }
    }
    return dp[target];
}

int combinationSum4(vector<int>& nums, int target) {
    arr = nums;
    dp.assign(target+1, -1);
    return findNumberOfPossibleCombinationsTopDownDP(target);
}

int main(){
    vector<int> nums = {1,2,3};
    int target = 4;
    cout<<combinationSum4(nums, target)<<endl;
    return 0;
}