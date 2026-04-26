package Graph_problems;

public class DetectCyclesIn2DGrid {
    int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;

    // utility function to check cycle using DFS
    public boolean dfsCycleCheck(int i, int j, int pi, int pj, char[][] grid, boolean[][] visited) {
        if (visited[i][j]) {
            return true;
        }

        visited[i][j] = true;

        for (int[] dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                grid[i][j] == grid[ni][nj]) {

                // skip parent cell
                if (ni == pi && nj == pj) continue;

                if (dfsCycleCheck(ni, nj, i, j, grid, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    public boolean containsCycle(char[][] grid) {
        m = grid.length;
        n = grid[0].length;

        boolean[][] visited = new boolean[m][n];

        // iterate through grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfsCycleCheck(i, j, -1, -1, grid, visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    public static void main(String[] args) {
        char[][] grid = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
        DetectCyclesIn2DGrid obj = new DetectCyclesIn2DGrid();
        System.out.println(obj.containsCycle(grid));
    }
}
