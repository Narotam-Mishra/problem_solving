
// Problem link - https://www.codingninjas.com/studio/problems/friends-pairing-problem_1214625?leftPanelTabValue=PROBLEM

// Approach - Top Down DP (Memoization)

package DynamicProgramming_problems;

import java.util.Arrays;

public class FriendPairing {
    static int mod = 1000000007;
    public static long[] dp;

    private static long friendPairing(int n){
        if(n == 0 || n == 1 || n == 2) return n;

        // if dp[n] is already calculated then return dp[n];
        if(dp[n] != -1) return dp[n];

        // otherwise calculate dp[n] using recurrence
        long singleWay = friendPairing(n-1)%mod;
        long pairedWay = ((n-1)%mod * friendPairing(n-2)%mod)%mod ;

        return dp[n] = (singleWay%mod + pairedWay%mod)%mod;

    }
    public static int numberOfWays(int n) {
        dp = new long[n+1];
        Arrays.fill(dp, -1);
        return (int)friendPairing(n);
    }

    public static void main(String[] args) {
        int n = 4;
        System.out.println(numberOfWays(n));
    }
}
