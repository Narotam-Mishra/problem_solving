
// Problem link : https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/

let isPrefixString = function(s, words) {
    // initialize an empty string to build the prefix incrementally
    let prefix = '';

    // step 1 - iterate through the words array
    for(const word of words){
        // step 2 - add the current word to the prefix
        prefix += word;

        // step 3 - check if the current prefix matches `s`
        if(prefix === s){
            return true;
        }

        // step 4 - if the prefix length exceeds `s` or diverges from it, return false
        if(prefix.length > s.length || !s.startsWith(prefix)){
            return false;
        }
    }

    // step 5 - if we complete the loop and no match is found, return false
    return false;
};

// let s = "iloveleetcode", words = ["i","love","leetcode","apples"];

let s = "iloveleetcode", words = ["apples","i","love","leetcode"];
console.log(isPrefixString(s, words));
