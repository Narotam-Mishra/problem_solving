
// Problem link : https://leetcode.com/problems/unique-morse-code-words/description/?envType=problem-list-v2&envId=string

let uniqueMorseRepresentations = function(words) {
    // step 1 : define the Morse code lookup table
    const morseCodeTable = [
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    ];

    // step 2 : initialize a Set to store unique transformations
    const transformationSet = new Set();

    // step 3 : iterate through each word in the words array
    for(const word of words){
        // initialize an empty string to build the Morse code for the word
        let morseWord = "";

        // convert each letter in the word to its Morse code equivalent
        for(const char of word){
            // append the Morse code of the character
            morseWord += morseCodeTable[char.charCodeAt(0) - 'a'.charCodeAt(0)];
        }

        // add the transformation to the set
        transformationSet.add(morseWord);
    }

    // step 4 : return the size of the Set (number of unique transformations)
    return transformationSet.size;
};

// const words = ["gin","zen","gig","msg"];

const words = ["a"];
console.log(uniqueMorseRepresentations(words));
