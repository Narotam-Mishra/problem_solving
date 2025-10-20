
// Binary Exponentiation or Fast Exponentiation

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

ll findPower(ll a, ll b){
    // base case:
    if(b == 0) return 1;

    ll halfPower = findPower(a, b/2);

    ll res = (halfPower * halfPower) % mod;

    if(b % 2 == 1){
        res = (res * a) % mod;
    }
    return res;
}

int main(){
    return 0;
}
