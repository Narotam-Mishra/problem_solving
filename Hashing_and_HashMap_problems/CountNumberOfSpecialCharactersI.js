
// Problem link : https://leetcode.com/problems/count-the-number-of-special-characters-i/description/?envType=problem-list-v2&envId=hash-table

let numberOfSpecialChars = function(word) {
    // step 1 - initialize two sets to store lowercase and uppercase letters
    // to store all lowercase letters
    const lowerSet = new Set();

    // to store all uppercase letters
    const upperSet = new Set();

    // step 2 - populate the sets by iterating through the string `word`
    for(let char of word){
        if(char >= 'a' && char <= 'z'){
            lowerSet.add(char);
        }else if(char >= 'A' && char <= 'Z'){
            upperSet.add(char);
        }
    }

    // step 3 - count special letters
    let specialCharCount = 0;
    for(let ch of lowerSet){
        // convert lowercase to uppercase
        const upperChar = ch.toUpperCase();
        if(upperSet.has(upperChar)){
            specialCharCount++;
        }
    }

    // step 4 - return the total count of special letters
    return specialCharCount;
};

// const word = "aaAbcBC";

// const word = "abc";

const word = "abBCab";
console.log(numberOfSpecialChars(word)); 
