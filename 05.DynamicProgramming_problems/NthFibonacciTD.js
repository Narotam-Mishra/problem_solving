
// Problem link - https://leetcode.com/problems/fibonacci-number/

let dp;

function findFibonacciMemo(n){
    if(n === 0 || n === 1) return n;

    // if dp[n] is already calculated then return its value
    if(dp[n] !== -1) return dp[n];

    // otherwise calculate dp[n]
    return dp[n] = findFibonacciMemo(n-1) + findFibonacciMemo(n-2);
}

let fib = function(n) {
    dp = Array(100).fill(-1);
    return findFibonacciMemo(n);
};