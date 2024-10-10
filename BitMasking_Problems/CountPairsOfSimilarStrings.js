
// Problem link : https://leetcode.com/problems/count-pairs-of-similar-strings/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

let similarPairs = function(words) {
    let pairsCnt = 0;
    let countMap = {};

    // iterate through each word in the words array
    for(let word of words){
        // normalize the word by sorting unique characters
        let sortedWord = [...new Set(word)].sort().join('');
        
        // if this sortedWord has been seen before, 
        // increment the count of pairs
        if(countMap[sortedWord]){
            pairsCnt += countMap[sortedWord];
        }
        // increment or set the count for this normalized form of the word
        countMap[sortedWord] = (countMap[sortedWord] || 0) + 1;
    }
    // return similar pairs count
    return pairsCnt;
};

// let words = ["aba","aabb","abcd","bac","aabc"];

let words = ["aabb","ab","ba"];
console.log(similarPairs(words));
