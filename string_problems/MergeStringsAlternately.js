
// Problem link - https://leetcode.com/problems/merge-strings-alternately/description/?envType=problem-list-v2&envId=string

let mergeAlternately = function(word1, word2) {
    // step 1 - use two pointers technique
    let i = 0, j = 0;

    // step 2 - store merged string into `res`
    let res = '';

    // step 3 - iterate on both strings alternatively
    while(i < word1.length && j < word2.length){
        res += word1[i++];
        res += word2[j++];
    }

    // check if some characters are left in word1 
    while(i < word1.length){
        res += word1[i++]
    }

    // check if some characters are left in word2 
    while(j < word2.length){
        res += word2[j++]
    }

    // step 4 - return final merged string `res`
    return res;
};

const word1 = "abc", word2 = "pqr";

// const word1 = "ab", word2 = "pqrs";

// const word1 = "abcd", word2 = "pq";
console.log(mergeAlternately(word1, word2));
