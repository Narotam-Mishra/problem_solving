
// Problem link - https://leetcode.com/problems/coin-change/description/


let c;
let dp;

function coinChangeTopDownDP(amount){
    // Base case: if amount is negative or zero
    if(amount < 0) return Number.MAX_VALUE;
    if(amount === 0) return 0;

    // if dp[amount] is already calculated then return dp[amount]
    if(dp[amount] !== -1) return dp[amount];

    let ans = Number.MAX_VALUE;
    let n = c.length;

    // Recursive case f(amount) = 1 + min(f(amount - coins[i]))
    for(let i=0; i<n; i++){
        if(amount >= c[i])
        ans = Math.min(ans, coinChangeTopDownDP(amount - c[i]));
    }

    // if ans is still Number.MAX_VALUE, then the given amount is not possible
    if(ans === Number.MAX_VALUE) return dp[amount] = Number.MAX_VALUE;

    // ans + 1 --> here + 1 is for to react that way
    return dp[amount] = 1 + ans;
}

let coinChange = function(coins, amount) {
    c = coins;
    dp = Array(amount+1).fill(-1);
    let minCoin = coinChangeTopDownDP(amount);
    return minCoin === Number.MAX_VALUE ? -1 : minCoin;
};

let coins = [1,2,5];
let amount = 11;
let ans = coinChange(coins, amount);
console.log(ans);