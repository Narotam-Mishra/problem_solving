
// Problem link - https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/?envType=daily-question&envId=2025-08-20

package DynamicProgramming_problems;

public class CountSquareSubmatricesWithAllOnes {
    public static int countSquares(int[][] matrix) {
        // get length of row and column
        int m = matrix.length;
        int n = matrix[0].length;

        // step 1 - create dp array
        // dp[i][j] = side length of largest square submatrix ending at (i,j)
        int[][] dp = new int[m][n];

        // store total count of square submatrices with 1
        int totalCount = 0;

        // step 2 - process each cell of matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // step 3 - if current cell is 0, no square can end here
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                }

                // step 4 - tf we're at first row or first column, max square size is 1
                else if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                }

                // step 5 - for other cells with 1, we will use the recurrence relation
                // dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                else {
                    dp[i][j] = Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }

                // step 6 - add the number of squares ending at this position
                // if dp[i][j] = k, then there are k squares ending here: 1x1, 2x2, ..., kxk
                totalCount += dp[i][j];
            }
        }

        // step 7 - return total count of square submatrices with 1
        return totalCount;
    }

    public static void main(String[] args) {
        // int[][] matrix = {
        //     {0,1,1,1},
        //     {1,1,1,1},
        //     {0,1,1,1}
        // };

        int[][] matrix = {
            {1,0,1},
            {1,1,0},
            {1,1,0}
        };

        System.out.println(countSquares(matrix));
    }
}
