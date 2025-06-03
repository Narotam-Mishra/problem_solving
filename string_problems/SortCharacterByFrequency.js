
// Problem link - https://leetcode.com/problems/sort-characters-by-frequency/?envType=problem-list-v2&envId=string

let frequencySort = function(s) {
    // step 1 - store frquency of each character in frquency map `frqMap` object
    let frqMap = {};
    for(let ch of s){
        frqMap[ch] = (frqMap[ch] || 0) + 1;
    }

    // return result 
    return Object.keys(frqMap)
        // step 2 - sort character by its frequency in descending order  
        .sort((a,b) => frqMap[b] - frqMap[a])
        // step 3 - repeat each character by its frequency
        .map((char) => char.repeat(frqMap[char]))
        // step 4 - join back to string and return
        .join('');
};

// const s = "tree";

// const s = "cccaaa";

// const s = "Aabb";

const s = "loveleetcode";
console.log(frequencySort(s));
