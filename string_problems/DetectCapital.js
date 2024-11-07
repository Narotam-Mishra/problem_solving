
// Problem link : https://leetcode.com/problems/detect-capital/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let detectCapitalUse = function(word) {
    // check for 1st condition : if all letters are uppercase
    if(word === word.toUpperCase()) return true;

    // check for 2nd condition : if all letters are lowercase
    if(word === word.toLowerCase()) return true;

    // check for 3rd condition : if only the first letter is uppercase and the rest are lowercase
    if(word[0] === word[0].toUpperCase() && word.slice(1) === word.slice(1).toLowerCase()) return true;

    // if none of three conditions are true then return false
    return false;
};

// let str = "USA";

// let str = "leetcode";

let str = "FlaG";
console.log(detectCapitalUse(str));
