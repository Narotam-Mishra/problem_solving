
// Problem link - https://leetcode.com/problems/n-th-tribonacci-number/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> dp;

int findNthTribonacciNumberTopDownDP(int n){
    if(n == 0) return 0;
    else if(n == 1 || n == 2) return 1;

    // if dp[n] is already calculated then return dp[n];
    if(dp[n] != -1) return dp[n];

    return dp[n] = findNthTribonacciNumberTopDownDP(n-1) + findNthTribonacciNumberTopDownDP(n-2) + findNthTribonacciNumberTopDownDP(n-3);
}
int tribonacci(int n) {
    dp.assign(n+1, -1);
    return findNthTribonacciNumberTopDownDP(n);
}

int main(){
    int num = 25;
    cout<<tribonacci(num)<<endl;
    return 0;
}