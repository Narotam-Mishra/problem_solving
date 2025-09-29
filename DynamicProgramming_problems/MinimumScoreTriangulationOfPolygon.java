
// Problem link - https://leetcode.com/problems/minimum-score-triangulation-of-polygon/?envType=daily-question&envId=2025-09-29

package DynamicProgramming_problems;

import java.util.Arrays;

public class MinimumScoreTriangulationOfPolygon {
    // global dp for precomputed values
    static int[][] dp;

    // recursive helper method
    private static int solveRec(int[] values, int i, int j){
        // step 1 - base case : for triangle we need atleast 3 points
        if(j - i + 1 < 3){
            return 0;
        }

        // if answer is already calculated then return its value
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // store final result in `res`
        int res = Integer.MAX_VALUE;

        // step 2 - calculate weight for each triangle in `weight`
        for(int k=i+1; k<j; k++){
            // step 3 - recursively solve triangulation
            int weight = values[i] * values[j] * values[k] + solveRec(values, i, k) + solveRec(values, k, j);

            // step 4 - update minimum result `res`
            res = Math.min(res, weight);
        }

        // step 5 - return final result `res`
        return dp[i][j] = res;
    }

    public static int minScoreTriangulation(int[] values) {
        // find size of values
        int n = values.length;

        dp = new int[n+1][n+1];

        // initialize dp array to -1
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        // solve recursively and return the value
        return solveRec(values, 0, n-1);
    }

    public static void main(String[] args) {
        // int[] values = {1,2,3};

        // int[] values = {3,7,4,5};

        int[] values = {1,3,1,4,1,5};
        System.out.println(minScoreTriangulation(values));
    }
}
