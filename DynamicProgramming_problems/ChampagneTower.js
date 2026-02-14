
// Problem link - https://leetcode.com/problems/champagne-tower/description/?envType=daily-question&envId=2026-02-14

let champagneTower = function(poured, query_row, query_glass) {
    // create memo array
    const memo = Array.from({ length: 101 }, () => Array(101).fill(-1));

    function solveRec(i, j) {

        // Invalid glass
        if (i < 0 || j < 0 || j > i) {
            return 0.0;
        }

        // Top glass
        if (i === 0 && j === 0) {
            return poured;
        }

        // Already computed
        if (memo[i][j] !== -1) {
            return memo[i][j];
        }

        // Overflow from left parent
        let leftUp = (solveRec(i - 1, j - 1) - 1) / 2.0;

        // Overflow from right parent
        let rightUp = (solveRec(i - 1, j) - 1) / 2.0;

        if (leftUp < 0) leftUp = 0.0;
        if (rightUp < 0) rightUp = 0.0;

        memo[i][j] = leftUp + rightUp;

        return memo[i][j];
    }

    return Math.min(1.0, solveRec(query_row, query_glass));
};

// const poured = 1, query_row = 1, query_glass = 1;

// const poured = 2, query_row = 1, query_glass = 1;

const poured = 100000009, query_row = 33, query_glass = 17;
console.log(champagneTower(poured, query_row, query_glass));