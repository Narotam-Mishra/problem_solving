
// Problem link - https://leetcode.com/problems/find-all-anagrams-in-a-string/description/?envType=problem-list-v2&envId=string

let findAnagrams = function(s, p) {
    // step 1 - store result in `res` array
    const res = [];

    // check for base case
    if(p.length > s.length){
        return res;
    }

    // step 2 - using fixed size frequency arrays to count frquencies
    const pCount = new Array(26).fill(0);
    const windowCount = new Array(26).fill(0);

    // step 3 - count pattern frquencies
    for(let ch of p){
        pCount[ch.charCodeAt(0) - 97]++;
    }

    // step 4 - calculate window size 
    const windowSize = p.length;

    // step 5 - initialize first window
    for(let i=0; i<windowSize; i++){
        windowCount[s.charCodeAt(i) - 97]++;
    }

    // using helper function to compare arrays
    function arrayEquals(arr1, arr2){
        for(let i=0; i<26; i++){
            if(arr1[i] !== arr2[i]) return false;
        }
        return true;
    }

    // step 6 - check first window
    if(arrayEquals(windowCount, pCount)){
        res.push(0);
    }

    // step 7 - slide through the window
    for(let i=windowSize; i<s.length; i++){
        // add new character frequency from current window
        windowCount[s.charCodeAt(i) - 97]++;

        // remove old character frequency
        windowCount[s.charCodeAt(i - windowSize) - 97]--;

        // check current window
        if(arrayEquals(windowCount, pCount)){
            res.push(i - windowSize + 1);
        }
    }

    // step 8 - return resultant array `res`
    return res;
};

const s = "cbaebabacd", p = "abc";

// const s = "abab", p = "ab";
console.log(findAnagrams(s, p));