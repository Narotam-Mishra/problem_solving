
// Problem link : https://leetcode.com/problems/goat-latin/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let toGoatLatin = function(sentence) {
    // define set of vowels
    const vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);

    // split the sentence into words
    const words = sentence.split(' ');

    // process each word and transform it into GoatLatin as per given conditions
    const goatLatinWords = words.map((word, index) => {
        let transformedWord = '';
        
        // check if the first letter is a vowel
        if(vowels.has(word[0])){
            // if it starts with a vowel, append "ma"
            transformedWord = word + 'ma';
        }else{
            // if it starts with a consonant, move the first letter to the end and append "ma"
            transformedWord += word.slice(1) + word[0] + 'ma';
        }
        
        // append 'a' based on the word's index (1-based)
        transformedWord += 'a'.repeat(index + 1);
        return transformedWord;
    })

    // join the transformed words back into a sentence
    return goatLatinWords.join(' ');
};

// let sentence = "I speak Goat Latin";

let sentence = "The quick brown fox jumped over the lazy dog";
console.log(toGoatLatin(sentence));
