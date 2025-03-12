
// Problem link - https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=problem-list-v2&envId=string

let reversePrefix = function(word, ch) {
    // step 1 - get `ch` index in word
    let chIndex = word.indexOf(ch);

    // check for edge case
    if(chIndex === -1) return word;

    // step 2 - traverse word in reverse order stating from `ch` index
    let res = '';
    for(let i=chIndex; i>=0; i--){
        // store characters in res
        res += word[i];
    }

    // step 3 - traverse remaining characters from word 
    for(let i=chIndex+1; i<word.length; i++){
        res += word[i];
    }

    // step 4 - return res;
    return res;
};

// const word = "abcdefd", ch = "d";

// const word = "xyxzxe", ch = "z";

const word = "abcd", ch = "z";
console.log(reversePrefix(word, ch));
