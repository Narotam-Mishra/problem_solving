
// Problem link : https://leetcode.com/problems/decode-the-message/description/?envType=problem-list-v2&envId=hash-table

let decodeMessage = function(key, message) {
    // step 1 - build the substitution map
    const substitutionMap = new Map();
    // pointer to track the current letter of the English alphabet
    let alphabetIndex = 0;

    // iterate through the key to extract unique letters
    for(let ch of key){
        // skip space
        if(ch === ' ') continue;

        // add the character to the map if it's not already present
        if(!substitutionMap.has(ch)){
            // 'a' = 97
            substitutionMap.set(ch, String.fromCharCode(alphabetIndex + 97));
            alphabetIndex++;

            // stop once we have a mapping for all 26 letters
            if(alphabetIndex === 26) break;
        }
    }

    // step 2 - decode the message
    let decodedMessage = '';
    for(let ch of message){
        // space remain unchnaged
        if(ch === ' ') decodedMessage += ' ';
        // substitute using map
        else decodedMessage += substitutionMap.get(ch);
    }

    // step 3 - return decoded message
    return decodedMessage;
};

// const key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv";

const key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";
console.log(decodeMessage(key, message)); 
