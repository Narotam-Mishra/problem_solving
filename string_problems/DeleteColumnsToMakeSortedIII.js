
// Problem link - https://leetcode.com/problems/delete-columns-to-make-sorted-iii/description/?envType=daily-question&envId=2025-12-22

let minDeletionSize = function(strs) {
    // get number of rows and columns
    const r = strs.length;         
    const c = strs[0].length;

    // dp[i] = LIS ending at column i
    const dp = new Array(c).fill(1);

    // keep track of length of LIS 
    let lis = 1;

    // step 1 - using LIS tecnique
    for (let i = 0; i < c; i++) {
        for (let j = 0; j < i; j++) {
            // flag to check if LIS condition hold true for all strings
            let isValid = true;

            // step 2 - validate column j → column i for all rows
            for (let k = 0; k < r; k++) {
                if (strs[k][j] > strs[k][i]) {
                    isValid = false;
                    break;
                }
            }

            // if valid, update dp[i]
            if (isValid) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }

        // step 3 - update LIS length
        lis = Math.max(lis, dp[i]);
    }

    // step 4 - return minimum deletions needed
    return c - lis;
};

// const strs = ["babca","bbazb"];

// const strs = ["edcba"];

const strs = ["ghi","def","abc"];
console.log(minDeletionSize(strs));
