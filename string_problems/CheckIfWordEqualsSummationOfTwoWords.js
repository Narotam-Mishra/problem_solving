
// Problem link - https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/?envType=problem-list-v2&envId=string

// utility function to convert string to corresponding numeric value
function getNumericValue(str){
    let res = '';
    for(let ch of str){
        res += ch.charCodeAt(0) - 'a'.charCodeAt(0);
    }
    return Number(res);
}

let isSumEqual = function(firstWord, secondWord, targetWord) {
    // step 1 - change input strings to corresponding numeric values
    let val1 = getNumericValue(firstWord);
    let val2 = getNumericValue(secondWord);

    // step 2 - find sum of both numeric values
    let sum = val1 + val2;

    // step 3 - check sum of numeric values are equal to corresponding numric value of `targetWord`
    return sum === getNumericValue(targetWord);
};

// const firstWord = "acb", secondWord = "cba", targetWord = "cdb";

// const firstWord = "aaa", secondWord = "a", targetWord = "aab";

const firstWord = "aaa", secondWord = "a", targetWord = "aaaa";
console.log(isSumEqual(firstWord, secondWord, targetWord));
