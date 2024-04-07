
// Problem link - https://leetcode.com/problems/n-th-tribonacci-number/description/

package DynamicProgramming_problems;

import java.util.Arrays;

public class NthTribonacciNumberTopDownDP {
    public static int[] dp;
    private static int findNthTribonacciNumberTopDownDP(int n){
        // Base case:
        if(n == 0) return 0;
        else if(n == 1 || n == 2) return 1;

        // if dp[n] is already calculated then return dp[n]
        if(dp[n] != -1) return dp[n];

        return dp[n] = findNthTribonacciNumberTopDownDP(n-1) + findNthTribonacciNumberTopDownDP(n-2) + findNthTribonacciNumberTopDownDP(n-3);
    }
    public static int tribonacci(int n) {
        dp = new int[n+1];
        Arrays.fill(dp, -1);
        return findNthTribonacciNumberTopDownDP(n);
    }

    public static void main(String[] args) {
        int num = 25;
        System.out.println(tribonacci(num));
    }
}