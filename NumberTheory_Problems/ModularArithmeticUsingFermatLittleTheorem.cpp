
// Modular Arithmetic implementation using Fermat Little Throrem
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

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

// calculate factorial
ll factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % mod;
    }
    return result;
}

// Modular Inverse using Fermat's Little Theorem
// Modular inverse of b mod m = b^(m-2) mod m
ll modularInverse(ll b) {
    return fastPower(b, mod - 2);
}

// Calculate nCr mod m
ll findModular_nCr(int n, int r) {
    // invalid case
    if (r < 0 || r > n) {
        return 0;  
    }
    
    // base cases
    if (r == 0 || r == n) {
        return 1;  
    }
    
    // calculate numerator: n!
    ll a = factorial(n);
    
    // calculate denominator: r! × (n-r)!
    ll b = (factorial(r) * factorial(n - r)) % mod;
    
    // Apply Fermat's Little Theorem
    // nCr mod m = numerator × modular_inverse(denominator) mod m
    ll res = (a * modularInverse(b)) % mod;
    
    return res;
}

// Optimized version with precomputed factorials (for multiple queries)
class ModularNCR {
private:
    vector<ll> fact;
    int maxN;
    
public:
    ModularNCR(int n) : maxN(n) {
        fact.resize(n + 1);
        precomputeFactorials();
    }
    
    void precomputeFactorials() {
        fact[0] = 1;
        for (int i = 1; i <= maxN; i++) {
            fact[i] = (fact[i-1] * i) % mod;
        }
    }
    
    ll nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        
        ll a = fact[n];
        ll b = (fact[r] * fact[n - r]) % mod;
        
        return (a * fastPower(b, mod-2)) % mod;
    }
};



int main(){
    // Example 1: Single computation
    cout << "10C3 mod (10^9+7) = " << findModular_nCr(10, 3) << endl;
    
    // Example 2: Multiple computations with precomputed factorials
    ModularNCR ncr(1000);  // Precompute factorials up to 1000
    cout << "100C50 mod (10^9+7) = " << ncr.nCr(100, 50) << endl;
    cout << "500C250 mod (10^9+7) = " << ncr.nCr(500, 250) << endl;

    return 0;
}