
// Problem link - https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/?envType=daily-question&envId=2025-10-12

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;
int N, M, K;

// using map as cache
unordered_map<string, int> cache;

// recursive helper function to calculate sum of products for all magical sequences
ll solveRec(int count, ll sum, vector<int>& nums){
    // step 1 - base case: we've selected M indices
    if(count == M){
        // step 1.1 - check if the binary representation of sum has exactly K set bits
        if(__builtin_popcountll(sum) == K){
            // valid magical sequence found, contribute 1 to the product chain
            return 1;
        }
        // invalid sequence, contribute 0
        return 0;
    }

    // step 2 - create unique key for memoization based on current state
    string key = to_string(count) + "-" + to_string(sum);

    // step 3 - return cached result if this state was computed before
    if(cache.count(key)){
        return cache[key];
    }

    // step 4 - try adding each index from 0 to N-1 to the current sequence
    ll totalSum = 0;
    for(int i=0; i<N; i++){
        //step 4.1 - add 2^i to the current sum (representing selection of index i)
        ll newSum = sum + (1LL << i);
        
        // step 4.2 - recursively calculate sum for sequences that include index i at this position
        // multiply by nums[i] as this index contributes nums[i] to the product
        ll prod = (nums[i] * solveRec(count+1, newSum, nums)) % mod;
        
        // step 4.3 - add this contribution to the total sum
        totalSum = (totalSum + prod) % mod;
    }

    // step 5 - cache the result before returning
    return cache[key] = totalSum;
}

int magicalSum(int m, int k, vector<int>& nums) {
    // initialization
    M = m;
    K = k;
    N = nums.size();

    // solve the problem recursively by using memoization
    return (int)(solveRec(0, 0, nums) % mod);
}

int main(){
    int m = 2, k = 2;
    vector<int> nums = {5,4,3,2,1};

    // int m = 1, k = 1;
    // vector<int> nums = {28};

    // int m = 5, k = 5;
    // vector<int> nums = {1,10,100,10000,1000000};
    cout<<magicalSum(m, k, nums);
    return 0;
}