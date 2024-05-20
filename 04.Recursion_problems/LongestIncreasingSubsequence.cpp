
// Problem link - https://leetcode.com/problems/longest-increasing-subsequence/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

int LIS_Rec(int i){
    // Base case: if ith index 'i' is at 0
    if (i == 0)
        return 1;

    // there will be atleast 1 increasing subsequence in array always
    int res = 1;

    for (int j = 0; j <= i - 1; j++){
        if (arr[j] < arr[i]){
            res = max(res, 1 + LIS_Rec(j));
        }
    }
    return res;
}

int lengthOfLIS(vector<int>& nums) {
    arr = nums;
    int ans = numeric_limits<int>::min();
    for(int i=0; i<nums.size(); i++){
        ans = max(ans, LIS_Rec(i));
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