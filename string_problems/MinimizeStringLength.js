
// Problem link - https://leetcode.com/problems/minimize-string-length/description/?envType=problem-list-v2&envId=string

let minimizedStringLength = function(s) {
    // step 1 - the minimal length is the number of distinct characters
    return new Set(s).size;
};

// const s = "aaabc";

// const s = "cbbd";

const s = "baadccab";
console.log(minimizedStringLength(s));
