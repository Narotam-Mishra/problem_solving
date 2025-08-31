
// Problem link - https://leetcode.com/problems/sudoku-solver/

#include<bits/stdc++.h>
using namespace std;

// utility function to find empty cells
bool findEmptyCells(vector<vector<char>>& board, int& row, int& col) {
    // scan board row by row from left to right
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            // found empty cell
            if (board[r][c] == '.') {
                row = r;
                col = c;
                return true;
            }
        }
    }

    // no empty cell found, board is complete
    return false;
}

// utility function to validate if placing a digit at given position violates Sudoku rules
bool isValidPlacement(vector<vector<char>>& board, int row, int col, char num) {
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

bool solveSudokuRecursive(vector<vector<char>>& board) {
    // step 1 - find empty cells
    int row, col;

    // base case : if no empty cells found, puzzle is completely solved
    if (!findEmptyCells(board, row, col)) {
        return true;
    }

    // step 2 - try each digit from 1 to 9
    for (int num = 1; num <= 9; num++) {
        // change number to character
        char digit = (char)('0' + num);

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

void solveSudoku(vector<vector<char>>& board) {
    solveSudokuRecursive(board);
}

void print2DVector(vector<vector<char>>& matrix){
    cout << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < matrix.size() - 1) cout << ",";
    }
    cout << "]" << std::endl;
}

int main(){
    vector<vector<char>> board = {
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

    cout << "Original board:" << endl;
    print2DVector(board);

    solveSudoku(board);

    cout << "\nSolved board:" << endl;
    print2DVector(board);

    return 0;
}