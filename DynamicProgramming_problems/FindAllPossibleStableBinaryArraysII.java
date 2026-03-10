package DynamicProgramming_problems;

public class FindAllPossibleStableBinaryArraysII {
    public int numberOfStableArrays(int zero, int one, int limit) {
        final int mod = 1_000_000_007;
        int[][][] dp = new int[zero + 1][one + 1][2];

        for (int i = 1; i <= Math.min(zero, limit); i++)
            dp[i][0][0] = 1;

        for (int j = 1; j <= Math.min(one, limit); j++)
            dp[0][j][1] = 1;

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                if (i == 0 || j == 0)
                    continue;

                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % mod;
                if (j - 1 >= limit)
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j - 1 - limit][0] + mod) % mod;

                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
                if (i - 1 >= limit)
                    dp[i][j][0] = (dp[i][j][0] - dp[i - 1 - limit][j][1] + mod) % mod;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }

    public static void main(String[] args) {
        FindAllPossibleStableBinaryArraysII solution = new FindAllPossibleStableBinaryArraysII();
        
        // Test case 1: zero=1, one=1, limit=2
        int result1 = solution.numberOfStableArrays(1, 1, 2);
        System.out.println("Test 1: numberOfStableArrays(1, 1, 2) = " + result1);
        
        // Test case 2: zero=3, one=3, limit=2
        int result2 = solution.numberOfStableArrays(3, 3, 2);
        System.out.println("Test 2: numberOfStableArrays(3, 3, 2) = " + result2);
        
        // Test case 3: zero=2, one=2, limit=1
        int result3 = solution.numberOfStableArrays(2, 2, 1);
        System.out.println("Test 3: numberOfStableArrays(2, 2, 1) = " + result3);
    }
}
