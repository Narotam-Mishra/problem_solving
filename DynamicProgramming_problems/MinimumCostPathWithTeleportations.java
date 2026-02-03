
// Problem link - https://leetcode.com/problems/minimum-cost-path-with-teleportations/description/

package DynamicProgramming_problems;

import java.util.*;

public class MinimumCostPathWithTeleportations {
    public static int minCost(int[][] grid, int k) {
        // step 1 - initialize grid dimensions
        int m1 = grid.length;
        int n1 = grid[0].length;

        // step 2 - create DP table with Integer.MAX_VALUE, set destination cost to 0
        int[][] dp = new int[m1][n1];
        for (int i = 0; i < m1; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        dp[m1 - 1][n1 - 1] = 0;

        // step 3 - find maximum grid value to size teleportCost array
        int maxVal = 0;
        for (int[] row : grid) {
            for (int val : row) {
                maxVal = Math.max(maxVal, val);
            }
        }

        // step 4 - track minimum cost to reach any cell with each value
        int[] teleportCost = new int[maxVal + 1];
        Arrays.fill(teleportCost, Integer.MAX_VALUE);

        // step 5 - iterate k times to explore k teleportation options
        for (int t = 0; t <= k; t++) {

            // step 5a - fill DP table bottom-right to top-left
            for (int i = m1 - 1; i >= 0; i--) {
                for (int j = n1 - 1; j >= 0; j--) {

                    // move down cost
                    if (i + 1 < m1 && dp[i + 1][j] != Integer.MAX_VALUE) {
                        dp[i][j] = Math.min(
                            dp[i][j],
                            grid[i + 1][j] + dp[i + 1][j]
                        );
                    }

                    // move right cost
                    if (j + 1 < n1 && dp[i][j + 1] != Integer.MAX_VALUE) {
                        dp[i][j] = Math.min(
                            dp[i][j],
                            grid[i][j + 1] + dp[i][j + 1]
                        );
                    }

                    // teleport to any cell with value <= current value
                    if (t > 0) {
                        dp[i][j] = Math.min(
                            dp[i][j],
                            teleportCost[grid[i][j]]
                        );
                    }
                }
            }

            // step 5b - update teleportCost for each grid value
            for (int i = 0; i < m1; i++) {
                for (int j = 0; j < n1; j++) {
                    teleportCost[grid[i][j]] =
                        Math.min(teleportCost[grid[i][j]], dp[i][j]);
                }
            }

            // step 5c - propagate costs (prefix minimum)
            for (int i = 1; i < teleportCost.length; i++) {
                teleportCost[i] =
                    Math.min(teleportCost[i], teleportCost[i - 1]);
            }
        }

        // step 6 - return minimum cost from start to destination
        return dp[0][0];
    }

    public static void main(String[] args) {
        // int[][] grid = {{1,3,3},{2,5,4},{4,3,5}};
        // int k = 2;

        int[][] grid = {{1,2},{2,3},{3,4}};
        int k = 1;
        System.out.println(minCost(grid, k));
    }
}
