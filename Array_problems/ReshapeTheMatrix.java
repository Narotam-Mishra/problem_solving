package Array_problems;

import java.util.*;

public class ReshapeTheMatrix {
    public static int[][] matrixReshape(int[][] mat, int r, int c) {
        // find row and column size of input matrix `mat`
        int m = mat.length;
        int n = mat[0].length;

        // step 1 - check for edge case : if total element differ then reshap is not possible
        if(m * n != r * c){
            return mat;
        }

        // store final result in `reshaped` matrix
        int[][] reshaped = new int[r][c];

        // step 2 - fill the new `reshaped` matrix 
        // single linear pass over all elements (row-major order)
        for(int k=0; k<m*n; k++){
            // step 3 - calculate original position in matrix `mat`
            int originalRow = k / n;
            int originalColumn = k % n;

            // step 4 - find new position in reshaped matrix
            int newRow = k / c;
            int newColumn = k % c;

            // move the element
            reshaped[newRow][newColumn] = mat[originalRow][originalColumn];
        } 
        
        // step 5 - return reshaped matrix `reshaped`
        return reshaped;
    }

    public static void main(String[] args) {
        // int[][] mat = {{1,2},{3,4}}; 
        // int r = 1, c = 4;

        int[][] mat = {{1,2},{3,4}}; 
        int r = 2, c = 4;

        int[][] res = matrixReshape(mat, r, c);
        System.out.println(Arrays.deepToString(res));
    }
}
