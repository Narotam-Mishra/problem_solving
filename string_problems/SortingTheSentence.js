
// Problem link : https://leetcode.com/problems/sorting-the-sentence/description/?envType=problem-list-v2&envId=string

let sortSentence = function(s) {
    // step 1 - split the sentence into words
    const words = s.split(" ");

    // step 2 - find word and its position
    // utility function to transform the words into an array of objects 
    // containing the word and its position
    const wordsWithPosition = words.map((word) => {
        const position = parseInt(word[word.length - 1]);
        const actualWord = word.slice(0, -1);
        return { actualWord, position };
    })

    // step 3 - sort the words based on their position
    wordsWithPosition.sort((a, b) => a.position - b.position);

    // step 4 - extract the sorted words and 
    const sortedWords = wordsWithPosition.map((obj) => obj.actualWord);

    // step 5 - reconstruct the sorted words using join and return the it 
    return sortedWords.join(" ");
};

// const str = "is2 sentence4 This1 a3";

const str = "Myself2 Me1 I4 and3";
console.log(sortSentence(str));
