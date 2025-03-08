
// Problem link : https://leetcode.com/problems/valid-sudoku/description/

let isValidSudoku = function(board) {
    // step 1 - create three sets rows, columns and boxes
    let rows = new Array(9).fill(null).map(() => new Set());
    let columns = new Array(9).fill(null).map(() => new Set());
    let box = new Array(9).fill(null).map(() => new Set());

    // step 2 - traverse the 9*9 board
    for(let i=0; i<9; i++){
        for(let j=0; j<9; j++){
            let val = board[i][j];

            // ignore empty cells
            if(val === '.') continue;

            // step 3 - calculate box index
            let boxIndex = Math.floor(i/3) * 3 + Math.floor(j/3);

            // step 4 - check if val already exists in row, col or box
            if(rows[i].has(val)) return false;
            if(columns[j].has(val)) return false;
            if(box[boxIndex].has(val)) return false;

            // step 5 - insert value into sets
            rows[i].add(val);
            columns[j].add(val);
            box[boxIndex].add(val);
        }
    }

    //step 6 - if no duplicates found, return true
    return true; 
};

// const board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]];

const board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]];
console.log(isValidSudoku(board));
