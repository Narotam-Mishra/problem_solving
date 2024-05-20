
// Problem link - https://leetcode.com/problems/fibonacci-number/

let dp;
function findFibonacciBU(n){
    if(n === 0 || n === 1) return n;

    dp = Array(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(let i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

let fib = function(n) {
    return findFibonacciBU(n);
};