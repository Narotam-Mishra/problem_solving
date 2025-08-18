
// Problem link - https://leetcode.com/problems/delete-greatest-value-in-each-row/description/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class DeleteGreatestValueInEachRow {
    public static int deleteGreatestValue(int[][] grid) {
        // step 1 - sort each row in descending order
        for(int i=0; i<grid.length; i++){
            // defualt sorting in ascending order
            Arrays.sort(grid[i]);

            // reverse them to get descending order
            for(int l = 0, r = grid[i].length-1; l < r; l++, r--){
                int temp = grid[i][l];
                grid[i][l] = grid[i][r];
                grid[i][r] = temp;
            }
        }

        // step 2 - process each column
        int ans = 0;
        for(int j=0; j<grid[0].length; j++){
            int maxNum = 0;

            // step 3 - find maximum among all rows for this column
            for(int i=0; i<grid.length; i++){
                maxNum = Math.max(maxNum, grid[i][j]);
            }

            // step 4 - add the maximum of deleted elements to the answer
            ans += maxNum;
        }

        // step 5 - return answer, `ans`
        return ans;
    }

    public static void main(String[] args) {
        // int[][] grid = {{1,2,4}, {3,3,1}};

        int[][] grid = {{10}};
        System.out.println(deleteGreatestValue(grid));
    }
}