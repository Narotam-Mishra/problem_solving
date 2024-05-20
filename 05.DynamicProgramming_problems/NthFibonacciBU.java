
// Problem link - https://www.codingninjas.com/studio/problems/nth-fibonacci-number_1115780

// Approach - Bottom Up DP

package DynamicProgramming_problems;

public class NthFibonacciBU {
    public static int[] dp;
    static int mod = 1000000007;

    public static int findFibBU(int n){
        dp = new int[n+1];

        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }

        return dp[n];
    }
    public static int fibonacciNumber(int n){
        return findFibBU(n);
    }

    public static void main(String[] args) {
        int n = 95;
        System.out.println(fibonacciNumber(n));
    }
}
