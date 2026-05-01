
// Problem link - https://leetcode.com/problems/rotate-function/description/?envType=daily-question&envId=2026-05-01

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();

    // step 1 - compute total sum
    ll totalSum = 0;
    for(int x : nums){
        totalSum += x;
    }

    // step 2 - compute F(0) = 0*nums[0] + 1*nums[1] + ... + (n-1)*nums[n-1]
    ll F = 0;
    for(int i=0; i<n; i++){
        F += (ll)i * nums[i];
    }

    // initialize max with F(0)
    ll maxF = F;

    // step 3 - Use the recurrence to compute F(1), F(2), ..., F(n-1)
    // formula: F(k) = F(k-1) + totalSum - n * nums[n-k]
    for(int k=1; k<n; k++){
        F = F + totalSum - (ll)n * nums[n-k];
        maxF = max(maxF, F);
    }

    // step 4 - return maximum value of rotation function
    return (int)maxF;
}

int main(){
    // vector<int> nums = {4,3,2,6};

    vector<int> nums = {100};
    cout<<maxRotateFunction(nums);
    return 0;
}