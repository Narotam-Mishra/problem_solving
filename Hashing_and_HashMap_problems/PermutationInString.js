
// Problem link - https://leetcode.com/problems/permutation-in-string/description/

let checkInclusion = function(s1, s2) {
    // edge case: if s1 is longer than s2, no permutation can exist
    if(s1.length > s2.length){
        return false;
    }
    
    // step 1 - using fixed size frequency arrays to count frquencies
    const pCount = new Array(26).fill(0);
    const windowCount = new Array(26).fill(0);

    // step 2 - count `s1` frquencies
    for(let ch of s1){
        pCount[ch.charCodeAt(0) - 97]++;
    }

    // step 3 - calculate window size 
    const windowSize = s1.length;

    // step 4 - initialize first window
    for(let i=0; i<windowSize; i++){
        windowCount[s2.charCodeAt(i) - 97]++;
    }

    // step 5 - using helper function to compare arrays
    function arrayEquals(arr1, arr2){
        for(let i=0; i<26; i++){
            if(arr1[i] !== arr2[i]) return false;
        }
        return true;
    }

    // step 6 - check first window
    if(arrayEquals(windowCount, pCount)){
        return true;
    }

    // step 7 - slide through the window
    for(let i=windowSize; i<s2.length; i++){
        // add new character frequency from current window
        windowCount[s2.charCodeAt(i) - 97]++;

        // remove old character frequency
        windowCount[s2.charCodeAt(i - windowSize) - 97]--;

        // check current window
        if(arrayEquals(windowCount, pCount)){
            return true;
        }
    }

    // step 8 - return false as sliding through window is completed
    return false;
};

// const s1 = "ab", s2 = "eidbaooo";

const s1 = "ab", s2 = "eidboaoo";
console.log(checkInclusion(s1, s2));
