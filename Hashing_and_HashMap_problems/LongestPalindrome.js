
// Problem link : https://leetcode.com/problems/longest-palindrome/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

/**
 * @param {string} s
 * @return {number}
 */
let longestPalindrome = function(s) {
    // step 1: count the frequency of each character
    // using object as map
    let charCount = {};

    for(const ch of s){
        if(charCount[ch]){
            charCount[ch]++;
        }else{
            charCount[ch] = 1
        }
    }

    let longestPalindromeLength = 0;
    let hasOdd = false;

    // step 2: calculate contributions to the palindrome
    for(const count of Object.values(charCount)) {
        if(count % 2 === 0){
            // if even, all characters can contribute to the palindrome
            longestPalindromeLength += count;
        }else{
            // if odd, use the largest even part and flag that an odd exists
            longestPalindromeLength += count - 1;
            hasOdd = true;
        }
    }

    // step 3: add 1 if there's an odd character to be the center
    if(hasOdd){
        longestPalindromeLength += 1;
    }

    // return longest palindrome length 'longestPalindromeLength'
    return longestPalindromeLength;
};

// let str = "abccccdd";

let str = "a";
console.log(longestPalindrome(str));
