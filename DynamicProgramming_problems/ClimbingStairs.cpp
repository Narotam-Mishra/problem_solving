
// Problem link : https://leetcode.com/problems/climbing-stairs/

#include<bits/stdc++.h>
using namespace std;

vector<int> memo(51, 0);
int helper(int n) {
    // base case:
    if (n == 1 || n == 2) return n;

    // if value is already computed then return
    if (memo[n]) return memo[n];

    // recursively calculate and store result into memo
    memo[n] = helper(n - 1) + helper(n - 2);
    return memo[n];
}
int climbStairs(int n) {
    return helper(n);
}

int main() {
    int n = 3;
    cout << climbStairs(n);
    return 0;
}