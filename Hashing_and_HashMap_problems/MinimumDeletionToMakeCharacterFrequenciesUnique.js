
// Problem link - https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/

// Appraoch - 1 (using object as Hash Map)
let minDeletions1 = function(s) {
    // step 1 - store frequency of each character 
    const frqMap = {};
    for(let ch of s){
        frqMap[ch] = (frqMap[ch] || 0) + 1;
    }

    // step 2 - use set to store used frequencies to ensure uniqueness
    const usedFrequencies = new Set();
    let deletionCount = 0;

    // step 3 - iterate on each frquency values
    for(char in frqMap){
        // get frequency 
        let frq = frqMap[char];

        // step 4 - reduce frequency until it's unique (or zero)
        while(frq > 0 && usedFrequencies.has(frq)){
            // simulate deleting one occurrence
            frq--;

            // count minimum deletion required
            deletionCount++;
        }

        // step 5 - if `frq > 0`, add it to the set of used frquencies
        if(frq > 0){
            usedFrequencies.add(frq);
        }
    }

    // step 6 - return minimum deletion needed to make good string
    return deletionCount;
};

// Appraoch - 12 (using fixed size array)
let minDeletions = function(s) {
    // step 1 - store frequency of each character 
    const frqMap = new Array(26).fill(0);
    for(let ch of s){
        frqMap[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    // step 2 - use set to store used frequencies to ensure uniqueness
    const usedFrequencies = new Set();
    let deletionCount = 0;

    // step 3 - iterate on each frquency values
    for(let frq of frqMap){
        // step 4 - reduce frequency until it's unique (or zero)
        while(frq > 0 && usedFrequencies.has(frq)){
            // simulate deleting one occurrence
            frq--;

            // count minimum deletion required
            deletionCount++;
        }

        // step 5 - if `frq > 0`, add it to the set of used frquencies
        if(frq > 0){
            usedFrequencies.add(frq);
        }
    }

    // step 6 - return minimum deletion needed to make good string
    return deletionCount;
};

const s = "aab";

// const s = "aaabbbcc";

// const s = "ceabaacb";
console.log(minDeletions(s));