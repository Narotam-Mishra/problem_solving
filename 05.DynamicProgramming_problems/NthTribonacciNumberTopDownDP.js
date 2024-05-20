
// Problem link - https://leetcode.com/problems/n-th-tribonacci-number/description/

let dp;
function tribTopDownDP(n){
    if(n === 0) return 0
    else if(n === 1 || n === 2) return 1;

    // if(dp[n] is already calculated then return dp[n])
    if(dp[n] !== -1) return dp[n];

    return dp[n] = tribTopDownDP(n-1) + tribTopDownDP(n-2) + tribTopDownDP(n-3)
}
let tribonacci = function(n) {
    dp = Array(n+1).fill(-1);
    return tribTopDownDP(n)
};

let num = 27;
console.log(tribonacci(num));