
// Problem link - https://leetcode.com/problems/coin-change/description/


package Recursion_problems;

public class CoinChangeRecursive {
    public static int[] c;

    public static int coinChangeRecursion(int amount){
        // Base case : when amount is negative or 0
        if(amount < 0) return Integer.MAX_VALUE;
        if(amount == 0) return 0;

        int ans = Integer.MAX_VALUE;
        int n = c.length;

        // Recursive case f(amount) = 1 + min(f(amount - coins[i]))
        for(int i=0; i<n; i++){
            if(amount >= c[i]){
                ans = Math.min(ans, coinChangeRecursion(amount - c[i]));
            }
        }

        // if ans is still infinity then coinChange is not possible
        if(ans == Integer.MAX_VALUE) return Integer.MAX_VALUE;

        // ans + 1 --> here + 1 is for to react that way
        return 1 + ans;
    }
    public static int coinChange(int[] coins, int amount) {
        c = coins;
        int minCoins = coinChangeRecursion(amount);
        return minCoins == Integer.MAX_VALUE ? -1 : minCoins;
    }

    public static void main(String[] args) {
        int[] coins = {1,2,5};
        int amount = 11;
        int ans = coinChange(coins, amount);
        System.out.println(ans);
    }
}