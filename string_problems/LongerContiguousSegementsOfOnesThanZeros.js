
// Problem link - https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/description/?envType=problem-list-v2&envId=string

let checkZeroOnes = function(s) {
    // step 1: initialize variables to keep track of the maximum length of contiguous segments of 1s and 0s
    let maxOnes = 0, maxZeros = 0;

    // step 2: initialize variables to keep track of the current character and its count
    let currChar = s[0];
    let currentCount = 1;

    // step 3 - iterate on each chacter of `s` starting from 1st index
    for (let i = 1; i < s.length; i++) {
        // step 3 - continue counting current segemnt
        if(s[i] === currChar){
            currentCount++;
        }else{
            // step 4 - when contiguous segment ends, update max length of 1s and 0s
            if(currChar === '1'){
                maxOnes = Math.max(maxOnes, currentCount);
            }else{
                maxZeros = Math.max(maxZeros, currentCount);
            }

            // step 5 - reset current character and count
            currChar = s[i];
            currentCount = 1;
        }    
    }

    // step 6 - update last segemnt after loop ends
    if (currChar === "1") {
      maxOnes = Math.max(maxOnes, currentCount);
    } else {
      maxZeros = Math.max(maxZeros, currentCount);
    }

    // step 7 - return true if max length of 1s is greater than max length of 0s
    return maxOnes > maxZeros;
};

const s = "1101";

// const s = "111000";

// const s = "110100010";

// const s = "011000111";
console.log(checkZeroOnes(s));
