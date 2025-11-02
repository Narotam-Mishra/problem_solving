
// Problem link - https://leetcode.com/problems/count-unguarded-cells-in-the-grid/?envType=daily-question&envId=2025-11-02

package Array_problems;

public class CountUnguardedCellsInGrid {
    // utility function to mark cells guarded
    private static void markGaurded(int r, int c, int[][] grid) {
        // up
        for (int i = r - 1; i >= 0; i--) {
            if (grid[i][c] == 2 || grid[i][c] == 3) {
                break;
            }

            // marking it as guarded
            grid[i][c] = 1;
        }

        // down
        for (int i = r + 1; i < grid.length; i++) {
            if (grid[i][c] == 2 || grid[i][c] == 3) {
                break;
            }

            // marking it as guarded
            grid[i][c] = 1;
        }

        // left
        for (int j = c - 1; j >= 0; j--) {
            if (grid[r][j] == 2 || grid[r][j] == 3) {
                break;
            }

            // marking it as guarded
            grid[r][j] = 1;
        }

        // right
        for (int j = c + 1; j < grid[0].length; j++) {
            if (grid[r][j] == 2 || grid[r][j] == 3) {
                break;
            }

            // marking it as guarded
            grid[r][j] = 1;
        }
    }

    public static int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] grid = new int[m][n];

        // step 1 - mark guards position
        for (int[] guard : guards) {
            int i = guard[0];
            int j = guard[1];
            grid[i][j] = 2;
        }

        // step 2 - mark walls posiiton
        for (int[] wall : walls) {
            int i = wall[0];
            int j = wall[1];
            grid[i][j] = 3;
        }

        // step 3 - cells which can be guarded will be marked as `1`
        for (int[] guard : guards) {
            int i = guard[0];
            int j = guard[1];
            markGaurded(i, j, grid);
        }

        // step 4 - count unguareded cell
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    count++;
            }
        }

        // step 5 - return count of unguarded cells
        return count;
    }
    
    public static void main(String[] args) {
        // int m = 4, n = 6;
        // int[][] guards = {{0,0},{1,1},{2,3}}, walls = {{0,1},{2,2},{1,4}};

        int m = 3, n = 3;
        int[][] guards = {{1,1}}, walls = {{0,1},{1,0},{2,1},{1,2}};
        System.out.println(countUnguarded(m, n, guards, walls));
    }
}