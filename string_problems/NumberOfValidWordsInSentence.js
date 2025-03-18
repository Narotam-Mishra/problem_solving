
// Problem link - https://leetcode.com/problems/number-of-valid-words-in-a-sentence/description/?envType=problem-list-v2&envId=string

// utlity function to check if a token is a valid word or not
function isValidWord(token){
    // check if token contains digits --> Invalid word
    if(/\d/.test(token)) return false;

    let hyphenCount = punctuationCount = 0;

    for(let i=0; i<token.length; i++){
        let char = token[i];

        // hyphen check
        if(char === '-'){
            hyphenCount++;
            if(hyphenCount > 1) return false;

            // hyphen must be surrounded by lowecase letters
            if (i === 0 || i === token.length - 1 || !(/[a-z]/.test(token[i - 1]) && /[a-z]/.test(token[i + 1]))){
                return false;
            }
        }

        // punctuation check
        if(char === '!' || char === '.' || char === ','){
            punctuationCount++;
            if(punctuationCount > 1) return false;

            // punctuation must be at the end of the word
            if(i !== token.length - 1) return false;
        }
    }

    // passed all checks, so return true
    return true;
}

let countValidWords1 = function(sentence) {
    // step 1 - split sentence into tokens by space
    const tokens = sentence.trim().split(/\s+/);
    let wordCount = 0;

    // step 2 - iterate on each token
    for(let token of tokens){
        // step 3 - check if it is a valid word or not using `isValidWord()` method
        if(isValidWord(token)){
            wordCount++;
        }
    }

    // step 4 - return valid word count
    return wordCount;
};

let countValidWords = function(sentence) {
    // step 1 - regular expression to match valid words
    const validWordPattern = /^[a-z]+(-[a-z]+)?[\.!,]?$/;

    // step 2 - regular expression to match standalone punctuation marks
    const punctuationPattern = /^[\.!,]$/;

    // step 3 - split the sentence into words using spaces as delimiters
    // keep valid words and return its length
    return sentence
      .split(/\s+/)
      .filter(
        (word) => validWordPattern.test(word) || punctuationPattern.test(word)
      ).length;
};

// const sentence = "cat and  dog";

// const sentence = "!this  1-s b8d!";

const sentence = "alice and  bob are playing stone-game10";
console.log(countValidWords(sentence));
