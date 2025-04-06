
// Problem link - https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/description/?envType=problem-list-v2&envId=string

// Approach - 1
let isAcronym1 = function(words, s) {
    // step 1 - store first character of each word in `res`
    let res = '';

    // step 2 - iterate on each word and extract its first charcter
    for(let word of words){
        res += word[0];
    }

    // step 3 - check if `s` is acronym of words 
    return res === s;
};

// Approach - 2
let isAcronym = function(words, s) {
    // check edge case:
    if(s.length !== words.length) return false;

    // step 1 - iterate on each character of `s` and 
    // check if it is equal to first character of each word of words array
    for(let i=0; i<s.length; i++){
        if(s[i] !== words[i][0]) return false;
    }

    // step 2 - return true if above condition is satified
    return true;
};

const words = ["alice","bob","charlie"], s = "abc";

// const words = ["an","apple"], s = "a";

// const words = ["never","gonna","give","up","on","you"], s = "ngguoy";
console.log(isAcronym(words, s));
