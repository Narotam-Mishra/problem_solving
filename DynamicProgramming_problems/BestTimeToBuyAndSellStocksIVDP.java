
// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

// Approach - using Top Down DP

package DynamicProgramming_problems;

public class BestTimeToBuyAndSellStocksIVDP {
    public static int[] pArr;
    public static int[][][] dp = new int[1005][105][2];

    private static int findMaxProfitTopDownDP(int i, int k, int ts){
        // Base case: all days are completed
        if(i == pArr.length) return 0;

        // if dp[i][k][ts] is already computed then return dp[i][k][ts]
        if(dp[i][k][ts] != -1) return dp[i][k][ts];

        int ans = Integer.MIN_VALUE;

        // Recursive case:
        // Case 1 : Ignore stock
        ans = Math.max(ans, findMaxProfitTopDownDP(i+1, k, ts));

        // Case 2 : Buy the stock on ith day
        if(k > 0 && ts == 0){
            ans = Math.max(ans, -pArr[i] + findMaxProfitTopDownDP(i+1, k, 1));
        }
        

        // Case 3 : sell the stock on ith day
        if(ts == 1){
            ans = Math.max(ans, pArr[i] + findMaxProfitTopDownDP(i+1, k-1, 0));
        }
        return dp[i][k][ts] = ans;
    }

    public static int maxProfit(int k, int[] prices) {
        pArr = prices;
        for(int i=0; i<1005; i++){
            for(int j=0; j<105; j++){
                for(int l=0; l<2; l++){
                    dp[i][j][l] = -1;
                }
            }
        }
        return findMaxProfitTopDownDP(0, k, 0);
    }

    public static void main(String[] args) {
        int k = 2;
        int[] prices = {3,2,6,5,0,3};
        System.out.println(maxProfit(k, prices));
    }
}
