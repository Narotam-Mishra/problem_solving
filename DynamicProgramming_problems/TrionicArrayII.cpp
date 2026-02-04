
// Problem link - https://leetcode.com/problems/trionic-array-ii/description/?envType=daily-question&envId=2026-02-04

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
vector<vector<ll>> memo;

ll solveRec(int i, int trend, vector<int>& nums){
    // base case: completed checking all elements
    if(i >= n){
        if(trend == 3){
            // no more elements, we have reached out of bound
            // return 0 as we've successfully completed a valid trionic array
            return 0;
        }else{
            // in case of invalid trend (incomplete pattern), return small value
            // trends: 0=start, 1=increasing, 2=decreasing, 3=increasing again
            return LONG_MIN / 2;
        }
    }

    // check if already computed for this state
    if(memo[i][trend] != LLONG_MIN){
        return memo[i][trend];
    }

    // initialize options with invalid values
    ll take = LLONG_MIN / 2;
    ll skip = LLONG_MIN / 2;

    // option 1: skip current element (only valid in initial state)
    if(trend == 0){
        skip = solveRec(i+1, 0, nums);
    }

    // option 2: take current element
    // if trend is 3 (final increasing phase), we can end here
    if(trend == 3){
        take = nums[i];
    }
    
    // check if next element exists to validate transitions
    if(i+1 < n){
        int curr = nums[i];
        int next = nums[i+1];

        // trend 0 (start): can only move to increasing phase (trend 1)
        if(trend == 0 && next > curr){
            take = max(take, curr + solveRec(i+1, 1, nums));
        }
        // trend 1 (increasing): can stay increasing or move to decreasing (trend 2)
        else if(trend == 1){
            if(next > curr){
                take = max(take, curr + solveRec(i+1, 1, nums));
            }else if(next < curr){
                take = max(take, curr + solveRec(i+1, 2, nums));
            }
        }
        // trend 2 (decreasing): can stay decreasing or move to increasing (trend 3)
        else if(trend == 2){
            if(next < curr){
                take = max(take, curr + solveRec(i+1, 2, nums));
            }else if(next > curr){
                take = max(take, curr + solveRec(i+1, 3, nums));
            }
        }
        // trend 3 (final increasing): can only stay increasing
        else if(trend == 3 && next > curr){
            take = max(take, curr + solveRec(i+1, 3, nums));
        }
    }

    // memoize and return the maximum of taking or skipping current element
    return memo[i][trend] = max(take, skip);
}

ll maxSumTrionic(vector<int>& nums) {
    // find size of `nums`
    n = nums.size();

    // initialize memo
    memo.assign(n+1, vector<ll>(4, LLONG_MIN));

    // step 1 - solve recursively and return result
    return solveRec(0, 0, nums);
}

int main(){
    // vector<int> nums = {0,-2,-1,-3,0,2,-1};

    vector<int> nums = {1,4,2,7};
    cout<<maxSumTrionic(nums);
    return 0;
}