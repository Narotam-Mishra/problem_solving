
// Problem link - https://leetcode.com/problems/lexicographically-smallest-palindrome/description/?envType=problem-list-v2&envId=string

let makeSmallestPalindrome = function(s) {
    // step 1 - make string into char array
    const strArr = s.split('');

    // step 2 - use two pointers approach 
    let i = 0, j = strArr.length - 1;

    // step 3 - process characters from both ends
    while(i < j){
        if(strArr[i] !== strArr[j]){
            // step 4 - replace the character that gives the lexicographically smaller result
            let smallarChar = strArr[i] < strArr[j] ? strArr[i] : strArr[j];
            strArr[i] = strArr[j] = smallarChar;
        }
        i++;
        j--;
    }

    // step 5 - join array back to string and return the result
    return strArr.join('');
};

// const s = "egcfe";

// const s = "abcd";

const s = "seven";
console.log(makeSmallestPalindrome(s));


