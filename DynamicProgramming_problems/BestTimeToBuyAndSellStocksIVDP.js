
// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

// Approach - using Top Down DP

let pArr;
let dp;

function findMaxProfitTopDownDP(i, k, ts){
    // Base case: all days are completed
    if(i === pArr.length) return 0;

    // if dp[i][k][ts] is already computed then return dp[i][k][ts]
    if(dp[i][k][ts] !== -1) return dp[i][k][ts];

    let ans = -1;

    // Recursive case:
    // Case 1 : Ignore stock
    ans = Math.max(ans, findMaxProfitTopDownDP(i+1, k, ts));

    // Case 2 : Buy the stock on ith day
    if(k > 0 && ts === 0){
        ans = Math.max(ans, -pArr[i] + findMaxProfitTopDownDP(i+1, k, 1));
    }

    // Case 3 : sell the stock on the i-th day
    if(ts === 1){
        ans = Math.max(ans, pArr[i] + findMaxProfitTopDownDP(i+1, k-1, 0));
    }
    return dp[i][k][ts] = ans;
}

let maxProfit = function(K, prices) {
    pArr = prices;
    dp = new Array(1005);
    for(let i = 0; i < 1005; i++) {
        dp[i] = new Array(105);
    }
    for(let i = 0; i < 1005; i++) {
        for(let j = 0; j < 105; j++) {
            dp[i][j] = new Array(2).fill(-1);

        }
    }
    return findMaxProfitTopDownDP(0, K, 0);
};

let k = 2;
// let prices = [2,4,1];

// let prices = [3,2,6,5,0,3]

let prices = [7,4,2,1,11];
console.log(maxProfit(k, prices));