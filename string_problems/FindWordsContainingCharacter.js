
// Problem link : https://leetcode.com/problems/find-words-containing-character/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let findWordsContaining = function(words, x) {
    // initialize an empty array to store indices of matching words
    let res = [];

    // iterate through each word in the words array
    for(let i=0; i<words.length; i++){
        // get the current word at index i
        let currWord = words[i];

        // check if the current word contains the character x
        if(currWord.includes(x)){
            // if it does, add the index to the result array
            res.push(i);
        }
    }

    // return the array of indices where words contain the character x
    return res;
};

// let words = ["leet","code"], x = "e";

// let words = ["abc","bcd","aaaa","cbc"], x = "a";

let words = ["abc","bcd","aaaa","cbc"], x = "z"
console.log(findWordsContaining(words, x));
