
// Problem link : https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/?envType=problem-list-v2&envId=hash-table

let canBeTypedWords1 = function(text, brokenLetters) {
    // step 1 - initialize count for words that can be typed
    let count = 0;

    // step 2 - split text into word array
    const words = text.split(" ");

    // step 3 - convert brokenLetters into a Set for quick lookup
    const brokenSet = new Set(brokenLetters);

    // step 4 - iterate over each word
    for(let word of words){
        // assume word can be typed
        let canType = true;

        // step 5 - check if any character in the word is in brokenLetters
        for(let ch of word){
            if(brokenSet.has(ch)){
                // mark as untypeable
                canType = false;
                // no need to further check so break the loop
                break;
            }
        }

        // step 6 - if the word is typeable, increase count
        if(canType) count++;
    }

    // step 7 - return the final count
    return count;
};

let canBeTypedWords = function(text, brokenLetters) {
    // step 1 - if no broken letters, all words can be typed
    if(!brokenLetters) return text.split(' ').length;

    // step 2 - Create regex pattern matching any broken letter
    const pattern = new RegExp(`[${brokenLetters}]`);

    // step 3 - Return count of words that don't contain broken letters
    return text.split(' ').filter(word => !pattern.test(word)).length;
};

const text = "hello world", brokenLetters = "ad";

// const text = "leet code", brokenLetters = "lt";

// const text = "leet code", brokenLetters = "e";
console.log(canBeTypedWords(text, brokenLetters));
