
// Problem link : https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/

let areAlmostEqual = function(s1, s2) {
    // step 1 - edge case: if strings are already equal, no swap is needed
    if(s1 === s2) return true;

    // step 2 - collect indices of mismatched characters
    const mismatches = [];
    for(let i=0; i<s1.length; i++) {
        if(s1[i] !== s2[i]){
            mismatches.push(i);
        }

        // if mismatches exceed 2, return false immediately
        if(mismatches.length > 2) return false;
    }

    // step 3 - check conditions for exactly two mismatches
    if(mismatches.length === 2){
        const [i, j] = mismatches;
        return s1[i] === s2[j] && s1[j] === s2[i];
    }

    // step 4 - if no mismatches or more than two mismatches, return false
    return false;
};

// const s1 = "bank", s2 = "kanb";

// const s1 = "attack", s2 = "defend";

const s1 = "kelb", s2 = "kelb";
console.log(areAlmostEqual(s1, s2)); 
