
// Problem link - https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/?envType=daily-question&envId=2025-12-28

let countNegatives = function(grid) {
    // find grid's row and column size
    const m = grid.length;
    const n = grid[0].length;

    // start from grid's bottom right
    let row = m-1, col = 0;

    // step 1 - iterate on grid using staircase approach
    let negativeNumsCount = 0;
    while(row >= 0 && col < n){
        // check if current element is non-neagtive,
        if(grid[row][col] >= 0){
            // move right
            col++;
        }else{
            // if current number is negative, count negative numbers
            // all elements to the right are also negative
            negativeNumsCount += (n - col);
            row--;
        }
    }

    // step 2 - return count of negative numbers in grid
    return negativeNumsCount;
};

// const grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]];

const grid = [[3,2],[1,0]];
console.log(countNegatives(grid));