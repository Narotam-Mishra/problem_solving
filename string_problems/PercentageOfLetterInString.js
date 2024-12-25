
// Problem link : https://leetcode.com/problems/percentage-of-letter-in-string/description/?envType=problem-list-v2&envId=string

let percentageLetter = function(s, letter) {
    // step 1 - find length of input string `s`
    const len = s.length;
    // counter to count number of characters in string
    let letterCount = 0;

    // step 2 - iterate on each character
    for(let char of s){
        // if given letter present, increment counter
        if(char === letter){
            letterCount++;
        }
    }

    let percentage = (letterCount / len) * 100

    // step 3 - calculate percentage of letter count and return
    return Math.round(percentage);
};

const s = "foobar", letter = "o";

// const s = "jjjj", letter = "k";
console.log(percentageLetter(s, letter));
