
// Problem link - https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/?envType=daily-question&envId=2026-01-10

let minimumDeleteSum = function (s1, s2) {
    const m = s1.length;
    const n = s2.length;

    // memo[i][j] → min delete sum for s1[i..], s2[j..]
    const memo = Array.from({ length: m + 1 }, () =>
        Array(n + 1).fill(-1)
    );

    // utility recursive function 
    function solveRec(i, j) {
        // base case: both strings consumed
        if (i >= m && j >= n) {
            return 0;
        }

        // already computed
        if (memo[i][j] !== -1) {
            return memo[i][j];
        }

        // case 1 - s1 finished → delete remaining s2
        if (i >= m) {
            return s2.charCodeAt(j) + solveRec(i, j + 1);
        }

        // case 2 - s2 finished → delete remaining s1
        if (j >= n) {
            return s1.charCodeAt(i) + solveRec(i + 1, j);
        }

        // characters match → move both
        if (s1[i] === s2[j]) {
            return solveRec(i + 1, j + 1);
        }

        // option 1 - Delete from s1
        const delS1 = s1.charCodeAt(i) + solveRec(i + 1, j);

        // option 2 - Delete from s2
        const delS2 = s2.charCodeAt(j) + solveRec(i, j + 1);

        // memoize and return minimum
        return (memo[i][j] = Math.min(delS1, delS2));
    }

    // step 1 - solve recursively and return
    return solveRec(0, 0);
};

// const s1 = "sea", s2 = "eat";

const s1 = "delete", s2 = "leet";
console.log(minimumDeleteSum(s1, s2));
