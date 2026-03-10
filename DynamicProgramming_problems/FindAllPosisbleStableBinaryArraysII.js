
// Problem link - https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/?envType=daily-question&envId=Invalid%20Date

/**
 * @param {number} zero
 * @param {number} one
 * @param {number} limit
 * @return {number}
 */
let numberOfStableArrays = function(zero, one, limit) {
    const mod = 1_000_000_007n;  // BigInt to avoid overflow

    const dp = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [0n, 0n])
    );

    for (let i = 1; i <= Math.min(zero, limit); i++)
        dp[i][0][0] = 1n;

    for (let j = 1; j <= Math.min(one, limit); j++)
        dp[0][j][1] = 1n;

    for (let i = 0; i <= zero; i++) {
        for (let j = 0; j <= one; j++) {
            if (i === 0 || j === 0) continue;

            dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % mod;
            if (j - 1 >= limit)
                dp[i][j][1] = (dp[i][j][1] - dp[i][j - 1 - limit][0] + mod) % mod;

            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
            if (i - 1 >= limit)
                dp[i][j][0] = (dp[i][j][0] - dp[i - 1 - limit][j][1] + mod) % mod;
        }
    }

    return Number((dp[zero][one][0] + dp[zero][one][1]) % mod);
}