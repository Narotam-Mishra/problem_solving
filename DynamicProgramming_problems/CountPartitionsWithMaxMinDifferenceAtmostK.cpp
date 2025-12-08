
// Problem link - https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;
ll memo[50000 + 1];

// Approach1 - using Recursion + Memoization
ll solveRec(int i, vector<int>& nums, int k) {
    // base case: array partition is completed now
    if (i >= nums.size()) {
        // we find 1 way to make partition
        return 1;
    }

    // if answer is already computed then return it
    if (memo[i] != -1) {
        return memo[i];
    }

    // recursive case
    int maxNum = INT_MIN, minNum = INT_MAX;
    ll ways = 0;
    for (int j = i; j < nums.size(); j++) {
        minNum = min(minNum, nums[j]);
        maxNum = max(maxNum, nums[j]);

        if (maxNum - minNum > k) {
            break;
        }
        ways = (ways + solveRec(j + 1, nums, k)) % mod;
    }
    return memo[i] = ways;
}

int countPartitions1(vector<int>& nums, int k) {
    int n = nums.size();
    memset(memo, -1, sizeof(memo));
    return solveRec(0, nums, k);
}

// Approach2 - using Bottom Up DP
int countPartitions2(vector<int>& nums, int k) {
    int n = nums.size();

    ll dp[n+1];

    // base case: same as solve(n) = 1
    dp[n] = 1;

    // step 1 - fill dp states from n-1 down to 0
    for(int i=n-1; i>=0; i--){
        ll count = 0;
        int minNum = INT_MAX, maxNum = INT_MIN;

        // step 2 - perfrom the recursive task
        for (int j = i; j < nums.size(); j++) {
            minNum = min(minNum, nums[j]);
            maxNum = max(maxNum, nums[j]);

            if (maxNum - minNum > k) {
                break;
            }
            count = (count + dp[j+1]) % mod;
        }

        // store count in dp
        dp[i] = count;
    }

    // step 3 - return the total number of ways to partition
    return (int)dp[0];
}

// Approach3 - using DP with Prefix Sum and monotonic deque
int countPartitions(vector<int>& nums, int k) {
    int n = nums.size();

    // using dp and prefix array
    vector<int> dp(n+1, 0);
    vector<int> pref(n+1, 0);

    dp[0] = 1;
    pref[0] = 1;

    // using deque to store maximum and minimum number in current window
    deque<int> minDeq, maxDeq;

    // step 1 - iterate on each window
    int i=0, j=0;
    while(j < n){
        // step 2 - update maximum and minimum in each window
        while(!maxDeq.empty() && nums[j] > nums[maxDeq.back()]){
            maxDeq.pop_back();
        }
        maxDeq.push_back(j);

        while(!minDeq.empty() && nums[j] < nums[minDeq.back()]){
            minDeq.pop_back();
        }
        minDeq.push_back(j);

        // step 3 - shrink window if condiiton not satisfy
        while(i <= j && nums[maxDeq.front()] - nums[minDeq.front()] > k){
            i++;

            if(!maxDeq.empty() && maxDeq.front() < i){
                maxDeq.pop_front();
            }

            if(!minDeq.empty() && minDeq.front() < i){
                minDeq.pop_front();
            }
        }

        // step 4 - fill dp array
        dp[j+1] = (pref[j] - (i > 0 ? pref[i-1] : 0) + mod) % mod;
        
        // step 5 - update prefix sum
        pref[j+1] = (pref[j] + dp[j+1]) % mod;

        // move through next window
        j++;
    }

    // step 6 - return final result
    return dp[n];
}

int main(){
    vector<int> nums = {9,4,1,3,7};
    int k = 4;

    // vector<int> nums = {3,3,4};
    // int k = 0;
    cout<<countPartitions(nums, k);
    return 0;
}