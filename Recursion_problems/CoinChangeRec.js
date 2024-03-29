
// Problem link - https://leetcode.com/problems/coin-change/description/

let c = [];

function coinChangeRecursive(amount){
    // Base case: if amount is negative or zero
    if(amount < 0) return Number.MAX_VALUE;
    if(amount === 0) return 0;

    let ans = Number.MAX_VALUE;
    let n = c.length;

    // Recursive case f(amount) = 1 + min(f(amount - coins[i]))
    for(let i=0; i<n; i++){
        if(amount >= c[i])
        ans = Math.min(ans, coinChangeRecursive(amount - c[i]));
    }

    // if ans is still Number.MAX_VALUE, then the given amount is not possible
    if(ans === Number.MAX_VALUE) return Number.MAX_VALUE;

    // ans + 1 --> here + 1 is for to react that way
    return 1 + ans;
}

let coinChange = function(coins, amount) {
    c = coins;
    let minCoin = coinChangeRecursive(amount);
    return minCoin === Number.MAX_VALUE ? -1 : minCoin;
};

// let coins = [2];
// let amount = 3;

// let coins = [1];
// let amount = 0;

let coins = [1,2,5];
let amount = 11;
let ans = coinChange(coins, amount);
console.log(ans);