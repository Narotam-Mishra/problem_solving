
// Problem link - https://leetcode.com/problems/magic-squares-in-grid/description/?envType=daily-question&envId=2025-12-30

let numMagicSquaresInside = function(grid) {
    function isMagicGrid(r, c) {
        const seen = new Set();

        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 3; j++) {
                let num = grid[r + i][c + j];
                if (num < 1 || num > 9 || seen.has(num)) {
                    return false;
                } else {
                    seen.add(num);
                }
            }
        }

        // find sum
        const Sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        // verify row, column and digonals sum
        for (let i = 0; i < 3; i++) {
            // verify row sum
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != Sum) {
                return false;
            }

            // verify column sum
            if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != Sum) {
                return false;
            }
        }

        // verify digonal sum
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != Sum) {
            return false;
        }

        // verify anti-digonal sum
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != Sum) {
            return false;
        }

        // all conditions holds correct, so return true
        return true;
    }

    // find count of rows and columns
    const rows = grid.length;
    const cols = grid[0].length;

    // step 1 - iterate on each 3*3 grid
    let count = 0;
    for (let i = 0; i <= rows - 3; i++) {
        for (let j = 0; j <= cols - 3; j++) {
            // step 2 - check if it is magic grid or not
            if (isMagicGrid(i, j)) {
                // increment count
                count++;
            }
        }
    }

    // step 3 - return count of magic grid
    return count;
};

// const grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]];

const grid = [[8]];
console.log(numMagicSquaresInside(grid));