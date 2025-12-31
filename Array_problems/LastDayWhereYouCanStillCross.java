
// Problem link - https://leetcode.com/problems/last-day-where-you-can-still-cross/

package Array_problems;

public class LastDayWhereYouCanStillCross {
    private static int R, C;

    // directions for moving up, down, left, right
    private static final int[][] directions = {{1,0},{-1,0},{0,1},{0,-1}};

    // utility method to perform DFS traversal
    private static boolean canReachBottomUsingDFS(int[][] grid, int i, int j){
        // out of bounds OR water cell OR already visited
        if(i < 0 || i >= R || j < 0 || j >= C || grid[i][j] == 1){
            return false;
        }

        // check if you have reached bottom row
        if(i == R-1){
            return true;
        }

        // mark grid as visited
        grid[i][j] = 1;

        // traverse all four possible directions
        for(int[] dir : directions){
            if(canReachBottomUsingDFS(grid, i + dir[0], j + dir[1])){
                return true;
            }
        }

        // return false as no condition satisfied
        return false;
    }

    // utility method to check crossing possibility on day m
    private static boolean canCross(int[][] cells, int m){
        int[][] grid = new int[R][C];

        // fill cells upto `m` days
        for(int i=0; i<=m; i++){
            // change 1-based indexing to 1
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;

            // fill water
            grid[x][y] = 1;
        }

        // try starting DFS from top row
        for(int j=0; j<C; j++){
            if(grid[0][j] == 0 && canReachBottomUsingDFS(grid, 0, j)){
                return true;
            }
        }

        // return false as not possible to cross
        return false;
    }

    public static int latestDayToCross(int row, int col, int[][] cells) {
        R = row;
        C = col;

        // store final result in `lastDay`
        int lastDay = 0;

        // step 1 - use binary search on grid over days
        int s = 0, e = cells.length-1;
        while(s <= e){
            int mid = s + (e - s)/2;

            // step 2 - check if crossing is possible on day `mid`
            if(canCross(cells, mid)){
                lastDay = mid + 1;
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }

        // step 3 - return the last day where it is possible to walk
        return lastDay;
    }

    public static void main(String[] args) {
        // int row = 2, col = 2;
        // int[][] cells = {{1,1},{2,1},{1,2},{2,2}};

        // int row = 2, col = 2;
        // int[][] cells = {{1,1},{1,2},{2,1},{2,2}};

        int row = 3, col = 3;
        int[][] cells = {{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}};

        System.out.println(latestDayToCross(row, col, cells));
    }
}
