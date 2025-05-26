
// Problem link - https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/description/?envType=problem-list-v2&envId=string

let minTimeToType = function(word) {
    // step 1 - store total minimum time in `minTime`
    let minTime = 0;

    // pointer start from character `a`
    let currentChar = 'a';

    // step 2 - iterate on each character of word
    for(let i=0; i<word.length; i++){
        // get target charcter
        let targetChar = word[i];

        // step 3 - calculate absolute difference between current and target character
        let diff = Math.abs(targetChar.charCodeAt(0) - currentChar.charCodeAt(0));

        // step 4 - since typwriter is circular so it can be either clockwise or anti-clockwise
        // so calculate minimum time accordingly
        let moveTime = Math.min(diff, 26 - diff);

        // step 5 - add 1 second to type each character
        minTime += moveTime + 1;

        // step 6 - update current pointer
        currentChar = targetChar;
    }

    // step 7 - return minimum time to type out the word
    return minTime
};

// const word = "abc";

// const word = "bza";

const word = "zjpc";
console.log(minTimeToType(word));
