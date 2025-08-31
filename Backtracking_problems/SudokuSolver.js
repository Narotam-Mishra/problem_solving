
// Problem link - https://leetcode.com/problems/sudoku-solver/?envType=daily-question&envId=2025-08-31

// utility function to find empty cells
function findEmptyCells(board){
    // scan board row by row from left to right
    for(let r=0; r<9; r++){
        for(let c=0; c<9; c++){
            // found empty cell
            if(board[r][c] === '.'){
                return [r,c];
            }
        }
    }

    // no empty cell found, board is complete
    return null;
}

// utility function to validate if placing a digit at given position violates Sudoku rules
function isValidPlacement(board, row, col, num){
    // three rules to be check valid placement
    // rule 1 - check if digit already exists in the same row
    for(let c=0; c<9; c++){
        if(board[row][c] === num){
            // digit already exist return false
            return false;
        }
    }

    // rule 2 - check if digit already exists in the same column
    for(let r=0; r<9; r++){
        if(board[r][col] === num){
            // digit already exist return false
            return false;
        }
    }

    // rule 3 - check if digit already exists in the same 3 * 3 subbox
    // calculate the starting position of the 3x3 box containing our cell
    const boxStartRow = Math.floor(row/3) * 3;
    const boxStartColumn = Math.floor(col/3) * 3;

    // check all 9 cells in 3*3 box
    for(let r=boxStartRow; r<boxStartRow+3; r++){
        for(let c=boxStartColumn; c<boxStartColumn+3; c++){
            if(board[r][c] === num){
                // digit already exist return false
                return false;
            }
        }
    }

    // all checks passed - this placement is valid, so return true
    return true;
}

function solveSudokuRecursive(board) {
    // step 1 - find empty cells
    const emptyCell = findEmptyCells(board);

    // base case : if no empty cells found, puzzle is completely solved
    if(!emptyCell){
        return true;
    }
    // extract row and column of empty cell
    const [row, col] = emptyCell;

    // step 2 - try each digit from 1 to 9
    for(let num=1; num<=9; num++){
        // change number to character
        const digit = num.toString();

        // step 3 - check if current digit is valid in this position
        if(isValidPlacement(board, row, col, digit)){
            // step 4 - place the digit (make a choice)
            board[row][col] = digit;

            // step 5 - recursively try to solve the rest of the puzzle
            if(solveSudokuRecursive(board)){
                return true;
            }

            // step 6 - backtrack, if recursive call failed then undo the choice
            board[row][col] = '.';
        }
    }

    // step 7 - if no digit (from 1 to 9) works in this cell, return false to trigger backtracking
    return false;
};

let solveSudoku = function(board) {
    solveSudokuRecursive(board);
};

const board = [
  ["5", "3", ".", ".", "7", ".", ".", ".", "."],
  ["6", ".", ".", "1", "9", "5", ".", ".", "."],
  [".", "9", "8", ".", ".", ".", ".", "6", "."],
  ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
  ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
  ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
  [".", "6", ".", ".", ".", ".", "2", "8", "."],
  [".", ".", ".", "4", "1", "9", ".", ".", "5"],
  [".", ".", ".", ".", "8", ".", ".", "7", "9"],
];

console.log("Before Solving Puzzle:",board);
solveSudoku(board);
console.log("After Solving Puzzle:",board);