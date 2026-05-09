
// Problem link - https://leetcode.com/problems/cyclically-rotating-a-grid/description/?envType=daily-question&envId=2026-05-09

package Array_problems;

import java.util.*;

public class CyclicallyRotatingGrid {
    public int[][] rotateGrid(int[][] grid, int k) {
        // find number of rows and columns
        int m = grid.length;
        int n = grid[0].length;

        // step 1 - find number of layers to traverse
        int layers = Math.min(m / 2, n / 2);

        // step 2 - traverse each layer
        for (int l = 0; l < layers; l++) {
            // keep track of layer elements
            List<Integer> nums = new ArrayList<>();

            // step 3 - find top-bottom and left-right layer number
            int top = l;
            int bottom = m - l - 1;
            int left = l;
            int right = n - l - 1;

            // top row traversal (left to right)
            for (int j = left; j <= right; j++) {
                nums.add(grid[top][j]);
            }

            // top right column traversal (top+1 to bottom-1)
            for (int i = top + 1; i <= bottom - 1; i++) {
                nums.add(grid[i][right]);
            }

            // bottom row traversal (right to left)
            for (int j = right; j >= left; j--) {
                nums.add(grid[bottom][j]);
            }

            // bottom left column traversal (bottom-1 to top+1)
            for (int i = bottom - 1; i >= top + 1; i--) {
                nums.add(grid[i][left]);
            }

            // step 4 - rotate nums k-times
            int len = nums.size();
            int normalizedK = k % len;

            // step 5 - after rotation copy back numbers to grid
            int idx = normalizedK;

            // fill top row (left to right)
            for (int j = left; j <= right; j++) {
                grid[top][j] = nums.get(idx++ % len);
            }

            // fill top right column (top+1 to bottom-1)
            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = nums.get(idx++ % len);
            }

            // fill bottom row (right to left)
            for (int j = right; j >= left; j--) {
                grid[bottom][j] = nums.get(idx++ % len);
            }

            // fill bottom left column traversal (bottom-1 to top+1)
            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = nums.get(idx++ % len);
            }
        }

        // step 6 - return final rotated grid
        return grid;
    }

    public static void main(String[] args) {
        int[][] grid = {{40,10},{30,20}};
        int k = 1;
        CyclicallyRotatingGrid obj = new CyclicallyRotatingGrid();
        int[][] res = obj.rotateGrid(grid, k);
        System.out.println(Arrays.deepToString(res));
    }
}
