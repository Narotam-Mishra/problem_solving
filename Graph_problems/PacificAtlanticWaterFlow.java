
// Problem link - https://leetcode.com/problems/pacific-atlantic-water-flow/description/?envType=daily-question&envId=2025-10-05

package Graph_problems;

import java.util.*;

public class PacificAtlanticWaterFlow {
    // utility method to check for valid path
    private static boolean isValid(int x, int y, int r, int c){
        return x>=0 && y>=0 && x<r && y<c;
    }

    // utility method to perform Depth First Search (DFS)
    private static void dfs(int x, int y, int[][] heights, boolean[][] visited, int r, int c){
        // four directions: up, down, left, right
        int[][] directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        // mark this cell as reachable from the ocean we started from
        visited[x][y] = true;

        // explore all four neighbous
        for(int[] dirs : directions){
            int newX = x + dirs[0];
            int newY = y + dirs[1];

            // check for valid path
            // main condition: heights[newX][newY] >= heights[x][y]
            // we're going BACKWARDS from ocean to inland
            // water flows DOWN in reality, but we're searching UP from ocean
            // it means: "Can we climb UP from current cell to neighbor?"
            // if yes, then water can flow DOWN from neighbor to current cell to ocean
            if(isValid(newX, newY, r, c) && !visited[newX][newY] && heights[newX][newY] >= heights[x][y]){
                dfs(newX, newY, heights, visited, r, c);
            }
        }
    }

    public static List<List<Integer>> pacificAtlantic(int[][] heights) {
        // find row and column size of heights grid
        int r = heights.length;
        int c = heights[0].length;

        // track which cells can reach Pacific Ocean
        boolean[][] pacificVisited = new boolean[r][c];
        
        // track which cells can reach Atlantic Ocean
        boolean[][] atlanticVisited = new boolean[r][c];

        // step 1 - start DFS from all Pacific Ocean border cells (left and top edges)
        for(int i=0; i<r; i++){
            // left edge (Pacific)
            dfs(i, 0, heights, pacificVisited, r, c);

            // right edge (Atlantic)
            dfs(i, c-1, heights, atlanticVisited, r, c);
        }

        for(int j=0; j<c; j++){
            // top edge (Pacific)
            dfs(0, j, heights, pacificVisited, r, c);

            // bottom edge (Atlantic)
            dfs(r-1, j, heights, atlanticVisited, r, c);
        }

        // step 2 - find cells that can reach both oceans
        List<List<Integer>> res = new ArrayList<>();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                // step 3 - if reachable from both Pacific and Atlantic
                if(pacificVisited[i][j] && atlanticVisited[i][j]){
                    // step 4 - add its co-ordinates to result `res` list
                    res.add(Arrays.asList(i, j));
                }
            }
        }

        // step 5 - return result `res` list
        return res;
    }

    public static void main(String[] args) {
        int[][] heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};

        // int[][] heights = {{1}};
        List<List<Integer>> res = pacificAtlantic(heights);
        System.out.println(res);
    }
}
