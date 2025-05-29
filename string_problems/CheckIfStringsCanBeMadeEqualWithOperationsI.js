
// Problem link - https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/?envType=problem-list-v2&envId=string

// Approach 1 - Brute Force
let canBeEqual1 = function(s1, s2) {
    // edge case:
    if(s1 === s2) return true;

    // step 1 - sort even position characters and join them
    const evenS1 = [s1[0], s1[2]].sort().join('');
    const evenS2 = [s2[0], s2[2]].sort().join('');

    // step 2 - sort odd position characters and join them
    const oddS1 = [s1[1], s1[3]].sort().join('');
    const oddS2 = [s2[1], s2[3]].sort().join('');

    // step 3 - check them for equality
    return evenS1 === evenS2 && oddS1 === oddS2;
};

// Approach 2 - Efficient Approach
let canBeEqual = function(s1, s2) {
    // edge case:
    if(s1 === s2) return true;

    function isMatch(s1, s2, i) {
      return (
        (s1[i] === s2[i] && s1[i + 2] === s2[i + 2]) ||
        (s1[i] === s2[i + 2] && s1[i + 2] === s2[i])
      );
    }

    return isMatch(s1, s2, 0) && isMatch(s1, s2, 1);
};

// const s1 = "abcd", s2 = "cdab";

// const s1 = "abcd", s2 = "dacb";

const s1 = "bnxw", s2 = "bwxn";
console.log(canBeEqual(s1, s2));
