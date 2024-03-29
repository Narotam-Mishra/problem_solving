
// Problem link - https://leetcode.com/problems/coin-change/description/

package DynamicProgramming_problems;

public class CoinChangeBottomUp {
    public static int[] dp;
    public static int[] c;

    private static int coinChangeBU(int amtVal){
        dp = new int[amtVal+1];
        dp[0] = 0;

        for(int amount=1; amount<=amtVal; amount++){
            int ans = Integer.MAX_VALUE;
            int n = c.length;
            
            for(int i=0; i<n; i++){
                if(amount >= c[i]){
                    ans = Math.min(ans, dp[amount - c[i]]);
                }
            }

            // if ans is still infinity then coinChange is not possible
            if(ans == Integer.MAX_VALUE){
                dp[amount] = Integer.MAX_VALUE;
            }else{
                // ans + 1 --> here + 1 is for to react that way
                dp[amount] = 1 + ans;
            }
        }
        return dp[amtVal];
    }
    public static int coinChange(int[] coins, int amount) {
        c = coins;
        int minCoins = coinChangeBU(amount);
        return minCoins == Integer.MAX_VALUE ? -1 : minCoins;
    }

    public static void main(String[] args) {
        int[] coins = {1,2,5};
        int amount = 11;
        int ans = coinChange(coins, amount);
        System.out.println(ans);
    }
}
