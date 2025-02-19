
// Problem link - https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/?envType=problem-list-v2&envId=hash-table

let maxDifference = function(s) {
    // step 1 - create frequency map array and fill it with characters frequencies
    const freqArr = new Array(26).fill(0);
    for(let i=0; i<s.length; i++){
        let charCode = s.charCodeAt(i) - 'a'.charCodeAt(0);
        freqArr[charCode]++;
    }

    // step 2 - find maximum odd frequency from frequency map array
    const maxOddFreq = Math.max(...freqArr.filter(freq => freq % 2 !== 0));
    
    // step 3 - find minimum even frequency from frequency map array
    const minEvenFreq = Math.min(...freqArr.filter(freq => (freq>0 && freq % 2 === 0)));
    
    // step 4 - find and return the maximum difference
    return (maxOddFreq - minEvenFreq);
};

// const s = "aaaaabbc";

const s = "abcabcab";
console.log(maxDifference(s));