
// Problem link - https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/?envType=daily-question&envId=2026-04-02

/**
 * @param {number[][]} coins
 * @return {number}
 */
let maximumAmount = function(coins) {
    const m = coins.length;
    const n = coins[0].length;
    const UNVISITED = -Infinity;
    
    // Initialize 3D memo array
    const memo = Array.from({length: m}, () =>
        Array.from({length: n}, () =>
            new Array(3).fill(UNVISITED)
        )
    );

    function solveRec(i, j, np) {
        // base case 1 - out of bounds
        if (i >= m || j >= n) return -Infinity;

        // base case 2 - reached destination
        if (i === m - 1 && j === n - 1) {
            if (coins[i][j] < 0 && np > 0) return 0;
            return coins[i][j];
        }

        // return cached result
        if (memo[i][j][np] !== UNVISITED) return memo[i][j][np];

        // case 1 - take current coins
        const best = Math.max(solveRec(i+1, j, np), solveRec(i, j+1, np));
        const take = (best === -Infinity) ? -Infinity : coins[i][j] + best;

        // case 2 - skip current cell (neutralise robber)
        let skip = -Infinity;
        if (coins[i][j] < 0 && np > 0) {
            const skipDown = solveRec(i+1, j, np-1);
            const skipRight = solveRec(i, j+1, np-1);
            skip = Math.max(skipDown, skipRight);
        }

        memo[i][j][np] = Math.max(take, skip);
        return memo[i][j][np];
    }

    return solveRec(0, 0, 2);
};

// Test
// const coins = [[0,1,-1],[1,-2,3],[2,-3,4]];

const coins = [[10,10,10],[10,10,10]];
console.log(maximumAmount(coins));