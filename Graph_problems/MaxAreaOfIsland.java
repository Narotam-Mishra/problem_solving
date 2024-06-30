
// Problem link - https://leetcode.com/problems/max-area-of-island/

package Graph_problems;

import java.util.LinkedList;
import java.util.Queue;

public class MaxAreaOfIsland {
    static final int[][] neighbourArr = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    private static int bfsTraversal(int i, int j, int[][] grid) {
        // using LinkedList as Queue to perform BFS
        Queue<int[]> qu = new LinkedList<>();

        // push the starting point (src) in queue
        qu.offer(new int[]{i, j});

        // mark this source cell(i,j) as visited by using '-'
        grid[i][j] = -1;

        // every connected component of a size atleast 1
        int sizeOfCC = 1;

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

                if(grid[newNeighbourX][newNeighbourY] == 1){
                    // it's an unvisited piece of land
                    grid[newNeighbourX][newNeighbourY] = -1;
                    // we will mark it as visited
                    qu.offer(new int[]{newNeighbourX, newNeighbourY});
                    // push new neighbour into queue

                    //increment the size of connected component after each visit
                    sizeOfCC++;
                }
            }
        }

        // return size of connected component
        return sizeOfCC;
    }

    public static int maxAreaOfIsland(int[][] grid) {
        int numOfMaxCC = 0;
        for(int i=0; i<grid.length; i++){
            for(int j=0; j<grid[i].length; j++){
                if(grid[i][j] == 1){
                    numOfMaxCC = Math.max(numOfMaxCC, bfsTraversal(i, j, grid));
                }
            }
        }

        return numOfMaxCC;
    }

    public static void main(String[] args) {
        int[][] grid = {
            { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
            { 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0 , 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            { 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
        };
        System.out.println("Maximum area of Island: " + maxAreaOfIsland(grid));
    }
}
