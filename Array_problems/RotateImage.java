
// Problem link - https://leetcode.com/problems/rotate-image/description/?envType=daily-question&envId=2026-05-04

package Array_problems;

public class RotateImage {
    public void rotate(int[][] matrix) {
        int n = matrix.length;

        // step 1 - find transpose of matrix
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // step 2 - reverse each row of matrix
        for(int i=0; i<n; i++){
            int s = 0;
            int e = n - 1;

            while(s < e){
                int temp = matrix[i][s];
                matrix[i][s] = matrix[i][e];
                matrix[i][e] = temp;

                s++;
                e--;
            }
        }
    }

    public static void main(String[] args) {
        int[][] matrix = {{1,2,3},{4,5,6},{7,8,9}};
        RotateImage obj = new RotateImage();
        obj.rotate(matrix);

    }
}
