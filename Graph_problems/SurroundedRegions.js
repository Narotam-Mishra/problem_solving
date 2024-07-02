
// Problem link - https://leetcode.com/problems/surrounded-regions/

function bfs_traversal(board, i, j){
  // find size of rows and columns
  const rows = board.length;
  const cols = board[0].length;

  // using array as queue
  const qu = [];
  // insert border cells(i,j) into queue
  qu.push([i, j]);
  // mark this cell to avoid revisiting
  board[i][j] = "M";

  // traverse queue to visit border's 0 one by one
  while (qu.length > 0) {
    // get front cell's cord from queue
    const [x, y] = qu.shift();

    // directions array to traverse neighbors
    const directions = [
      [x - 1, y], // up
      [x + 1, y], // down
      [x, y - 1], // left
      [x, y + 1], // right
    ];

    // traverse current cell's neighbors
    for (const [nx, ny] of directions) {
      // by check border conditions
      if (
        nx >= 0 &&
        ny >= 0 &&
        nx < rows &&
        ny < cols &&
        board[nx][ny] === "O"
      ) {
        // mark this cell to avoid revisiting
        board[nx][ny] = "M";
        // push neighbor's cell into queue
        qu.push([nx, ny]);
      }
    }
  }
}

let solve = function(board) {
    // cornor case:
    if(!board || board.length === 0) return;

    // find size of rows and columns
    const rows = board.length;
    const cols = board[0].length;

    // step1 : Mark all 'O's on the border and their connected 'O's
    for(let i=0; i<rows; i++){
        // left border cells
        if(board[i][0] === 'O') bfs_traversal(board, i, 0);
        // right border cells
        if(board[i][cols-1] === 'O') bfs_traversal(board, i, cols-1); 
    }

    for(let j=0; j<cols; j++){
        // top boarder cells
        if(board[0][j] === 'O') bfs_traversal(board, 0, j);
        // bottom boarder cells
        if(board[rows-1][j] === 'O') bfs_traversal(board, rows-1, j);
    }

    // step2 : convert all remaining (that are not border/edge) 'O's to 'X
    for(let i=0; i<rows; i++){
        for(let j=0; j<cols; j++){
            if(board[i][j] === 'O'){
                board[i][j] = 'X';
            }
        }
    }

    // step3: Convert all 'M's back to 'O's
    for(let i=0; i<rows; i++){
        for(let j=0; j<cols; j++){
            if(board[i][j] === 'M'){
                board[i][j] = 'O';
            }
        }
    }
};

const board = [
    ['X', 'X', 'X', 'X'],
    ['X', 'O', 'O', 'X'],
    ['X', 'X', 'O', 'X'],
    ['X', 'O', 'X', 'X']
];

solve(board);
console.log(board);