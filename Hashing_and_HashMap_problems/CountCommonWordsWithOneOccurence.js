
// Problem link : https://leetcode.com/problems/count-common-words-with-one-occurrence/description/

let countWords = function(words1, words2) {
    // step 1: initialize hash maps to store the frequency of each word
    const wordMap1 = {};
    const wordMap2 = {};

    // step 2: count frequencies in words1
    for(const word of words1){
        wordMap1[word] = wordMap1[word] ? wordMap1[word] + 1 : 1;
    }

    // step 3: count frequencies in words2
    for(const word of words2){
        wordMap2[word] = wordMap2[word] ? wordMap2[word] + 1 : 1;
    }

    // step 4: compare counts and count matches
    let count = 0;
    for(const word in wordMap1){
        if(wordMap1[word] === 1 && wordMap2[word] === 1){
            count++;
        }
    }

    // step 5 - return number of strings that appear exactly once in each of the two arrays.
    return count;
};

// const words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"];

// const words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"];

const words1 = ["a","ab"], words2 = ["a","a","a","ab"];
console.log(countWords(words1, words2)); 
