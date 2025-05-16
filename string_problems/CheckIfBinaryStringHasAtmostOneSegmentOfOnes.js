
// Problem link - https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/

let checkOnesSegment = function(s) {
    // step 1 - return true if "01" is not found in the string
    return !(s.includes('01'));
};

// const s = "1001";

// const s = "110";

const s = "10";
console.log(checkOnesSegment(s));
