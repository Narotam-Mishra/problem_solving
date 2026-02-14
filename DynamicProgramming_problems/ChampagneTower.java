
// Problem link - https://leetcode.com/problems/champagne-tower/?envType=daily-question&envId=2026-02-14

package DynamicProgramming_problems;

public class ChampagneTower {
    // Memo table
    static double[][] memo = new double[101][101];

    // Recursive function
    public static double solveRec(int poured, int i, int j) {
        // base case1: Invalid glass
        if (i < 0 || j < 0 || j > i) {
            return 0.0;
        }

        // base case 2: Top glass
        if (i == 0 && j == 0) {
            return poured;
        }

        // already computed
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // overflow from left parent
        double leftUp = (solveRec(poured, i - 1, j - 1) - 1) / 2.0;

        // overflow from right parent
        double rightUp = (solveRec(poured, i - 1, j) - 1) / 2.0;

        if (leftUp < 0) leftUp = 0.0;
        if (rightUp < 0) rightUp = 0.0;

        return memo[i][j] = leftUp + rightUp;
    }

    public static double champagneTower(int poured, int query_row, int query_glass) {
        // initialize memo with -1
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                memo[i][j] = -1;
            }
        }

        // step 1 - solve recursilvely and return
        return Math.min(1.0, solveRec(poured, query_row, query_glass));
    }

    public static void main(String[] args) {
        // int poured = 1, query_row = 1, query_glass = 1;

        // int poured = 2, query_row = 1, query_glass = 1;

        int poured = 100000009, query_row = 33, query_glass = 17;
        System.out.println(champagneTower(poured, query_row, query_glass));
    }
}
