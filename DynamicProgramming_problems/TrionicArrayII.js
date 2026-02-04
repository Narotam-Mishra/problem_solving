
// Problem link - https://leetcode.com/problems/trionic-array-ii/description/?envType=daily-question&envId=2026-02-04

let maxSumTrionic = function(nums) {
    const n = nums.length;
    const NEG_INF = Number.MIN_SAFE_INTEGER;

    // memo[i][trend]
    const memo = Array.from({ length: n + 1 }, () =>
        Array(4).fill(null)
    );

    function solveRec(i, trend) {
        // base case
        if (i >= n) {
            return trend === 3 ? 0 : NEG_INF;
        }

        if (memo[i][trend] !== null) {
            return memo[i][trend];
        }

        let take = NEG_INF;
        let skip = NEG_INF;

        // option 1: skip only allowed in start state
        if (trend === 0) {
            skip = solveRec(i + 1, 0);
        }

        // option 2: take current element
        if (trend === 3) {
            take = nums[i];
        }

        if (i + 1 < n) {
            const curr = nums[i];
            const next = nums[i + 1];

            // trend 0 → trend 1
            if (trend === 0 && next > curr) {
                take = Math.max(take, curr + solveRec(i + 1, 1));
            }
            // trend 1 → trend 1 or 2
            else if (trend === 1) {
                if (next > curr) {
                    take = Math.max(take, curr + solveRec(i + 1, 1));
                } else if (next < curr) {
                    take = Math.max(take, curr + solveRec(i + 1, 2));
                }
            }
            // trend 2 → trend 2 or 3
            else if (trend === 2) {
                if (next < curr) {
                    take = Math.max(take, curr + solveRec(i + 1, 2));
                } else if (next > curr) {
                    take = Math.max(take, curr + solveRec(i + 1, 3));
                }
            }
            // trend 3 → trend 3 only
            else if (trend === 3 && next > curr) {
                take = Math.max(take, curr + solveRec(i + 1, 3));
            }
        }

        return memo[i][trend] = Math.max(take, skip);
    }

    return solveRec(0, 0);
};

// const nums = [0,-2,-1,-3,0,2,-1];

const nums = [1,4,2,7];
console.log(maxSumTrionic(nums));