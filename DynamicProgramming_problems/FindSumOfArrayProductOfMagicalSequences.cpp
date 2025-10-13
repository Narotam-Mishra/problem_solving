
// Problem link - https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/?envType=daily-question&envId=2025-10-12

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;
int N, M, K;

// using map as cache
unordered_map<string, int> cache;

ll solveRec(int count, ll sum, vector<int>& nums){
    // base case
    if(count == M){
        if(__builtin_popcountll(sum) == K){
            return 1;
        }
        return 0;
    }

    string key = to_string(count) + "-" + to_string(sum);

    if(cache.count(key)){
        return cache[key];
    }

    ll totalSum = 0;
    for(int i=0; i<N; i++){
        ll newSum = sum + (1LL << i);

        ll prod = (nums[i] * solveRec(count+1, newSum, nums)) % mod;

        totalSum = (totalSum + prod) % mod;
    }

    return cache[key] = totalSum;
}

int magicalSum(int m, int k, vector<int>& nums) {
    M = m;
    K = k;
    N = nums.size();
    return (int)(solveRec(0, 0, nums) % mod);
}

int main(){
    int m = 2, k = 2;
    vector<int> nums = {5,4,3,2,1};
    cout<<magicalSum(m, k, nums);
    return 0;
}