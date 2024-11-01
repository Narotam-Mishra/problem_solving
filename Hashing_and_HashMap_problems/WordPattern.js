
// Problem link : https://leetcode.com/problems/word-pattern/description/

let wordPattern = function(pattern, s) {
    // split the string `s` into words
    const words = s.split(" ");

    // corner case: if pattern length and words length don't match, immediately return false
    if(pattern.length !== words.length) return false;

    // initialize Maps for bijection
    const patternToWord = new Map();
    const wordToPattern = new Map();

    // iterate through each letter in the pattern and corresponding word in words
    for(let i=0; i<pattern.length; i++) {
        const word = words[i];
        const letter = pattern[i];

        // check if the letter in the pattern already maps to a different word
        if(patternToWord.has(letter)){
            if(patternToWord.get(letter) !== word){
                // conflict: letter is mapped to a different word
                return false;
            }
        }else{
            // map the letter to the current word
            patternToWord.set(letter, word);
        }

        // check if the word is already mapped to a different letter in the pattern
        if(wordToPattern.has(word)){
            if(wordToPattern.get(word) !== letter){
                // conflict: word is mapped to a different letter
                return false;
            }
        }else{
            // map the word to the current letter
            wordToPattern.set(word, letter);
        }
    }
    // if all mappings are consistent, return true
    return true;
};

// let pattern = "abba";
// let s = "dog cat cat dog";

// let pattern = "abba";
// let s = "dog cat cat fish";

let pattern = "abba";
let s = "dog constructor constructor dog";
console.log(wordPattern(pattern, s));
