
// Problem link : https://leetcode.com/problems/valid-palindrome-ii/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

// helper function to check if a substring of string 's' is a palindrome
function checkPalindromeInRange(str, left, right){
    while(left < right){
        // mismatch found
        if(str[left] != str[right]) return false;
        
        left++;
        right--;
    }
    // No mismatches, it's a palindrome
    return true
}

let validPalindrome = function(s) {
    // using two pointers approach
    l = 0, r = s.length - 1;

    // move pointers towards each other
    while(l < r){
        if(s[l] != s[r]){
            // if mismatch found, try skipping either the left or right character
            return checkPalindromeInRange(s, l+1, r) || checkPalindromeInRange(s, l, r- 1);
        }
        l++;
        r--;
    }
    // if no mismatches, or it's already a palindrome
    return true;
};

// let str = "abca";

// let str = "aba";

let str = "abc";
console.log(validPalindrome(str));
