
// Problem link - https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/?envType=problem-list-v2&envId=string

let arrayStringsAreEqual = function(word1, word2) {
    // step 1 - join each characters of word array and check for equality
    return word1.join('') === word2.join('');
};

const word1 = ["ab", "c"], word2 = ["a", "bc"];

// const word1 = ["a", "cb"], word2 = ["ab", "c"]

// const word1  = ["abc", "d", "defg"], word2 = ["abcddefg"];
console.log(arrayStringsAreEqual(word1, word2));
