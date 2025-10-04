
// Problem link - https://leetcode.com/problems/trapping-rain-water-ii/?envType=daily-question&envId=2025-10-03

package Heaps_PriorityQueue_problems;

import java.util.*;

public class TrappingRainWaterII {
    // helper class to store height and co-ordinats
    static class Cell {
        int height, row, col;
        Cell(int height, int row, int col){
            this.height = height;
            this.row = row;
            this.col = col;
        }
    }

    public static int trapRainWater(int[][] heightMap) {
        // find size of row and column of heightMap grid
        int m = heightMap.length;
        int n = heightMap[0].length;

        // base case
        if(m < 3 || n < 3) return 0;

        // directions for 4-neighbors (up, down, left, right)
        int[][] directions = {{0,-1}, {0,1}, {-1,0}, {1,0}};

        // min-heap based on height
        PriorityQueue<Cell> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.height));

        // visited matrix to mark cell true once it is visted
        boolean[][] visited = new boolean[m][n];

        // step 1 - add left and right boundary cells
        for(int r=1; r<m-1; r++){
            pq.offer(new Cell(heightMap[r][0], r, 0));
            visited[r][0] = true;
            pq.offer(new Cell(heightMap[r][n-1], r, n-1));
            visited[r][n-1] = true;
        }

        // step 2 - add top and bottom most boundary cells also
        for(int c=0; c<n; c++){
            pq.offer(new Cell(heightMap[0][c], 0, c));
            visited[0][c] = true;
            pq.offer(new Cell(heightMap[m-1][c], m-1, c));
            visited[m-1][c] = true;
        }

        // step 3 - process from lowest boundary height
        int waterVolume = 0;
        while(!pq.isEmpty()){
            // extract height and its co-ordinates
            Cell cell = pq.poll();

            // step 4 - explore neighbours
            for(int[] dir : directions){
                int newRow = cell.row + dir[0];
                int newCol = cell.col + dir[1];

                // step 5 - skip boundary cells or already visited cells
                if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || visited[newRow][newCol]) continue;

                // step 6 - calculate trapped water
                waterVolume += Math.max(cell.height - heightMap[newRow][newCol], 0);

                // step 7 - push the updated neighbor into heap
                pq.offer(new Cell(Math.max(cell.height, heightMap[newRow][newCol]), newRow, newCol));

                // step 8 - mark the cell as visited
                visited[newRow][newCol] = true;
            }
        }

        // step 9 - return total trapped water
        return waterVolume;
    }

    public static void main(String[] args) {
        // int[][] heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};

        int[][] heightMap = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3}, {3,2,2,2,3}, {3,3,3,3,3}};

        System.out.println(trapRainWater(heightMap));
    }
}
