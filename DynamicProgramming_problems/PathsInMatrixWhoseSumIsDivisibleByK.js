
// Problem link - https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/?envType=daily-question&envId=2025-11-26

const MOD = 1e9 + 7;
let memo;

function solve(r, c, currSum, k, grid, m, n) {
    // edge case:
    if (r >= m || c >= n) return 0;
    
    // base case:
    if (r === m - 1 && c === n - 1) {
        return (currSum + grid[m - 1][n - 1]) % k === 0 ? 1 : 0;
    }
    
    // if answer is already computed then return the answer
    if (memo[r][c][currSum] !== -1) {
        return memo[r][c][currSum] % MOD;
    }
    
    // recursive case: recursively move down and right respectively
    const down = solve(r + 1, c, (currSum + grid[r][c]) % k, k, grid, m, n);
    const right = solve(r, c + 1, (currSum + grid[r][c]) % k, k, grid, m, n);
    
    return memo[r][c][currSum] = (down + right) % MOD;
}

let numberOfPaths = function(grid, k) {
    // find rows and columns size of grid
    const m = grid.length;
    const n = grid[0].length;
    
    memo = Array.from({ length: m }, () =>
        Array.from({ length: n }, () =>
            Array(k).fill(-1)
        )
    );
    
    // step 1 - solve the problem recursively
    return solve(0, 0, 0, k, grid, m, n);
}

// const grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3;

const grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1;
console.log(numberOfPaths(grid, k));