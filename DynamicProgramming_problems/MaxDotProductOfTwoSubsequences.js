
// Problem link - https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/?envType=daily-question&envId=2026-01-08

let maxDotProduct = function (nums1, nums2) {
    const m = nums1.length;
    const n = nums2.length;

    // initialize memo table with -1e9
    const memo = Array.from({ length: 501 }, () =>
        Array(501).fill(-1e9)
    );

    // utility recursive function to solve
    function solveRec(i, j) {
        // base case: if either array is exhausted,
        // return a very small number
        if (i === m || j === n) {
            return -1e9;
        }

        // if already computed, return it
        if (memo[i][j] !== -1e9) {
            return memo[i][j];
        }

        // value of taking only current pair
        const val = nums1[i] * nums2[j];

        // take both current elements
        const takeBoth = val + solveRec(i + 1, j + 1);

        // skip element from nums2
        const skipJ = solveRec(i, j + 1);

        // skip element from nums1
        const skipI = solveRec(i + 1, j);

        // store and return the maximum
        memo[i][j] = Math.max(val, takeBoth, skipJ, skipI);

        return memo[i][j];
    }

    // step 1 - start recursion from (0, 0)
    return solveRec(0, 0);
};

// const nums1 = [2,1,-2,5], nums2 = [3,0,-6];

// const nums1 = [3,-2], nums2 = [2,-6,7];

const nums1 = [-1,-1], nums2 = [1,1];
console.log(maxDotProduct(nums1, nums2));