
// Problem link - https://leetcode.com/problems/rotting-oranges/

package Graph_problems;

import java.util.*;

public class RottingOranges {
    private static final int[][] neighbourArr = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    private static int bfsTraversal(int[][] grid){
        // using LL as queue
        Queue<int[]> queue = new LinkedList<>();

        // find row and column size
        int m = grid.length;
        int n = grid[0].length;
        int res = 0;

        // add all initial rotten oranges to the queue
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    queue.add(new int[]{i, j, 0}); // {x, y, time}
                }
            }
        }

        // perform BFS traversal
        // till the time queue is empty
        while(!queue.isEmpty()){
            // get co-ordinates of the rotten orange
            int[] curr = queue.poll();
            int x = curr[0];
            int y = curr[1];
            // get time
            int time = curr[2];

            // traverse neighbour of current rotten orange
            for(int[] neighbour : neighbourArr){
                int nx = x + neighbour[0];
                int ny = y + neighbour[1];

                // check boundary condition for grid
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

                // we need to traverse within grid boundary
                if(grid[nx][ny] == 1){
                    // calculate result 'res'
                    res = Math.max(res, time + 1);

                    // mark as rotten
                    grid[nx][ny] = 2;

                    // add newly rotten orange to the queue
                    queue.add(new int[]{nx, ny, time+1});
                }
            }
        }

        // check if any fresh orange is left
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        // return result 'res'
        return res;
    }

    public static int orangesRotting(int[][] grid) {
        return bfsTraversal(grid);
    }

    public static void main(String[] args) {
        // int[][] grid = {{0, 2}};

        int[][] grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
        System.out.println(orangesRotting(grid));
    }
}