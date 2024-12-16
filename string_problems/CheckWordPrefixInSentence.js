
// Problem link : https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let isPrefixOfWord = function(sentence, searchWord) {
    // step 1 : split the sentence into an array of words
    const words = sentence.split(' ');

    // step 2 : loop through each word and check if searchWord is a prefix
    for(let i=0; i<words.length; i++){
        // check if the current word starts with the searchWord
        if(words[i].startsWith(searchWord)){
            // return the 1-indexed position (i + 1)
            return i+1;
        }
    }

    // step 3 : if no match is found, return -1
    return -1;
};

// let sentence = "i love eating burger", searchWord = "burg"

// let sentence = "this problem is an easy problem", searchWord = "pro";

let sentence = "i am tired", searchWord = "you";
console.log(isPrefixOfWord(sentence, searchWord));


