
// Problem link : https://leetcode.com/problems/climbing-stairs/

package DynamicProgramming_problems;


public class ClimbingStairs {
    public static int[] dp;
    private static int helper(int n){
        // base case:
        if(n == 1 || n == 2) return n;

        // if value is already computed then return
        if(dp[n] != 0) return dp[n];

        // recursively calculate and store result into dp array
        dp[n] = helper(n - 1) + helper(n - 2);
        return dp[n];
    }
    public static int climbStairs(int n) {
        dp = new int[51];
        return helper(n);
    }
    
    public static void main(String[] args) {
        int n = 3;
        System.out.println(climbStairs(n));
    }
}