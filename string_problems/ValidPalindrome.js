
// Problem link : https://leetcode.com/problems/valid-palindrome/description/

function conversion(str){
    return str.toLowerCase().replace(/[^a-z0-9]/g, '');
}

let isPalindrome = function(s) {
    // remove all non-alphanumeric characters from string
    s = conversion(s);

    // now reverse the string
    let str = s.split("").reverse().join("");
    
    // check whether reversed string 'str' is equal to input string 's'
    return s === str ? true : false;
};

// let inpStr = "race a car";

let inpStr = "A man, a plan, a canal: Panama";
console.log(isPalindrome(inpStr));


