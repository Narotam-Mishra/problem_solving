
// Problem link - https://leetcode.com/problems/sort-matrix-by-diagonals/?envType=daily-question&envId=2025-08-28

package Array_problems;

import java.util.*;

public class SortMatrixByDiagonals {
    private static void processDiagonals(int si, int sj, int[][] grid){
        int n = grid.length;
        int i = si, j = sj;

        // collect values along current diagonal
        List<Integer> vals = new ArrayList<>();
        while(i < n && j < n){
            vals.add(grid[i][j]);
            i++;
            j++;
        }

        // decice sorting order based on diagonal key diff = si - sj
        int diff = si - sj;
        if(diff >= 0){
            // bottom-left & main diagonal --> descending order sorting
            vals.sort(Collections.reverseOrder());
        }else{
            // top right --> ascending order sorting
            Collections.sort(vals);
        }

        // write sorted values back along diagonal
        i = si;
        j = sj;

        int index = 0;
        while(i < n && j < n){
            grid[i][j] = vals.get(index++);
            i++;
            j++;
        }
    }

    public static int[][] sortMatrix(int[][] grid) {
        // find size of grid
        int n = grid.length;

        // step 1 - first, diagonals starting from top row (0, col)
        for(int c=0; c<n; c++){
            // step 2 - process digonal along top right
            processDiagonals(0, c, grid);
        }

        // step 3 - then, diagonals starting from first column (row, 0),
        // skipping row 0 to avoid duplicate main diagonal
        for(int r=1; r<n; r++){
            // step 4 - process digonal along bottom-left
            processDiagonals(r, 0, grid);
        }

        // step 5 - return final diagonal sorted grid
        return grid;
    }

    public static void main(String[] args) {
        // int[][] grid = {{1,7,3},{9,8,2},{4,5,6}};

        // int[][] grid = {{0,1},{1,2}};

        int[][] grid = {{1}};
        int[][] res = sortMatrix(grid);
        System.out.println(Arrays.deepToString(res));
    }
}
