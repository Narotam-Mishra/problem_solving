
// Problem link - https://leetcode.com/problems/minimum-score-triangulation-of-polygon/?envType=daily-question&envId=2025-09-29

let minScoreTriangulation = function(values) {
    const n = values.length;

    // global dp for precomputed values
    const dp = Array.from({ length: n }, () => Array(n).fill(-1));

    // recursive solveRec function
    const solveRec = (i, j) => {
        // step 1 - base case : for triangle we need at least 3 points
        if (j - i + 1 < 3) {
            return 0;
        }

        // if answer is already calculated then return its value
        if (dp[i][j] !== -1) {
            return dp[i][j];
        }

        // store final result in `res`
        let res = Infinity;

        // step 2 - calculate weight for each triangle in `weight`
        for (let k = i + 1; k < j; k++) {
            // step 3 - recursively solve triangulation
            const weight = values[i] * values[j] * values[k] + solveRec(i, k) + solveRec(k, j);

            // step 4 - update minimum result
            res = Math.min(res, weight);
        }

        // step 5 - return final result `res`
        return dp[i][j] = res;
    };

    // solve recursively and return the value
    return solveRec(0, n - 1);
};

// const values = [1,2,3];

// const values = [3,7,4,5];

const values = [1,3,1,4,1,5];
console.log(minScoreTriangulation(values));