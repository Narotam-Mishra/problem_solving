
// Problem link - https://leetcode.com/problems/longest-balanced-substring-i/?envType=daily-question&envId=2026-02-12

// utility function to check if substring is balanced
function isBalancedString(freq) {
    let commonFreq = 0;

    for (let i = 0; i < 26; i++) {
        if (freq[i] === 0) continue;

        if (commonFreq === 0) {
            commonFreq = freq[i];
        } else if (commonFreq !== freq[i]) {
            return false;
        }
    }

    return true;
}

let longestBalanced = function(s) {
    const n = s.length;

    // keep track of longest balanced substring length
    let maxLen = 0;

    // step 1 - iterate on each starting index
    for (let i = 0; i < n; i++) {
        // frequency array for characters a-z
        let freq = new Array(26).fill(0);

        // step 2 - iterate on substrings starting from i
        for (let j = i; j < n; j++) {
            let idx = s.charCodeAt(j) - 'a'.charCodeAt(0);
            freq[idx]++;

            // step 3 - check if current substring is balanced
            if (isBalancedString(freq)) {
                // step 4 - update maximum length
                maxLen = Math.max(maxLen, j - i + 1);
            }
        }
    }

    // step 5 - return result
    return maxLen;
}

// const s = "abbac";

// const s = "zzabccy";

const s = "aba";
console.log(longestBalanced(s));