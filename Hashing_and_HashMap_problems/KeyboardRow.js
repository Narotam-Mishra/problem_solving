
// Problem link - https://leetcode.com/problems/keyboard-row/description/

// utility function to check wheather each character of word exist in row or not
function isWordInRow(word, rowSet){
    for(let char of word.toLowerCase()){
        if(!rowSet.has(char)){
            // even if one character is not in the same row return false immediately
            return false;
        }
    }
    // all characters are in same row, return true
    return true;
}

let findWords = function(words) {
    // step 1 - define sets for each keyboard row
    const row1 = new Set("qwertyuiop");
    const row2 = new Set("asdfghjkl");
    const row3 = new Set("zxcvbnm");

    // step 2 - store final result in `res`
    const res = [];

    // step 3 - iterate on each word
    for(let word of words){
        // check first character to dtermine which row it belongs to
        const lowerChar = word[0].toLowerCase();

        // step 4 - determine row for each word
        if(row1.has(lowerChar)){
            if(isWordInRow(word, row1)) res.push(word);
        }else if(row2.has(lowerChar)){
            if(isWordInRow(word, row2)) res.push(word);
        }else if(row3.has(lowerChar)){
            if(isWordInRow(word, row3)) res.push(word);
        }
    }

    // step 5 - return final result `res`
    return res;
};

// const words = ["Hello","Alaska","Dad","Peace"];

// const words = ["omk"];

const words = ["adsdf", "sfd"];
console.log(findWords(words));
