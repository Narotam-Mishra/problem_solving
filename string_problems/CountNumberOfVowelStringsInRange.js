
// Problem link - https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/description/?envType=problem-list-v2&envId=string

let vowelStrings = function(words, left, right) {
    // step 1 - initialize counter to count vowel string in `words`
    let count = 0;

    // step 2 - create vowels set for fast lookup
    let vowelsSet = new Set(['a','e','i','o','u']);

    // step 3 - iterate on words array in range of `left` to `right`
    for(let i=left; i<=right; i++){
        let word = words[i];

        // step 4 - check for vowel string conditions
        if(vowelsSet.has(word[0]) && vowelsSet.has(word[word.length - 1])){
            // increment the counter if it matches the given vowel string conditions
            count++;
        }
    }

    // step 5 - return counter `count`
    return count;
};

// const words = ["are","amy","u"], left = 0, right = 2;

const words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4;
console.log(vowelStrings(words, left, right));
