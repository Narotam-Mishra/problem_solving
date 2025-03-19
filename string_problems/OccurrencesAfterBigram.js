
// Problem link - https://leetcode.com/problems/occurrences-after-bigram/description/?envType=problem-list-v2&envId=string

let findOcurrences = function(text, first, second) {
    // step 1 - split text into words
    const words = text.split(' ');
    const res = [];

    // step 2 - iterate on each word
    for(let i=0; i<words.length-2; i++){
        // step 3 - check if current and next word match `first` and `second`
        if(words[i] === first && words[i+1] === second){
            // step 4 - add the third word to result
            res.push(words[i+2]);
        }
    }

    // step 5 - return the array of found words
    return res;
};

const text = "alice is a good girl she is a good student", first = "a", second = "good";

// const text = "we will we will rock you", first = "we", second = "will";
console.log(findOcurrences(text, first, second));
