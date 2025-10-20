
// More Details - https://chat.deepseek.com/share/sbivk6wij6ll5r4c6e

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

// Function to compute power efficiently (Binary Exponentiation)
ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Function to compute factorial modulo MOD
ll factorial(ll n) {
    ll result = 1;
    for (ll i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

// Function to compute nCr modulo MOD
ll modular_nCr(ll n, ll r) {
    // Base cases
    if (r < 0 || r > n) {
        return 0;
    }
    if (r == 0 || r == n) {
        return 1;
    }
    
    // Calculate numerator and denominator
    ll numerator = factorial(n);
    ll denominator = (factorial(r) * factorial(n - r)) % MOD;
    
    // Compute modular inverse of denominator using Fermat's Little Theorem
    ll mod_inverse = power(denominator, MOD - 2, MOD);
    
    // Final result
    ll result = (numerator * mod_inverse) % MOD;
    return result;
}

// Optimized version with precomputed factorials (more efficient for multiple queries)
class ModularCombinations {
private:
    vector<ll> fact;
    vector<ll> inv_fact;
    ll mod;
    
public:
    ModularCombinations(int max_n, ll m = MOD) : mod(m) {
        fact.resize(max_n + 1);
        inv_fact.resize(max_n + 1);
        
        // Precompute factorials
        fact[0] = 1;
        for (int i = 1; i <= max_n; i++) {
            fact[i] = (fact[i-1] * i) % mod;
        }
        
        // Precompute inverse factorials using Fermat's Little Theorem
        inv_fact[max_n] = power(fact[max_n], mod - 2, mod);
        for (int i = max_n - 1; i >= 0; i--) {
            inv_fact[i] = (inv_fact[i+1] * (i+1)) % mod;
        }
    }
    
    ll nCr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        return (fact[n] * inv_fact[r] % mod) * inv_fact[n - r] % mod;
    }
};

int main() {
    // Test the modular_nCr function
    cout << "Testing modular_nCr:" << endl;
    cout << "5C2 = " << modular_nCr(5, 2) << endl;  // 10
    cout << "10C3 = " << modular_nCr(10, 3) << endl; // 120
    cout << "7C4 = " << modular_nCr(7, 4) << endl;  // 35
    
    // Test the optimized version
    cout << "\nTesting optimized version:" << endl;
    ModularCombinations comb(1000);
    cout << "5C2 = " << comb.nCr(5, 2) << endl;  // 10
    cout << "10C3 = " << comb.nCr(10, 3) << endl; // 120
    
    return 0;
}