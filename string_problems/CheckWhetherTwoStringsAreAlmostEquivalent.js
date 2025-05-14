
// Problem link - https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/description/?envType=problem-list-v2&envId=string

let checkAlmostEquivalent = function(word1, word2) {
    // step 1 - use frequency array to store count for each character
    const frq = new Array(26).fill(0);

    // step 2 - iterate on each character of `word1` and count its frequency
    for(let ch of word1){
        frq[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    // step 3 - iterate on each character of `word2` and decrement its frequency
    for(let ch of word2){
        frq[ch.charCodeAt(0) - 'a'.charCodeAt(0)]--;
    }

    // step 4 - iterate on frequency array 
    for(let i=0; i<26; i++){
        // and check if frequency difference of each character should be atmost 3
        if(Math.abs(frq[i]) > 3){
            // if frequency difference is not atmost 3 then return false immediately
            return false;
        }
    }

    // step 5 - if frequency difference of each character is atmost three, then return true
    return true;
};

// const word1 = "aaaa", word2 = "bccb";

// const word1 = "abcdeef", word2 = "abaaacc";

// const word1 = "cccddabba", word2 = "babababab";

const word1 = "zzzyyy", word2 = "iiiiii";
console.log(checkAlmostEquivalent(word1, word2));