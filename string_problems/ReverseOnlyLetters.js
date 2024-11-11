
// Problem link : https://leetcode.com/problems/reverse-only-letters/?envType=problem-list-v2&envId=string&difficulty=EASY&status=TO_DO%2CATTEMPTED

// utility function to test each character is valid alphabet
function isLetter(ch){
    return /^[a-zA-Z]$/.test(ch);
}

let reverseOnlyLetters = function(s) {
    // convert string to array to easily swap characters
    let chars = s.split('');

    // initialize pointers
    let l = 0, r = chars.length - 1;

    // process the characters until the two pointers meet
    while(l < r){

        // move left pointer to the next letter
        while(l < r && !isLetter(chars[l])){
            l++;
        }

        // move right pointer to the next letter
        while(l < r && !isLetter(chars[r])){
            r--;
        }

        // swap letters at left and right pointers
        if(l < r){
            [chars[l], chars[r]] = [chars[r], chars[l]];
            l++;
            r--;
        }
    }

    // convert char array back to string
    return chars.join('');
};

// let str = "ab-cd";

// let str = "a-bC-dEf-ghIj";

let str = "Test1ng-Leet=code-Q!";
console.log(reverseOnlyLetters(str));
