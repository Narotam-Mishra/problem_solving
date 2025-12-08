
// Problem link - https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/

let countPartitions = function(nums, k) {
    const n = nums.length;
    const MOD = 1_000_000_007;

    const dp = Array(n + 1).fill(0);
    const pref = Array(n + 1).fill(0);

    dp[0] = 1;
    pref[0] = 1;

    let minDeq = [];
    let maxDeq = [];

    let i = 0;

    for (let j = 0; j < n; j++) {

        // maintain max deque
        while (maxDeq.length > 0 && nums[j] > nums[maxDeq[maxDeq.length - 1]]) {
            maxDeq.pop();
        }
        maxDeq.push(j);

        // maintain min deque
        while (minDeq.length > 0 && nums[j] < nums[minDeq[minDeq.length - 1]]) {
            minDeq.pop();
        }
        minDeq.push(j);

        // shrink window
        while (i <= j && nums[maxDeq[0]] - nums[minDeq[0]] > k) {
            i++;

            if (maxDeq.length > 0 && maxDeq[0] < i)
                maxDeq.shift();

            if (minDeq.length > 0 && minDeq[0] < i)
                minDeq.shift();
        }

        const left = pref[j];
        const right = i > 0 ? pref[i - 1] : 0;

        dp[j + 1] = (left - right + MOD) % MOD;

        pref[j + 1] = (pref[j] + dp[j + 1]) % MOD;
    }

    return dp[n];
};
