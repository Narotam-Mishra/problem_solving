
// Problem link : https://leetcode.com/problems/permutation-difference-between-two-strings/description/?envType=problem-list-v2&envId=hash-table

let findPermutationDifference = function(s, t) {
    // step 1 - initialize variable to store absolute difference
    let absDiff = 0;

    // step 2 - iterate over the any of input string
    for(let i=0; i<s.length; i++) {
        // get first character
        let ch = s[i];

        // get index of that first character in target string `t`
        let i2 = t.indexOf(ch);

        // step 3 - find sum of absolute difference
        absDiff += Math.abs(i - i2);
    }

    // step 4 - return sum of absolute difference
    return absDiff;
};

// const s = "abc", t = "bac";

const s = "abcde", t = "edbac";
console.log(findPermutationDifference(s, t));
