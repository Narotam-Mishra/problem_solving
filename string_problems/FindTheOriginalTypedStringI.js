
// Problem link - https://leetcode.com/problems/find-the-original-typed-string-i/description/?envType=problem-list-v2&envId=string

let possibleStringCount = function(word) {
    // step 1 - count number of possible strings
    // start with 1 for the string as-is (no mistakes)
    let count = 1;

    // step 2 - iterate on each character of `word`
    for(let i=0; i<word.length; i++){

        // step 3 - find the length of the current run of identical characters
        let j = i + 1
        while(j < word.length && word[j] === word[i]){
            j++;
        }

        // step 4 - if we found repeated characters
        // Alice might have intended to type just one character here
        const runLength = j - i;
        if(runLength > 1){
            // increment count for repeated characters
            count++;
        }
    }

    // step 5 - return count number of possible strings
    return count;
};

// const word = "abbcccc";

// const word = "abcd";

const word = "aaaa";
console.log(possibleStringCount(word));
