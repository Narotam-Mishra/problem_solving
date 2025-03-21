
// Problem link - https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=problem-list-v2&envId=string

// utility function to check string is palindromic or not
function isPalindromicString(str){
    let s = 0, e = str.length - 1;
    while(s < e){
        if(str[s] !== str[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

let firstPalindrome = function(words) {
    // step 1 - iterate on each string
    for(let word of words){
        // step 2 - check if it is palindromic string or not
        if(isPalindromicString(word)){
            // step 3 - return word immediately if it is palindromic
            return word;
        }
    }

    // step 4 - otherwise return empty string
    return '';
};

const words = ["abc","car","ada","racecar","cool"];

// const words = ["notapalindrome","racecar"];

// const words = ["def","ghi"];
console.log(firstPalindrome(words));
