
// Problem link - https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-11-21

let countPalindromicSubsequence = function (s) {
    const n = s.length;

    // Step 1: first & last occurrence for each character
    const indices = Array.from({ length: 26 }, () => [-1, -1]);

    for (let i = 0; i < n; i++) {
        const c = s.charCodeAt(i) - 97; // 'a' = 97
        if (indices[c][0] === -1) {
            indices[c][0] = i;
        }
        indices[c][1] = i;
    }

    let res = 0;

    // Step 2: for each char, check unique mids
    for (let i = 0; i < 26; i++) {
        const left = indices[i][0];
        const right = indices[i][1];

        if (left === -1) continue;

        // Step 3: count unique chars in between
        const set = new Set();
        for (let mid = left + 1; mid <= right - 1; mid++) {
            set.add(s[mid]);
        }

        res += set.size;
    }
    return res;
};