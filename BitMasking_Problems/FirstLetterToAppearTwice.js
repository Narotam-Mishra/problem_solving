
// Problem link : https://leetcode.com/problems/first-letter-to-appear-twice/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

let repeatedCharacter = function(s) {
    let obj = {};

    // loop through each character of the string
    for(let ch of s){
        // if character exists in obj, increment its count
        if(obj[ch]){
            obj[ch]++;
        }else{
            // otherwise, initialize it with 1
            obj[ch] = 1;
        }

        // return the character once its count reaches 2
        if(obj[ch] == 2){
            return ch;
        }
    }
};

// let str = "abccbaacz";

let str = "abcdd";
console.log(repeatedCharacter(str));
