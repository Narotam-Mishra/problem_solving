
// Problem link - https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/?envType=daily-question&envId=2025-10-12

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;
int N, K;

vector<ll> fact;
vector<ll> invFact;

map<tuple<ll, int, int, int>, ll> cache;

// utility function to compute a^b
ll fastPower(ll a, ll b){
    // base case:
    if(b == 0) return 1;

    // recursively compute power
    ll halfPower = fastPower(a, b/2);

    // store result in `res`
    ll res = (halfPower * halfPower) % mod;

    if(b % 2 == 1){
        res = (res * a) % mod;
    }
    return res;
}

// utility function to compute nCr % mod
ll nCr(int n, int r) {
    // nCr = n! * invFact(n-r)! * invFact(r)!
    return (((fact[n] * invFact[r]) % mod) * invFact[n-r]) % mod;
}

// Optimized Approach using Combinatorics
ll computeRec(ll binarySum, int m, int k, int i, vector<int>& nums){
    auto key = make_tuple(binarySum, m, k, i);

    if(cache.count(key)){
        return cache[key];
    }

    // base case:
    if(m == 0 && __builtin_popcount(binarySum) == k){
        return 1;
    }

    if(m == 0 || i>= N){
        return 0;
    }

    ll totalSum = 0;

    // skip index `i`
    totalSum = (totalSum + computeRec((binarySum>>1), m, k-(binarySum & 1), i+1, nums)) % mod;
    
    // take index `i` frq number of times
    for(int frq=1; frq<=m; frq++){
        ll newBinarySum = binarySum + frq;

        ll prod = computeRec((newBinarySum >> 1), m-frq, k - (newBinarySum & 1), i+1, nums) % mod;

        prod = (fastPower(nums[i], frq) % mod * prod % mod) % mod;

        prod = (prod * nCr(m, frq)) % mod;

        totalSum = (totalSum + prod) % mod;
    }

    return cache[key] = totalSum;
}

int magicalSum(int m, int k, vector<int>& nums) {
    // initialization
    K = k;
    N = nums.size();

    // precompute factorial and inverse factorial
    fact.assign(m+1, 1);
    invFact.assign(m+1, 1);

    for(int i=2; i<=m; i++){
        fact[i] = (fact[i-1] * i) % mod;
    }

    // using Fermat's Little Thorem for inverse factorial
    for(int i=0; i<=m; i++){
        invFact[i] = fastPower(fact[i], mod-2);
    }

    // solve the problem recursively by using memoization
    return (int)(computeRec(0, m, k, 0, nums)) % mod;
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