
// Problem link - https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/?envType=daily-question&envId=2025-08-22

let minimumArea = function(grid) {
    // edge case: empty grid
    if(!grid || grid.length === 0 || grid[0].length === 0){
        return 0;
    }

    // find row and column length
    const rows = grid.length;
    const cols = grid[0].length;

    // step 1 - initialize boundaries values to impossible values
    // this will help to detect if we actually find any 1's
    let minRow = rows;   // start with maximum impossible high value
    let maxRow = -1;     // start with minimum impossible high value
    let minCol = cols;
    let maxCol = -1;

    // step 2 - process entire grid to find boundaries of all 1's
    for(let i=0; i<rows; i++){
        for(let j=0; j<cols; j++){
            if(grid[i][j] === 1){
                // update row boundaries
                minRow = Math.min(minRow, i);
                maxRow = Math.max(maxRow, i);

                // update column boundaries
                minCol = Math.min(minCol, j);
                maxCol = Math.max(maxCol, j);
            }
        }
    }

    // step 3 - handle edge case if no 1s found in grid
    if(maxRow === -1){
        // no rectangle needed if no 1's exist, so return 0
        return 0;
    }

    // step 4 - find width and height of rectangle
    const height = maxRow - minRow + 1;
    const width = maxCol - minCol + 1;

    // step 5 - calculate minimum area of rectangle and return
    return height * width;
};

// const grid = [[0,1,0],[1,0,1]];

const grid = [[1,0],[0,0]];
console.log(minimumArea(grid));