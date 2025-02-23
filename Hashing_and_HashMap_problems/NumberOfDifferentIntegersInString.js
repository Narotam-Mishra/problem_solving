
// Problem link - https://leetcode.com/problems/number-of-different-integers-in-a-string/description/?envType=problem-list-v2&envId=hash-table

let numDifferentIntegers = function(word) {
    // step 1 - replace all non-digit characters with space using regex
    word = word.replace(/\D+/g, ' ');

    // step 2 - split by space, filter non-empty values, and convert to integers
    const set = new Set(word.trim().split(/\s+/).map(Number));
    
    // step 3 - return the size of the set
    return set.size;
};

// const word = "a123bc34d8ef34";

// const word = "leet1234code234";

const word = "a1b01c001";

console.log(numDifferentIntegers(word));
