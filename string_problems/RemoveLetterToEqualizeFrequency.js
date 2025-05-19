
// Problem link - https://leetcode.com/problems/remove-letter-to-equalize-frequency/description/?envType=problem-list-v2&envId=string

let equalFrequency = function(word) {
    // step 1 - store frequency of each character in frequency array `frq`
    const frq = new Array(26).fill(0);
    for(let ch of word){
        frq[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    // step 2 - try removing each frequency once
    for(let i=0; i<26; i++){
        // skip 0
        if(frq[i] == 0){
            continue;
        }

        // step 3 - remove frequency once 
        frq[i]--;

        // step 4 - collect non-zero frequency once
        const frqSet = new Set();
        for(let f of frq){
            if(f > 0){
                frqSet.add(f);
            }
        }

        // step 5 - check if all frquencies are same, then return true immediately
        if(frqSet.size === 1) return true;

        // step 6 - restore original frquency
        frq[i]++;
    }

    // step 7 - return false if conditions not met
    return false;
};

// const word = "abcc";

const word = "aazz";
console.log(equalFrequency(word));
