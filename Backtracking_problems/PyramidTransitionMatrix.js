
// Problem link - https://leetcode.com/problems/pyramid-transition-matrix/description/?envType=daily-question&envId=2025-12-29

/**
 * Pyramid Transition Matrix
 */

const memo = new Map();

function solveRec(curr, mp, idx, aboveStr) {
    const key = `${curr}_${idx}_${aboveStr}`;

    // Base case: reached the top
    if (curr.length === 1) {
        memo.set(key, true);
        return true;
    }

    // Memoization check
    if (memo.has(key)) {
        return memo.get(key);
    }

    // Finished building current level, move to next
    if (idx === curr.length - 1) {
        const res = solveRec(aboveStr, mp, 0, "");
        memo.set(key, res);
        return res;
    }

    const pair = curr.substring(idx, idx + 2);

    // No valid top block
    if (!mp.has(pair)) {
        memo.set(key, false);
        return false;
    }

    // Try all possible top blocks
    for (const ch of mp.get(pair)) {
        if (solveRec(curr, mp, idx + 1, aboveStr + ch)) {
            memo.set(key, true);
            return true;
        }
    }

    memo.set(key, false);
    return false;
}

let pyramidTransition = function(bottom, allowed) {
    const mp = new Map();

    // Build mapping: "AB" -> ["C", "D"]
    for (const pattern of allowed) {
        const key = pattern.substring(0, 2);
        const top = pattern[2];

        if (!mp.has(key)) mp.set(key, []);
        mp.get(key).push(top);
    }

    return solveRec(bottom, mp, 0, "");
}

// const bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"];

const bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"];
console.log(pyramidTransition(bottom, allowed));