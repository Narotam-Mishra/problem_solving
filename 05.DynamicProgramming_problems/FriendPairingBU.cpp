
// Problem link - https://www.codingninjas.com/studio/problems/friends-pairing-problem_1214625?leftPanelTabValue=PROBLEM

// Approach - Top Down BU (Tabulation)

#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long int friendPairing(int n){
    vector<long long int>dp(n+1, 0);

    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++){
        dp[i] = ((dp[i-1])%mod + ((i - 1) * dp[i-2])%mod)%mod;
    }
    return dp[n];
}

int numberOfWays(int n){
    return (int)friendPairing(n);
}
