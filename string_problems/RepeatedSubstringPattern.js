
// Problem link : https://leetcode.com/problems/repeated-substring-pattern/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

// Brute Force Approach
let repeatedSubstringPattern1 = function(s) {
    const n = s.length;

    // edge case:
    if(n <= 1) return false;

    // loop through all possible substring length
    for(let l=1; l<=Math.floor(n/2); l++){
        // check if l is a divisor of n
        if(n % l === 0){
            // candidate substring
            const substring = s.slice(0,l);

            // repeat the substring
            const repeatedStr = substring.repeat(n/l);

            // check if the repeates string match the original string 's'
            if(repeatedStr === s){
                return true;
            }
        }
    }

    // no valid substring found
    return false;
};

// Efficient Approach
let repeatedSubstringPattern = function(s) {
    // check for edge case:
    if(s.length === 0){
        return false;
    }

    // step 1 : concatenate the string with itself
    const conStr = s + s;

    // step 2 : remove the first and last characters of the concatenated string
    const modStr = conStr.slice(1, conStr.length - 1);

    // step 3 : check if the original string is a substring of the modified concatenated string
    return modStr.includes(s);
};

let s = "abab";

// let s = "aba";

// let s = "abcabcabcabc";
console.log(repeatedSubstringPattern(s));
