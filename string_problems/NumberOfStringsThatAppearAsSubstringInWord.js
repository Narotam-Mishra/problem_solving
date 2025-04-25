
// Problem link - https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/description/?envType=problem-list-v2&envId=string

let numOfStrings = function(patterns, word) {
    // step 1 - initialize counter `count`
    let count = 0;

    // step 2 - iterate on each pattern
    for(let w of patterns){

        // step 3 - check if each word `w` of pattern exist in input `word`
        if(word.includes(w)){
            // increment counter if substring exist
            count++;
        }
    }

    // step 4 - return count of substring
    return count;
};

// const patterns = ["a","abc","bc","d"], word = "abc";

// const patterns = ["a","b","c"], word = "aaaaabbbbb";

const patterns = ["a","a","a"], word = "ab";
console.log(numOfStrings(patterns, word));
