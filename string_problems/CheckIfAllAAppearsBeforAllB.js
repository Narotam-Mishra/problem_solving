
// Problem link - https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/

let checkString = function(s) {
    // step 1 - set flag to tack if we have seen `b`
    let seenB = false;

    // step 2 - iterate on each character of `s`
    for(let ch of s){
        // step 3 - mark true for every `b` that we have seen
        if(ch === 'b'){
            seenB = true;
        }else if(ch === 'a'){
            // step 4 - if we see an `a` after `b` then return false immediately
            if(seenB){
                return false;
            }
        }
    }

    // step 5 - return true as all characters follow the rule: 'a's before 'b's
    return true;
};

// const s = "aaabbb";

// const s = "ababa";

const s = "bbb";
console.log(checkString(s));
