
// Problem link - https://leetcode.com/problems/increment-submatrices-by-one/?envType=daily-question&envId=2025-11-14

package Array_problems;

import java.util.*;

public class IncrementSubmatricesByOne {
    public static  int[][] rangeAddQueries(int n, int[][] queries) {
        // intialize matrix `mat` to store final result
        int[][] mat = new int[n][n];

        // step 1 - process each query
        // each query is of the form [row1, col1, row2, col2].
        for(int[] query : queries){
            int row1 = query[0];
            int col1 = query[1];
            int row2 = query[2];
            int col2 = query[3];

            // step 2 - populate DAT
            for(int r=row1; r<=row2; r++){
                mat[r][col1] += 1;

                if(col2 + 1 < n){
                    mat[r][col2 + 1] -= 1;
                }
            }
        }

        // step 3 - find cummulative sum from `mat`
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                mat[i][j] += mat[i][j-1];
            }
        }

        // step 4 - return final result from `mat`
        return mat;
    }

    public static void main(String[] args) {
        // int n = 3;
        // int[][] queries = {{1,1,2,2},{0,0,1,1}};

        int n = 2;
        int[][] queries = {{0,0,1,1}};
        int[][] res = rangeAddQueries(n, queries);
        System.out.println(Arrays.deepToString(res));
    }
}
