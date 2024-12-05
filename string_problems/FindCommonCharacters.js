
// Problem link : https://leetcode.com/problems/find-common-characters/description/?envType=problem-list-v2&envId=string&difficulty=EASY&status=TO_DO

let commonChars = function(words) {
    // initialize an array to store the minimum frequency of each character
    // 26 slots for each character of alphabet
    let commonCount = Array(26).fill(0);

    // utility function to convert character to index
    const charToIndex = (char) => char.charCodeAt(0) - 'a'.charCodeAt(0);

    // count frequency of each character in first word
    for(const ch of words[0]){
        commonCount[charToIndex(ch)]++;
    }

    // iterate through remaining words to find common minimum frequencies
    for(let i=1; i<words.length; i++) {
        // frequency count for the current word
        let currCharCount = Array(26).fill(0);
        for(const ch of words[i]){
            currCharCount[charToIndex(ch)]++;
        }

        // update the commonCount array by taking the minimum frequency
        for(let j=0; j<26; j++){
            commonCount[j] = Math.min(currCharCount[j], commonCount[j]);
        }
    }

    // build result array using the final commonCount array
    let res = [];
    for(let i=0; i<26; i++){
        // add the character `i + 'a'` repeated `commonCount[i]` times
        res.push(...Array(commonCount[i]).fill(String.fromCharCode(i + 'a'.charCodeAt(0))));
    }
    return res;
};

// let words = ["bella","label","roller"];

let words = ["cool","lock","cook"]
console.log(commonChars(words));
