
// Problem link - https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/?envType=daily-question&envId=2025-12-28

package Array_problems;

public class CountNegativeNumbersInSortedMatrix {
    public static int countNegatives(int[][] grid) {
        // find grid's row and column size
        int m = grid.length;
        int n = grid[0].length;

        // start from bottom-left of grid
        int row = m - 1, col = 0;

        // step 1 - traverse grid using staircase approach
        int negativeNumsCount = 0;
        while (row >= 0 && col < n) {
            // check if current element is non-neagtive,
            if (grid[row][col] >= 0) {
                // move right
                col++;
            } else {
                // if current number is negative, count negative numbers
                // all elements to the right are also negative
                negativeNumsCount += (n - col);
                // move to row above
                row--;
            }
        }

        // step 2 - return total count of negative numbers
        return negativeNumsCount;
    }

    public static void main(String[] args) {
        // int[][] grid = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};

        int[][] grid = {{3,2},{1,0}};
        System.out.println(countNegatives(grid));
    }
}
