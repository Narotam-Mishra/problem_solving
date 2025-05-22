
// Problem link - https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/description/?envType=problem-list-v2&envId=string

let minDeletion = function(s, k) {
    // step 1 - count frequency of each character
    const counts = new Array(26).fill(0);
    for (let ch of s) {
        counts[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    // step 2 - sort frequencies in ascending order
    counts.sort((a, b) => a - b);

    // step 3 - count number of distinct characters
    let d = 0;
    for (let i = 0; i < 26; i++) {
        if (counts[i] !== 0) {
            d++;
        }
    }

    // step 4 - if already at most k distinct, no deletions needed
    if (d <= k) return 0;

    // step 5 - remove the least frequent characters
    let numOfDel = 0;
    let toRemove = d - k;
    for (let i = 0; i < 26 && toRemove > 0; i++) {
        if (counts[i] !== 0) {
            numOfDel += counts[i];
            toRemove--;
        }
    }

    // step 6 - return minimum number of deletions
    return numOfDel;
};