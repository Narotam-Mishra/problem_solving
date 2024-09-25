
// Problem link : https://leetcode.com/problems/count-the-number-of-consistent-strings/description/?envType=problem-list-v2&envId=bit-manipulation

let countConsistentStrings = function(allowed, words) {
    // convert 'allowed' string into a Set for efficient lookup of allowed characters
    const allowedSet = new Set(allowed);

    // using reduce to count the consistent strings in one loop
    return words.reduce((count, word) => {
        // check if every character in the word is in the allowed set
        if(word.split('').every(char => allowedSet.has(char))){
            // if consistent, increment the count
            count++;
        }
        return count;
    }, 0)
};

let allowed = "ab";
let words = ["ad","bd","aaab","baa","badab"];
console.log(countConsistentStrings(allowed, words));
