
// Problem link - https://leetcode.com/problems/count-special-triplets/description/?envType=daily-question&envId=2025-12-09

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int specialTriplets(vector<int>& nums) {
    // leftMap to store count of values seen on left side of `j`
    // rightMap to store count of values seen on right side of `j`
    unordered_map<int, int> leftMap, rightMap;

    // step 1 - initialize rightMap with count of `nums`
    // initially everything is on right side of `j`
    for (int& num : nums) {
        rightMap[num]++;
    }

    // store final result in `res`
    ll res = 0;

    // step 2 - iterate on each element as the middle index j
    for (int& num : nums) {
        // update right map count
        rightMap[num]--;

        // step 3 - calculate target
        // as we need nums[i] == 2 * nums[j] and nums[k] == 2 * nums[j]
        int target = num * 2;

        // step 4 - check if target is present in the map or not
        int left = leftMap[num * 2];
        int right = rightMap[num * 2];

        // step 5 - number of triplets contributed by this j is left * right
        res = (res + (1LL * left * right)) % mod;

        // step 6 - include current `num` into leftMap
        leftMap[num]++;
    }

    // step 7 - return final result `res`
    return (int)res;
}

int main(){
    // vector<int> nums = {6,3,6};

    // vector<int> nums = {0,1,0,0};

    vector<int> nums = {8,4,2,8,4};
    cout<<specialTriplets(nums);
    return 0;
}