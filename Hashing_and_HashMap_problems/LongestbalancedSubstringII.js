
// Problem link - https://leetcode.com/problems/longest-balanced-substring-ii/description/?envType=daily-question&envId=2026-02-13

// helper function to find the longest balanced substring
// containing exactly 2 distinct characters: ch1 and ch2.
function solve(s, ch1, ch2) {
    const n = s.length;

    // diffMap stores the first occurrence index of each (cnt1 - cnt2) difference value.
    // Key insight: if the same difference appears at index i and later at index j,
    // then the substring s[i+1..j] has equal counts of ch1 and ch2.
    const diffMap = new Map();

    let maxLen = 0;
    let cnt1 = 0, cnt2 = 0;

    for (let i = 0; i < n; i++) {

        // If current character is neither ch1 nor ch2,
        // it acts as a wall — reset everything to start a fresh window.
        if (s[i] !== ch1 && s[i] !== ch2) {
            diffMap.clear();
            cnt1 = 0;
            cnt2 = 0;
            continue;
        }

        // Count occurrences of ch1 and ch2 so far in the current window.
        if (s[i] === ch1) cnt1++;
        if (s[i] === ch2) cnt2++;

        // If counts are equal, the entire current window (from start) is balanced.
        if (cnt1 === cnt2) {
            maxLen = Math.max(maxLen, cnt1 + cnt2);
        }

        // Use prefix difference trick:
        // diff = cnt1 - cnt2 captures the "imbalance" seen so far.
        // If this same diff was seen before at index k, then
        // between k+1 and i the counts of ch1 and ch2 are equal.
        const diff = cnt1 - cnt2;
        if (diffMap.has(diff)) {
            maxLen = Math.max(maxLen, i - diffMap.get(diff));
        } else {
            // Only store the first occurrence to maximize future window lengths.
            diffMap.set(diff, i);
        }
    }
    return maxLen;
}

function longestBalanced(s) {
    const n = s.length;
    let maxLen = 0;

    // -------------------------------------------------------
    // Case 1: Balanced substring using only 1 distinct character.
    // Any run of the same character is trivially balanced.
    // So just find the longest run of consecutive equal characters.
    // -------------------------------------------------------
    let cnt = 1; // s[0] starts a run of length 1
    for (let i = 1; i < n; i++) {
        if (s[i] === s[i - 1]) {
            cnt++;        // extend the current run
        } else {
            maxLen = Math.max(maxLen, cnt); // current run ended, record it
            cnt = 1;      // start a new run
        }
    }
    maxLen = Math.max(maxLen, cnt); // capture the last run

    // -------------------------------------------------------
    // Case 2: Balanced substring using exactly 2 distinct characters.
    // Try all 3 pairs. The third character acts as a barrier in solve().
    // -------------------------------------------------------
    maxLen = Math.max(maxLen, solve(s, 'a', 'b')); // 'c' is a wall
    maxLen = Math.max(maxLen, solve(s, 'a', 'c')); // 'b' is a wall
    maxLen = Math.max(maxLen, solve(s, 'b', 'c')); // 'a' is a wall

    // -------------------------------------------------------
    // Case 3: Balanced substring using all 3 distinct characters.
    // We need cntA == cntB == cntC across the substring.
    //
    // Key insight: track two differences simultaneously —
    //   diffAB = cntA - cntB
    //   diffAC = cntA - cntC
    // If both differences repeat at index k and index i,
    // then in the window (k, i]: cntA==cntB and cntA==cntC, so all three are equal.
    // We encode both diffs as a single string key for the map.
    // -------------------------------------------------------
    let cntA = 0, cntB = 0, cntC = 0;
    const diffMap = new Map();

    for (let i = 0; i < n; i++) {
        if (s[i] === 'a') cntA++;
        if (s[i] === 'b') cntB++;
        if (s[i] === 'c') cntC++;

        // If all three counts are equal, the entire prefix is balanced.
        if (cntA === cntB && cntA === cntC) {
            maxLen = Math.max(maxLen, cntA + cntB + cntC);
        }

        // Encode the current imbalance state as a composite key.
        const diffAB = cntA - cntB;
        const diffAC = cntA - cntC;
        const key = `${diffAB}_${diffAC}`;

        if (diffMap.has(key)) {
            // Same imbalance state seen before — window between is balanced.
            maxLen = Math.max(maxLen, i - diffMap.get(key));
        } else {
            // First time seeing this imbalance state — store it.
            diffMap.set(key, i);
        }
    }

    return maxLen;
}

// const s = "abbac";

// const s = "aabcc";

const s = "aba";
console.log(longestBalanced(s));