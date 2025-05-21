
// Problem link - https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/?envType=problem-list-v2&envId=string

let maxFreqSum = function(s) {
    // step 1 - use frquency array to store frquency of each character in `s`
    const frq = new Array(26).fill(0);
    
    // step 2 - iterate on each character of `s` abd store its frquency
    for(let ch of s){
        frq[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    // step 3 - find maximum vowel and consonants frquency
    let maxFrqV = 0, maxFrqC = 0;
    for(let i=0; i<26; i++){
        if(i === 0 || i === 4 || i === 8 || i === 14 || i === 20){
            maxFrqV = Math.max(maxFrqV, frq[i]);
        }else{
            maxFrqC = Math.max(maxFrqC, frq[i]);
        }
    }

    // step 4 - return sum of maximum vowel and consonant frequency
    return maxFrqC +maxFrqV;
};

// const s = "successes";

const s = "aeiaeia";
console.log(maxFreqSum(s));
