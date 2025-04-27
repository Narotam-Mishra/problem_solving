
// Problem link - https://leetcode.com/problems/remove-palindromic-subsequences/description/?envType=problem-list-v2&envId=string

// utility function to check if string is palindrome or not
function isPalindrome(str){
    let l = 0, r = str.length - 1;

    while(l < r){
        if(str[l] !== str[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

let removePalindromeSub = function(s) {
    // step 1 - if input string `s` is palindrome then we can remove it in 1 step
    // otherwise , remove all a's in one step and all b's in another step
    return isPalindrome(s) ? 1 : 2;
};

// const s = "ababa";

// const s = "abb";

const s = "baabb";
console.log(removePalindromeSub(s));
