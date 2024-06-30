
// Problem link - https://leetcode.com/problems/number-of-islands/description/

package Graph_problems;

import java.util.*;

public class NumberOfIslands {
    static final int[][] neighbourArr = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    private static void bfsTraversal(int i, int j, char[][] grid) {
        // using LinkedList as Queue to perform BFS
        Queue<int[]> qu = new LinkedList<>();

        // push the starting point (src) in queue
        qu.offer(new int[]{i, j});

        // mark this source cell(i,j) as visited by using '-'
        grid[i][j] = '-';

        // until queue is not empty, visit neighbour of current cell(i,j)
        while(!qu.isEmpty()){
            int[] curr = qu.poll();
            // traverse nearest neighbours
            for(int n=0; n<4; n++){
                int newNeighbourX = curr[0] + neighbourArr[n][0];
                int newNeighbourY = curr[1] + neighbourArr[n][1];

                // check boundary condition
                if (newNeighbourX < 0 || newNeighbourY < 0 || newNeighbourX >= grid.length || newNeighbourY >= grid[0].length) {
                    // We are outside of grid, so we will continue
                    continue;
                }

                if(grid[newNeighbourX][newNeighbourY] == '1'){
                    // it's an unvisited piece of land
                    grid[newNeighbourX][newNeighbourY] = '-';
                    // we will mark it as visited
                    qu.offer(new int[]{newNeighbourX, newNeighbourY});
                    // push new neighbour into queue
                }
            }
        }
    }

    public static int numIslands(char[][] grid) {
        int numOfIslands = 0;

        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[i].length; j++){
                if(grid[i][j] == '1'){
                    bfsTraversal(i, j, grid);
                    numOfIslands++;
                }
            }
        }
        return numOfIslands;
    }

    public static void main(String[] args) {
        // char[][] grid = {
        //     {'1', '1', '1', '1', '0'},
        //     {'1', '1', '0', '1', '0'},
        //     {'1', '1', '0', '0', '0'},
        //     {'0', '0', '0', '0', '0'}
        // };

        char[][] grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
        };
        System.out.println("Number of islands: " + numIslands(grid));
    }
}