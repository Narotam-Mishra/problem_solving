
// Problem link - https://leetcode.com/problems/last-day-where-you-can-still-cross/description/

let latestDayToCross = function (row, col, cells) {
    const R = row, C = col;
    const directions = [
        [1, 0], [-1, 0], [0, 1], [0, -1]
    ];

    // DFS helper
    function canReachBottom(grid, i, j) {
        if (
            i < 0 || i >= R ||
            j < 0 || j >= C ||
            grid[i][j] === 1
        ) {
            return false;
        }

        // reached bottom row
        if (i === R - 1) return true;

        // mark visited
        grid[i][j] = 1;

        for (const [dx, dy] of directions) {
            if (canReachBottom(grid, i + dx, j + dy)) {
                return true;
            }
        }

        return false;
    }

    // check if crossing is possible on day m
    function canCross(m) {
        const grid = Array.from({ length: R }, () => Array(C).fill(0));

        // flood cells up to day m
        for (let i = 0; i <= m; i++) {
            const [x, y] = cells[i];
            grid[x - 1][y - 1] = 1;
        }

        // start DFS from top row
        for (let j = 0; j < C; j++) {
            if (grid[0][j] === 0 && canReachBottom(grid, 0, j)) {
                return true;
            }
        }

        return false;
    }

    // step 1 - perform binary search on cells over days
    let left = 0, right = cells.length - 1;
    let lastDay = 0;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);

        // step 2 - check if crossing is possible on day `mid`
        if (canCross(mid)) {
            lastDay = mid + 1;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // step 3 - return the last day where it is possible to walk
    return lastDay;
};

// const row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]];

// const row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]];

const row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]];
console.log(latestDayToCross(row, col, cells));