
// Problem link - https://www.codingninjas.com/studio/problems/friends-pairing-problem_1214625?leftPanelTabValue=PROBLEM

// Approach - Top Down BU (Tabulation)


package DynamicProgramming_problems;

public class FriendPairingBU {
    static final long mod = 1000000007;

    private static long friendPairing(int n){
        long[] dp = new long[n+1];

        if(n == 1 || n == 2) return n;
        
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3; i<=n; i++){
            dp[i] = (dp[i-1]%mod + ((i-1)%mod * dp[i-2]%mod)%mod)%mod;
        }
        return dp[n];
    }

    public static int numberOfWays(int n) {
        return (int)friendPairing(n);
    }
}
