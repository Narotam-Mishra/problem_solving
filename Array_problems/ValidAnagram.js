
// Problem link - https://leetcode.com/problems/valid-anagram/description/

// Approach - 1 (Brute Force)
let isAnagram = function(s, t) {
    s = s.split("").sort().join("");
    t = t.split("").sort().join("");

    if(s === t){
        return true;
    }else{
        return false;
    }
};

// Approach - 2 (Efficient Approach using Freuency map)

let isAnagram1 = function(s, t) {
    if(s.length !== t.length) return false;

    // prepare frequency map
    const freqMap = {};

    for(let i=0; i<s.length; i++){
        if(freqMap[s[i]]){
            // if it is defined, we land here
            freqMap[s[i]] += 1;
        }else{
            // if it is undefined, we land here
            freqMap[s[i]] = 1;
        }
    }

    // this loop matches the characters inside the string t, with the map
    for(let i=0; i<t.length; i++){
        if(freqMap[t[i]] === undefined){
            // there is a character in t, which is not present in s
            return false;
        }else{
            // if occ found, decrease the frequency
            freqMap[t[i]] -= 1;
            if(freqMap[t[i]] === 0){
                delete freqMap[t[i]];
            }
        }
    }

    return Object.keys(freqMap).length === 0;
};