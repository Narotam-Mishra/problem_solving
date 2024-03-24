
// Problem link - https://www.codingninjas.com/studio/problems/nth-fibonacci-number_1115780

// Approach - Top Down DP

package DynamicProgramming_problems;

import java.util.Arrays;

/**
 * NthFibonacciNumber
 */
public class NthFibonacciNumber {
    public static int[] dp;
    static int mod = 1000000007;
    public static int findNthFibonacci(int n){
        // base case:
        if(n==0 || n==1) return n;

        // if nth fibonacci is already calculated then return it
        if(dp[n] != -1) return dp[n];

        // otherwise calculate it using recursion
        return dp[n] = (findNthFibonacci(n-1) + findNthFibonacci(n-2))%mod;

    }
    public static int fibonacciNumber(int n){
        dp = new int[100005];
        Arrays.fill(dp, -1);
        return findNthFibonacci(n);
    }

    public static void main(String[] args) {
        int n = 95;
        System.out.println(fibonacciNumber(n));
    }
}