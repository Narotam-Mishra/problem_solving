
// Problem link - https://leetcode.com/problems/count-number-of-trapezoids-i/description/?envType=daily-question&envId=2025-12-02

/**
 * Counts the number of trapezoids that can be formed from given points
 * @param {number[][]} points - Array of [x, y] coordinate pairs
 * @return {number} - Count of trapezoids modulo 10^9 + 7
 */
let countTrapezoids = function (points) {
    const mod = 1e9 + 7;

    // Step 1 - count horizontal lines
    const mp = new Map();
    for (const [x, y] of points) {
        mp.set(y, (mp.get(y) || 0) + 1);
    }

    // Step 2 - count trapezoids
    let res = 0n, prevHl = 0n;

    for (const count of mp.values()) {
        const c = BigInt(count);
        const hLines = (c * (c - 1n)) / 2n; // nC2

        res += hLines * prevHl;
        res %= BigInt(mod);

        prevHl += hLines;
        prevHl %= BigInt(mod);
    }

    return Number(res % BigInt(mod));
};

// const points = [[1,0],[2,0],[3,0],[2,2],[3,2]];

const points = [[0,0],[1,0],[0,1],[2,1]];
console.log(countTrapezoids(points));