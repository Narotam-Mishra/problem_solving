
// Problem link : https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/?envType=problem-list-v2&envId=hash-table

let areOccurrencesEqual1 = function(s) {
    // step 1 : create map and store frequency of each character of input string `s`
    const map = {};
    for(let ch of s){
        map[ch] = (map[ch] || 0) + 1;
    }

    // step 2 : get count of first charcter of input string
    const currCount = map[s[0]];

    // step 3 - compare 1st charcter count with remaining characters
    for(let i=1; i<s.length; i++){
        // if remaining characters count are not equal
        if(map[s[i]] !== currCount){
            // return false immediately
            return false;
        }
    }
    // step 4 - otherwise return true
    return true;
};

let areOccurrencesEqual = function(s) {
    // step 1: create a frequency array and store the frequency of each character in the input string `s`
    const frqArr = new Array(26).fill(0);
    for (let i = 0; i < s.length; i++) {
        frqArr[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }

    // step 2: get the count of the first character of the input string
    const currCount = frqArr[s.charCodeAt(0) - 'a'.charCodeAt(0)];

    // step 3: compare the count of the first character with the remaining characters
    for (let num of frqArr) {
        // if the count of any remaining character is not equal to the count of the first character
        if (num !== 0 && num !== currCount) {
            // return false immediately
            return false;
        }
    }

    // step 4: otherwise, return true
    return true;
};

const s = "abacbc";

// const s = "aaabb";
console.log(areOccurrencesEqual(s));
