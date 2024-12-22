
// Problem link : https://leetcode.com/problems/maximum-number-of-balloons/description/?envType=problem-list-v2&envId=string

let maxNumberOfBalloons1 = function(text) {
    // step 1 - create an array to count the frequency of each character 
    const balloonsFreq = { 'b': 1, 'a': 1, 'l': 2, 'o': 2, 'n': 1 };
    const textFreq = new Array(26).fill(0);

    // step 2 - count the frequency of each character in the input text
    for(const char of text){
        textFreq[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    // step 3 - // Calculate the maximum number of "balloon" instances that can be formed
    let minInstances = Infinity;
    for(const char in balloonsFreq){
        // get the index of the character in the text
        const index = char.charCodeAt(0) - 'a'.charCodeAt(0);
        
        // calculate possible instances of the word "balloon"
        let possibleInstances = Math.floor(textFreq[index] / balloonsFreq[char]);
        
        // update the minimum instances
        minInstances = Math.min(minInstances, possibleInstances);
    }

    // step 4 - return the minimum instances `minInstances`
    return minInstances;
};

let maxNumberOfBalloons = function(text) {
    // step 1 - initialize a frequency array for 26 letters of the alphabet
    const freq = new Array(26).fill(0);

    // step 2 - populate the frequency array based on the characters in the text
    for(let char of text){
        const index = char.charCodeAt(0) - 'a'.charCodeAt(0);
        freq[index]++;
    }

    // step 3 - compute the maximum number of "balloon" instances
    // 'b' -> index 1, 'a' -> index 0, 'l' -> index 11, 'o' -> index 14, 'n' -> index 13
    const bCount = freq[1];
    const aCount = freq[0];
    const lCount = Math.floor(freq[11] / 2);
    const oCount = Math.floor(freq[14] / 2);
    const nCount = freq[13];

    // step 4 - return the minimum count among all required characters
    return Math.min(bCount, aCount, lCount, oCount, nCount);
};

// const text = "nlaebolko";

const text = "loonbalxballpoon";

// const text = "leetcode";
console.log(maxNumberOfBalloons(text)); 
