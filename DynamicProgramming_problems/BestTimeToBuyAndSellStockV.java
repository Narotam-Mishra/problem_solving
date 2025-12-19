
// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/

package DynamicProgramming_problems;

public class BestTimeToBuyAndSellStockV {
    private static long[][][] memo;
    private static final long NEG_INF = -(long)1e18;

    public static long maximumProfit(int[] prices, int k) {
        int n = prices.length;

        memo = new long[n][k+1][3];
        for(int i=0; i<n; i++){
            for(int j=0; j<=k; j++){
                for(int c=0; c<=2; c++){
                    memo[i][j][c] = Long.MIN_VALUE;
                }
            }
        }

        // Case:
        // 0 - fresh transaction - you have not bought anything and you have not short-sold anything
        // 1 - Normal transaction - you have bought a stock and you need to sell it later
        // 2 - Short sell transaction - you have short-sold a stock and you need to buy it later

        return solveRec(0, k, 0, prices);
    }

    private static long solveRec(int i, int k, int c, int[] prices){
        // base case: no more transactions left or no more days left
        if(i >= prices.length){
            if(c == 0) return 0;

            // unfinished transaction: transaction is invalid
            return NEG_INF;
        }

        // memoization check
        if(memo[i][k][c] != Long.MIN_VALUE){
            return memo[i][k][c];
        }

        // recursive case: 
        long skip = solveRec(i+1, k, c, prices);
        long take = NEG_INF;
        if(k > 0){
            if(c == 1){
                // normal transaction
                take = prices[i] + solveRec(i+1, k-1, 0, prices);
            }else if(c == 2){
                // short sell, you have to buy later
                take = -prices[i] + solveRec(i+1, k-1, 0, prices);
                
            }else{
                // fresh transaction: buy-sell or short sell-buy
                take = Math.max(
                    -prices[i] + solveRec(i+1, k, 1, prices), // buy-sell (normal transaction)
                    prices[i] + solveRec(i+1, k, 2, prices) // short sell-buy
                );
            }
        }

        return memo[i][k][c] = Math.max(skip, take);
    }

    public static void main(String[] args) {
        // int[] prices = {1,7,9,8,2};
        // int k = 2;

        int[] prices = {12,16,19,19,8,1,19,13,9};
        int k = 3;
        System.out.println(maximumProfit(prices, k));
    }
}
