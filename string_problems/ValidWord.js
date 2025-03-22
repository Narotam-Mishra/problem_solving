
// Problem link - https://leetcode.com/problems/valid-word/description/?envType=problem-list-v2&envId=string

let isValid = function(word) {
    // step 1 - check the length constraint
    if(word.length < 3) return false;

    // step 2 - ensure only valid characters (letters and digits) are present
    if (!/^[a-zA-Z0-9]+$/.test(word)) return false;

    // step 3 - define a set of vowels for quick lookup
    const vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
    
    let hasVowel = false;
    let hasConsonant = false;
    // step 4 - iterate on each character of input `word`
    for(let char of word){
        if(vowels.has(char)){
            // found atleast one vowel
            hasVowel = true;
        }else if(isNaN(char)){
            // if it's not a number, it's a consonant
            hasConsonant = true;
        }

        // step 5 - if both conditions are met, no need to check further
        if(hasVowel && hasConsonant){
            return true;
        }
    }

    // step 6 - return false if any condition is not met
    return false;
};

// const word = "234Adas";

// const word = "b3";

const word = "a3$e";
console.log(isValid(word));
