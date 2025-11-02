
// Problem link - https://leetcode.com/problems/count-unguarded-cells-in-the-grid/?envType=daily-question&envId=2025-11-02

let countUnguarded = function(m, n, guards, walls) {
    const grid = Array.from({ length: m }, () => new Array(n).fill(0));

    function markGuarded(r, c, grid){
        // up
        for (let i = r - 1; i >= 0; i--) {
            if (grid[i][c] == 2 || grid[i][c] == 3) {
                break;
            }

            // marking it as guarded
            grid[i][c] = 1;
        }

        // down
        for (let i = r + 1; i < grid.length; i++) {
            if (grid[i][c] == 2 || grid[i][c] == 3) {
                break;
            }

            // marking it as guarded
            grid[i][c] = 1;
        }

        // left
        for (let j = c - 1; j >= 0; j--) {
            if (grid[r][j] == 2 || grid[r][j] == 3) {
                break;
            }

            // marking it as guarded
            grid[r][j] = 1;
        }

        // right
        for (let j = c + 1; j < grid[0].length; j++) {
            if (grid[r][j] == 2 || grid[r][j] == 3) {
                break;
            }

            // marking it as guarded
            grid[r][j] = 1;
        }
    }

    // step 1 - mark guards position
    for (let guard of guards) {
        let i = guard[0];
        let j = guard[1];
        grid[i][j] = 2;
    }

    // step 2 - mark walls posiiton
    for (let wall of walls) {
        let i = wall[0];
        let j = wall[1];
        grid[i][j] = 3;
    }

    // step 3 - cells which can be guarded will be marked as `1`
    for (let guard of guards) {
        let i = guard[0];
        let j = guard[1];
        markGuarded(i, j, grid);
    }

    // step 4 - count unguareded cell
    let count = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 0) count++;
        }
    }

    // step 5 - return count of unguarded cells
    return count;
};

// const m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]];

const m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]];
console.log(countUnguarded(m, n, guards, walls));