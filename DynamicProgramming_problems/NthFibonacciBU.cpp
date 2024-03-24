
// Problem link - https://www.codingninjas.com/studio/problems/nth-fibonacci-number_1115780

// Approach - Bottom Up DP

#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int findNthFibonacciNumberBU(int n){
    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%mod;
    }

    return dp[n];
}

int fibonacciNumber(int n) {
    return findNthFibonacciNumberBU(n);
}

int main(){
    int n = 95;
    cout<<fibonacciNumber(n);
    return 0;
}