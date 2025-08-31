
// Problem link - https://leetcode.com/problems/sudoku-solver/

package Backtracking_problems;

public class SudokuSolver {
    // utility function to find empty cells
    private static int[] findEmptyCells(char[][] board) {
        // scan board row by row from left to right
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                // found empty cell
                if (board[r][c] == '.') {
                    return new int[] { r, c };
                }
            }
        }

        // no empty cell found, board is complete
        return null;
    }

    // utility function to validate if placing a digit at given position violates
    // Sudoku rules
    private static boolean isValidPlacement(char[][] board, int row, int col, char num) {
        // three rules to be check valid placement
        // rule 1 - check if digit already exists in the same row
        for (int c = 0; c < 9; c++) {
            if (board[row][c] == num) {
                // digit already exist return false
                return false;
            }
        }

        // rule 2 - check if digit already exists in the same column
        for (int r = 0; r < 9; r++) {
            if (board[r][col] == num) {
                // digit already exist return false
                return false;
            }
        }

        // rule 3 - check if digit already exists in the same 3 * 3 subbox
        // calculate the starting position of the 3x3 box containing our cell
        int boxStartRow = (row / 3) * 3;
        int boxStartColumn = (col / 3) * 3;

        // check all 9 cells in 3*3 box
        for (int r = boxStartRow; r < boxStartRow + 3; r++) {
            for (int c = boxStartColumn; c < boxStartColumn + 3; c++) {
                if (board[r][c] == num) {
                    // digit already exist return false
                    return false;
                }
            }
        }

        // all checks passed - this placement is valid, so return true
        return true;
    }

    // recursive method to solve sudoku using backtracking
    private static boolean solveSudokuRecursive(char[][] board) {
        // step 1 - find empty cells
        int[] emptyCells = findEmptyCells(board);

        // base case : if no empty cells found, puzzle is completely solved
        if (emptyCells == null) {
            return true;
        }

        // extract row and column of empty cell
        int row = emptyCells[0];
        int col = emptyCells[1];

        // step 2 - try each digit from 1 to 9
        for (int num = 1; num <= 9; num++) {
            // change number to character
            char digit = (char) ('0' + num);

            // step 3 - check if current digit is valid in this position
            if (isValidPlacement(board, row, col, digit)) {
                // step 4 - place the digit (make a choice)
                board[row][col] = digit;

                // step 5 - recursively try to solve the rest of the puzzle
                if (solveSudokuRecursive(board)) {
                    return true;
                }

                // step 6 - backtrack, if recursive call failed then undo the choice
                board[row][col] = '.';
            }
        }

        // step 7 - if no digit (from 1 to 9) works in this cell, return false to
        // trigger backtracking
        return false;
    }

    public static void solveSudoku(char[][] board) {
        solveSudokuRecursive(board);
    }

    // helper method to print the board
    private static void printBoard(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        char[][] board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };
        
        System.out.println("Original board:");
        printBoard(board);
        
        solveSudoku(board);
        
        System.out.println("\nSolved board:");
        printBoard(board);
    }
}
