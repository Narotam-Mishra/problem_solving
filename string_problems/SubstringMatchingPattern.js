
// Problem link - https://leetcode.com/problems/substring-matching-pattern/description/?envType=problem-list-v2&envId=string

let hasMatch = function(s, p) {
    // step 1 - split the pattern at '*'
    let [prefix, suffix] = p.split('*');

    // step 2 - find first occurence of prefix in `s`
    let prefixIndex = s.indexOf(prefix);
    
    // step 3 - if prefix not found then return false right away
    if(prefixIndex === -1) return false;

    // step 4 - check if suffix exist after prefixIndex
    let suffixIndex = s.indexOf(suffix, prefixIndex + prefix.length);
    
    // step 5 - suffix must appear after prefix for valid match, otherwise return false
    return suffixIndex !== -1;
};

// const s = "leetcode", p = "ee*e";

// const s = "car", p = "c*v";

const s = "luck", p = "u*";
console.log(hasMatch(s, p));
