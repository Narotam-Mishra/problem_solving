
// Problem link - https://leetcode.com/problems/search-a-2d-matrix/description/

package binarySearch_problems;

public class Search2DMatrix {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int s = 0, e = m*n - 1;

        while(s <= e){
            int mid = s + (e-s)/2;
            int rowIdx = mid/n, colIdx = mid%n;
            if(target == matrix[rowIdx][colIdx]){
                return true;
            }else if(target > matrix[rowIdx][colIdx]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return false;
    }
}
