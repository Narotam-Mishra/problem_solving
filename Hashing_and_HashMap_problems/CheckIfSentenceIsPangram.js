
// Problem link : https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/?envType=problem-list-v2&envId=hash-table

let checkIfPangram1 = function(sentence) {
    const mapArr = new Array(26).fill(0);

    for(let ch of sentence){
        mapArr[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
    }

    console.log(mapArr);
    
    for(let i=0; i<26; i++){
        if(mapArr[i] < 1){
            return false;
        }
    }
    return true;
};

let checkIfPangram2 = function(sentence) {
    return new Set(sentence).size === 26;
};

let checkIfPangram = function(sentence) {
    // step 1: iterate through each letter of the alphabet
    for (let ch = 'a'.charCodeAt(0); ch <= 'z'.charCodeAt(0); ch++) {
        // step 2: check if the current letter is present in the sentence
        if (sentence.indexOf(String.fromCharCode(ch)) === -1) {
            // step 3: if any letter is not found, return false
            return false;
        }
    }
    // step 4: if all letters are found, return true
    return true;
};

// const sentence = "thequickbrownfoxjumpsoverthelazydog";

// const sentence = "leetcode";

const sentence = "onrcsnlxckptsxffbyswujpamfltvmdoxovggepknmtacrjkkorjgvgtgaiaudspnpxkwikevmjeephhiyvnoymjwjfopovscbefecnoytjxfwasabwohqujwowmakpyuuqvgfab";
console.log(checkIfPangram(sentence));
