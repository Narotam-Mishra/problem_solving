
// Problem link - https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/?envType=daily-question&envId=2026-04-08

#include<bits/stdc++.h>
using namespace std;

int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    const int mod = 1e9 + 7;

    // step 1 - iterate on each query
    for(auto query : queries){
        // extract value from queries
        int l = query[0];
        int r = query[1];
        int k = query[2];
        int v = query[3];

        // step 2 - perform given operation
        while(l <= r){
            nums[l] = (1LL * nums[l] * v) % mod;

            l += k;
        }
    }

    // step 3 - perform XOR for all element
    int res = 0;
    for(int &num : nums){
        res ^= num;
    }

    // step 4 - return final result
    return res;
}

int main(){
    // vector<int> nums = {1,1,1};
    // vector<vector<int>> queries = {{0,2,1,4}};

    vector<int> nums = {2,3,1,5,4};
    vector<vector<int>> queries = {{1,4,2,3},{0,2,1,2}};
    cout<<xorAfterQueries(nums, queries);
    return 0;
}