
// Problem link - https://leetcode.com/problems/diagonal-traverse/description/?envType=daily-question&envId=2025-08-25

package Array_problems;

import java.util.*;

public class DiagonalTraverse {
    public static int[] findDiagonalOrder(int[][] mat) {
        // find row and column size
        int m = mat.length;
        int n = mat[0].length;

        // store final result in `res`
        int[] res = new int[m*n];
        // index for result array `res`
        int index = 0;

        // step 1 - traverse each digonal of matrix `mat`
        for(int ds=0; ds<m+n-1; ds++){
            List<Integer> currentDiagonal = new ArrayList<>();

            // step 2 - find all element in current diagonal where `i + j = diagonal sum (ds)`
            for(int i=0; i<m; i++){
                int j = ds - i;

                // step 3 - check calculated column index is valid 
                if(j<n && j>=0){
                    currentDiagonal.add(mat[i][j]);
                }
            }

            // step 4 - alternate the direction of traversal for each diagonal
            // odd diagonals (1, 3, 5...): traverse top-right to bottom-left
            // even diagonals (2, 4, 6...): traverse bottom-left to top-right
            if(ds % 2 == 0){
                Collections.reverse(currentDiagonal);
            }

            // step 5 - add diagonal elements to result `res`
            for(int num : currentDiagonal){
                res[index++] = num;
            }
        }

        // step 6 - return result `res`
        return res;
    }

    public static void main(String[] args) {
        // int[][] mat = {{1,2,3},{4,5,6},{7,8,9}};

        int[][] mat = {{1,2},{3,4}};
        int[] res = findDiagonalOrder(mat);
        System.out.println(Arrays.toString(res));
    }
}
