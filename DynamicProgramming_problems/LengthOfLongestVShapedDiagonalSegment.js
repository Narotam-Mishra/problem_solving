
// Problem link - https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/?envType=daily-question&envId=2025-08-27

let lenOfVDiagonal = function(grid) {
    // find column and row size
    const m = grid.length;
    const n = grid[0].length;

    // directions: [↘, ↙, ↖, ↗]
    const directions = [
        [1, 1],
        [1, -1],
        [-1, -1],
        [-1, 1],
    ];

    // recursively explore all possible path
    function solveRec(i, j, d, canTurn, val) {
        // calculate new position based on current direction
        const newI = i + directions[d][0];
        const newJ = j + directions[d][1];

        // boundary or mismatch check
        // if out of bounds OR value doesn't match expected alternating pattern
        if (newI < 0 || newI >= m || newJ < 0 || newJ >= n || grid[newI][newJ] !== val) {
            return 0;
        }
        
        let ans = 0;

        // case 1: keep moving same direction
        const keepMoving = 1 + solveRec(newI, newJ, d, canTurn, val === 2 ? 0 : 2);
        ans = Math.max(ans, keepMoving);

        // case 2: try clockwise turn if possible
        if (canTurn) {
            // calculate new direction: clockwise turn means (d + 1) % 4
            const newDirection = (d + 1) % 4;

            // try turning: move to new position, new direction, can't turn again
            const turnAndMove = 1 + solveRec(newI, newJ, newDirection, false, val === 2 ? 0 : 2);
            ans = Math.max(ans, turnAndMove);
        }

        return ans;
    }

    // store longest V shape length in `maxVLen`
    let maxVLen = 0;

    // step 2 - try every cell as potential starting point
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            // V-diagonal must start with value 1
            if (grid[i][j] === 1) {
                // step 3 - try all 4 diagonal directions as initial direction
                for (let d = 0; d <= 3; d++) {
                    // step 4 - start recursion : 1 (current cell) + maximum extension
                    maxVLen = Math.max(maxVLen, 1 + solveRec(i, j, d, true, 2, grid));
                }
            }
        }
    }

    // step 5 - return longest V-Shape length
    return maxVLen;
};

// const grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]];

// const grid = [[1,2,2,2,2],[2,2,2,2,0],[2,0,0,0,0],[0,0,2,2,2],[2,0,0,2,0]];

const grid = [[2,2,2,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]];
console.log(lenOfVDiagonal(grid));