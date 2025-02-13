
// Problem link : https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/description/?envType=problem-list-v2&envId=hash-table

let greatestLetter = function(s) {
    // step 1 - create a set containing all characters in the string
    // this allow O(1) lookup
    const charSet = new Set(s);
    
    // step 2 - iterate over lowercase English letters in reverse order
    for(let ch = 122; ch >= 97; ch--){
        // convert ASCII value to character
        let char = String.fromCharCode(ch);

        // step 3 - check if both the lowercase and uppercase versions of the letter exist in the set
        if(charSet.has(char) && charSet.has(char.toUpperCase())){
            return char.toUpperCase();
        }
    }

    // step 4 - if no such letter is found, return an empty string
    return "";
};

// const s = "lEeTcOdE";

// const s = "arRAzFif";

const s = "AbCdEfGhIjK";
console.log(greatestLetter(s));
