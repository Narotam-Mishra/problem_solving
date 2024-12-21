
// Problem link : https://leetcode.com/problems/rearrange-characters-to-make-target-string/description/

// helper function to create a frequency map of characters in a string
function createFrequencyArray(str){
    // frequency array to store frequency of each character
    const freqArray = new Array(26).fill(0); 
    for (const char of str) {
        freqArray[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }
    return freqArray;
}

let rearrangeCharacters = function(s, target) {
    // step 1 - create frequency arrays for both s and target
    const sFreqArray = createFrequencyArray(s);
    const targetFreqArray = createFrequencyArray(target);

    // step 2 - initialize the maximum number of copies to a large number
    let maxCopies = Infinity;

    // step 3 - calculate the maximum number of copies of target that can be formed
    for (let i = 0; i < 26; i++) {
        if (targetFreqArray[i] > 0) {
            if (sFreqArray[i] === 0) {
                // if a character in target is not present in s, we can't form target even once
                return 0;
            }
            // calculate how many times this character can contribute to forming target
            const possibleCopies = Math.floor(sFreqArray[i] / targetFreqArray[i]);
            // update the maximum number of copies
            maxCopies = Math.min(maxCopies, possibleCopies);
        }
    }

    // step 4 : return `maxCopies` maximum copies possible
    return maxCopies;
};

// const s = "ilovecodingonleetcode", target = "code";

const s = "abbaccaddaeea", target = "aaaaa";
console.log(rearrangeCharacters(s, target)); 
