
// Problem link - https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/description/?envType=problem-list-v2&envId=string

let mostWordsFound = function(sentences) {
    // step 1 - initialize variable to count maximum number of words
    let maxWords = 0;

    // step 2 - iterate on each sentence of `sentences`
    for(let sentence of sentences){
        // step 3 - count number of words in each sentence
        let count = sentence.trim().split(/\s+/).filter(word => word.length > 0).length;
        
        // step 4 - update maximum number of words
        maxWords = Math.max(count, maxWords);
    }

    // step 5 - return maximum number of words `maxWords`
    return maxWords;
};

// const sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"];

const sentences = ["please wait", "continue to fight", "continue to win"];
console.log(mostWordsFound(sentences));
