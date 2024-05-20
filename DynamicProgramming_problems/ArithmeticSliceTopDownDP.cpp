
// Problem link - https://leetcode.com/problems/arithmetic-slices/description/

// Approach - using TopDown DP


#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> dp;

int findNumOfArithmeticSlicesTopDownDP(int i){
    // Base case1: if ith index is 0 or 1 then there is no Arithmetic slice return 0
    if(i == 0 || i == 1) return dp[i] = 0;

    // Base case2 : if the difference between any two consecutive elements is not the same then return 0
    if(arr[i] -arr[i-1] != arr[i-1] - arr[i-2]) return dp[i] = 0;

    // if dp[i] is already calculated then return dp[i]
    if (dp[i] != -1) return dp[i];

    // Recursive case
    return dp[i] = 1 + findNumOfArithmeticSlicesTopDownDP(i-1);
}

int findNumOfArithmeticSlicesBottomUpDP(){
    for (int i = 0; i < arr.size(); i++){
        // Base case1: if ith index is 0 or 1 then there is no Arithmetic slice return 0
        if (i == 0 || i == 1) dp[i] = 0;

        // Base case2 : if the difference between any two consecutive elements is not
        // the same then return 0
        else if (arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2]) dp[i] = 0;

        else{
            // store ans in Bottom Up DP
            dp[i] = 1 + dp[i - 1];
        }
    }

    int res = 0;
    for (int id = 0; id < arr.size(); id++){
        res += dp[id];
    }

    return res;
}

int numberOfArithmeticSlices(vector<int>& nums) {
    arr = nums;
    dp.resize(nums.size()+1);
    return findNumOfArithmeticSlicesBottomUpDP();
}

int numberOfArithmeticSlices1(vector<int>& nums) {
    arr = nums;
    dp.assign(nums.size()+1, -1);

    int res = 0;
    for(int i=0; i<nums.size(); i++){
        res += findNumOfArithmeticSlicesTopDownDP(i);
    }
    return res;
}

int main(){
    vector<int> arr = {1,2,3,4};
    cout<<numberOfArithmeticSlices(arr)<<endl;
    return 0;
}