
// Problem link - https://leetcode.com/problems/surrounded-regions/

package Graph_problems;

import java.util.*;

public class SurroundedRegions {

    // helper method to perfrom BFS
    private static void bfsHelper(char[][] board, int i, int j){
        // find size of rows and columns
        int rows = board.length;
        int cols = board[0].length;

        // using queue to perform BFS
        Queue<int[]> queue = new LinkedList<>();
        // insert border cells(i,j) into queue
        queue.offer(new int[]{i, j});
        // mark this cell to avoid revisiting
        board[i][j] = 'M';

        // directions array to traverse neighbors
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right

        // traverse queue to visit border's 0 one by one
        while(!queue.isEmpty()){
            // get front cell's cord from queue
            int[] cell = queue.poll();

            // traverse current cell's neighbors
            for(int[] dir : directions){
                int nx = cell[0] + dir[0];
                int ny = cell[1] + dir[1];

                // by check border conditions
                if(nx >= 0 && ny >= 0 && nx < rows && ny < cols && board[nx][ny] == 'O'){
                    // mark this cell to avoid revisiting
                    board[nx][ny] = 'M';

                    // push neighbor's cell into queue
                    queue.offer(new int[]{nx, ny});
                }
            }
        }
    }

    public static void solve(char[][] board) {
        // cornor case:
        if(board == null || board.length == 0) return;

        // find size of rows and columns
        int rows = board.length;
        int cols = board[0].length;

        // step1 : Mark all 'O's on the border and their connected 'O's
        for(int i=0; i<rows; i++){
            // left border cells
            if(board[i][0] == 'O') bfsHelper(board, i, 0);

            // right border cells
            if(board[i][cols-1] == 'O') bfsHelper(board, i, cols-1);
        }

        for(int j=0; j<cols; j++){
            // top border cells
            if(board[0][j] == 'O') bfsHelper(board, 0, j);

            // bottom border cells
            if(board[rows-1][j] == 'O') bfsHelper(board, rows-1, j);
        }

        // step2 : convert all remaining (that are not border/edge) 'O's to 'X
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        // step3: Convert all 'M's back to 'O's
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'M') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    public static void main(String[] args) {
        char[][] board = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'}
        };
        solve(board);
        
        // print board
        for(char[] row : board){
            System.out.println(Arrays.toString(row));
        }
    }
}