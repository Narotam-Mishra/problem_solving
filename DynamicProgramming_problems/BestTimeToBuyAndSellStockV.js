
// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/description/

let maximumProfit = function(prices, k) {
    const n = prices.length;
    const NEG_INF = -1e18;

    // array for memoization
    const memo = Array.from({ length: n }, () =>
      Array.from({ length: k + 1 }, () => Array(3).fill(null))
    );

    const solveRec = (i, k, c) => {
        // base case: no more transactions left or no more days left
        if(i >= n){
            if(c === 0) return 0;

            // unfinished transaction: transaction is invalid
            return NEG_INF;
        }

        // memoization check
        if(memo[i][k][c] !== null) return memo[i][k][c];

        // recursive case: 
        let skip = solveRec(i+1, k, c);
        let take = NEG_INF;
        if(k > 0){
            if(c === 1){
                // normal transaction
                take = prices[i] + solveRec(i+1, k-1, 0);
            }else if(c === 2){
                // short sell, you have to buy later
                take = -prices[i] + solveRec(i+1, k-1, 0);
                
            }else{
                // fresh transaction: buy-sell or short sell-buy
                take = Math.max(
                    -prices[i] + solveRec(i+1, k, 1), // buy-sell (normal transaction)
                    prices[i] + solveRec(i+1, k, 2) // short sell-buy
                );
            }
        }

        memo[i][k][c] = Math.max(skip, take);
        return memo[i][k][c];
    };

    return solveRec(0, k, 0);
};

// const prices = [1,7,9,8,2], k = 2;

const prices = [12,16,19,19,8,1,19,13,9], k = 3;
console.log(maximumProfit(prices, k));