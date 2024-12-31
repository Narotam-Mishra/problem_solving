
// Problem link : https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=problem-list-v2&envId=string

let uncommonFromSentences = function(s1, s2) {
    // step 1 - split the sentences into words
    const words = s1.split(' ').concat(s2.split(' '));
    
    // step 2 - create a frequency map to count occurrences of each word
    const objMap = {};

    // count words in the sentence (s1 & s2)
    for(let word of words){
        objMap[word] = objMap[word] ? objMap[word] + 1 : 1;
    }

    // step 3 - find uncommon words (words with a frequency of exactly 1)
    const res = [];
    for(const word in objMap){
        if(objMap[word] === 1){
            // only add words that appear exactly once
            res.push(word);
        }
    }

    // step 4 - return the result array `res`
    return res;
};

// const s1 = "this apple is sweet", s2 = "this apple is sour";

const s1 = "apple apple", s2 = "banana";
console.log(uncommonFromSentences(s1, s2));
