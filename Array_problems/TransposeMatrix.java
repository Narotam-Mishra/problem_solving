
// Problem link - https://leetcode.com/problems/transpose-matrix/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class TransposeMatrix {
    public static int[][] transpose(int[][] matrix) {
        // find row `m` and column `n` length of matrix
        int m = matrix.length;
        int n = matrix[0].length;

        // step 1 - store result in `res` matrix
        int[][] res = new int[n][m];

        // step 2 - iterate on matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // step 3 - find transpose matrix, i.e, matrix[i][j] = matrix[j][i]
                res[j][i] = matrix[i][j];
            }
        }

        // step 4 - return resultant tranposed matrix `res`
        return res;
    }

    public static void main(String[] args) {
        int[][] matrix = {{1,2,3},{4,5,6},{7,8,9}};

        // int[][] matrix = {{1,2,3},{4,5,6}};
        int[][] res = transpose(matrix);
        System.out.println(Arrays.deepToString(res));
    }
}