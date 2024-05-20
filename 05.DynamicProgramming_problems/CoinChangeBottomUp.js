
// Problem link - https://leetcode.com/problems/coin-change/description/

let dp;
let c;

function coinChangeBottomUpDp(amtVal){
    dp = Array(amtVal+1);
    dp[0] = 0;

    for(let amount=1; amount<=amtVal; amount++){
        let n = c.length;
        let res = Number.MAX_VALUE;

        // iterate over n number of coins
        for(let i=0; i<n; i++){
            if(amount >= c[i]){
                res = Math.min(res, dp[amount - c[i]]);
            }
        }

        // if ans is still Number.MAX_VALUE, then the given amount is not possible
        if(res === Number.MAX_VALUE){
            dp[amount] = Number.MAX_VALUE;
        }else{
            // otherwise calculate dp[amount]
            dp[amount] = 1 + res;
        }
    }
    return dp[amtVal];
}

let coinChange = function(coins, amount) {
    c = coins;
    let minCoins = coinChangeBottomUpDp(amount);
    return minCoins === Number.MAX_VALUE ? -1 : minCoins;
};

let coins = [1,2,5];
let amount = 11;
let ans = coinChange(coins, amount);
console.log(ans);