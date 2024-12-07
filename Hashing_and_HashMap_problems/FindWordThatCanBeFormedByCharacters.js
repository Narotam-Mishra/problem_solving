
// Problem link : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let countCharacters = function(words, chars) {
    // step 1: create a frequency map for `chars`
    const charCount = {};
    for(let ch of chars){
        charCount[ch] = (charCount[ch] || 0) + 1;
    }

    // to store the sum of lengths of "good" strings
    let totalLengthofGoodStr = 0;

    // step 2: iterate through each word in `words`
    for(const word of words){
        // create a frequency map for the current word
        const wordCount = {};
        for(let ch of word){
            wordCount[ch] = (wordCount[ch] || 0) + 1;
        }

        // step 3: check if the word can be formed using `chars`
        let canBeFormed = true;
        for(const char of word){
            if(!charCount[char] || wordCount[char] > charCount[char]){
                // not enough characters available in `chars`
                canBeFormed = false;
                break;
            }
        }

        // step 4: if the word is "good," add its length to `totalLengthofGoodStr`
        if(canBeFormed){
            totalLengthofGoodStr += word.length;
        }
    }
    return totalLengthofGoodStr;
};

// const words = ["cat","bt","hat","tree"], chars = "atach";

const words = ["hello","world","leetcode"], chars = "welldonehoneyr";
console.log(countCharacters(words, chars));
