
// Problem link - https://leetcode.com/problems/maximum-total-damage-with-spell-casting/?envType=daily-question&envId=2025-10-11

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// dp array to computed overlapping values
vector<ll> dp;

// recursive function to take or skip the power and find maximum damage
ll solveRec(vector<ll>& nums, int i, int n, unordered_map<ll, ll>& mp){
    // base case : if index out of bounds, no more damage can be added
    if(i >= n){
        return 0;
    }

    // if this state is already computed, return cached result
    if(dp[i] != -1){
        return dp[i];
    }

    // option1 - skip the current power value, as it might fall in forbidden range
    ll skipOption = solveRec(nums, i+1, n, mp);

    // option2 -  take current power value
    // find next power value that is not forbiddden range
    // using lower_bound to find first element >= nums[i] + 3
    int j = lower_bound(begin(nums)+i+1, end(nums), nums[i] + 3) - begin(nums);

    // total damage = (current power * its frequency) + damage from non-conflicting powers
    ll takeOption = nums[i] * mp[nums[i]] + solveRec(nums, j, n, mp);

    // store and return the maximum of both options
    return dp[i] = max(skipOption, takeOption);
}

ll maximumTotalDamage(vector<int>& power) {
    // step 1 - map to store frequency of each power value
    unordered_map<ll, ll> mp;
    for(int p : power){
        mp[p]++;
    }

    // step 2 - extract unique power value
    vector<ll> nums;
    for(auto [p, count] : mp){
        nums.push_back(p);
    }

    //step 3 - sort unique powers in ascending order
    // this allows us to use binary search and process in order
    sort(nums.begin(), nums.end());

    // step 4 - initialize dp array
    int n = mp.size();
    dp.assign(n+1, -1);

    // step 5 - solve recursively with memoization
    return solveRec(nums, 0, n, mp);
}

int main(){
    // vector<int> power = {1,1,3,4};

    vector<int> power = {7,1,6,6};
    cout<<maximumTotalDamage(power);
    return 0;
}