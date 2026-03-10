
// Problem link - https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/?envType=daily-question&envId=2026-03-09

package DynamicProgramming_problems;

public class FindAllPossibleStableBinaryArraysI {
    private static final int MOD = 1_000_000_007;
    // memo[oneLeft][zeroLeft][lastWasOne]
    private int[][][] memo;
    private int limit;

    private int solveRec(int zeroLeft, int oneLeft, int lastWasOne) {
        // base case
        if (zeroLeft == 0 && oneLeft == 0) {
            return 1;
        }

        if (memo[oneLeft][zeroLeft][lastWasOne] != -1) {
            return memo[oneLeft][zeroLeft][lastWasOne];
        }

        long res = 0;
        if (lastWasOne == 1) {
            // last was 1 → we place zeros now
            int maxLen = Math.min(limit, zeroLeft);
            for (int len = 1; len <= maxLen; len++) {
                res += solveRec(zeroLeft - len, oneLeft, 0);
                if (res >= MOD) res -= MOD;
            }
        } else {
            // last was 0 → we place ones now
            int maxLen = Math.min(limit, oneLeft);
            for (int len = 1; len <= maxLen; len++) {
                res += solveRec(zeroLeft, oneLeft - len, 1);
                if (res >= MOD) res -= MOD;
            }
        }

        memo[oneLeft][zeroLeft][lastWasOne] = (int) res;
        return memo[oneLeft][zeroLeft][lastWasOne];
    }

    public int numberOfStableArrays(int zero, int one, int limit) {
        this.limit = limit;
        // constraints allow up to [200][200][2] like in C++
        memo = new int[one + 1][zero + 1][2];
        for (int i = 0; i <= one; i++) {
            for (int j = 0; j <= zero; j++) {
                memo[i][j][0] = -1;
                memo[i][j][1] = -1;
            }
        }

        int startWithOne = solveRec(zero, one, 0); // lastWasOne = false → 0
        int startWithZero = solveRec(zero, one, 1); // lastWasOne = true → 1

        long ans = startWithOne;
        ans += startWithZero;
        ans %= MOD;
        return (int) ans;
    }

    public static void main(String[] args) {
        FindAllPossibleStableBinaryArraysI solution = new FindAllPossibleStableBinaryArraysI();
        
        // int zero = 1, one = 1, limit = 2;

        // int zero = 1, one = 2, limit = 1;

        int zero = 3, one = 3, limit = 2;
        System.out.println(solution.numberOfStableArrays(zero, one, limit));  // Expected: 2
    }
}
