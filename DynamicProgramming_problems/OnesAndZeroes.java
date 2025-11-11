
// Problem link - https://leetcode.com/problems/ones-and-zeroes/description/?envType=daily-question&envId=2025-11-11

package DynamicProgramming_problems;

public class OnesAndZeroes {
    private static  int[][][] memo;

    private static  int solve(int[][] countPairs, int m, int n, int i) {
        // base case:
        if (i >= countPairs.length || (m == 0 && n == 0)) {
            return 0;
        }

        // if answer is already computed then return it
        if (memo[m][n][i] != -1) {
            return memo[m][n][i];
        }

        // two choices in recursion
        // option 1 - take 0s & 1s
        int take = 0;
        if (countPairs[i][0] <= m && countPairs[i][1] <= n) {
            take = 1 + solve(countPairs, m - countPairs[i][0],
                             n - countPairs[i][1], i + 1);
        }

        // option 2 - skip 0s and 1s
        int skip = solve(countPairs, m, n, i + 1);

        // memoize and return maximum of take and skip
        return memo[m][n][i] = Math.max(take, skip);
    }

    public static int findMaxForm(String[] strs, int m, int n) {
        int N = strs.length;

        // step 1 - find count of zeros and ones in 2D array
        int[][] countPairs = new int[N][2];
        for (int i = 0; i < N; i++) {
            int zeros = 0, ones = 0;

            for (char ch : strs[i].toCharArray()) {
                if (ch == '0') {
                    zeros++;
                } else {
                    ones++;
                }
            }
            
            countPairs[i][0] = zeros;
            countPairs[i][1] = ones;
        }

        // initialize values in memo with -1
        memo = new int[101][101][601];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= N; k++) {
                    memo[i][j][k] = -1;
                }
            }
        }

        // step 2 - solve the problem recursively and return result
        return solve(countPairs, m, n, 0);
    }

    public static void main(String[] args) {
        String[] strs = {"10","0001","111001","1","0"};
        int m = 5, n = 3;
        System.out.println(findMaxForm(strs, m, n));
    }
}
