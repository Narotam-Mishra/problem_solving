
// Problem link - https://leetcode.com/problems/longest-palindromic-subsequence/

// Approach - using Recursion

function findLPSRecursion(s, i, j){
    // Base case if bothe indices i and j are equal return 1
    if(i === j) return 1;
    
    // if ith index surpass jth index that means no pallindromic string is possible
    // return 0
    if(i > j) return 0;
    
    // if terminal characters are equal , add their contribution
    // and recursively call the function on remaning characters
    if(s[i] === s[j]){
        return 2 + findLPSRecursion(s, i + 1, j - 1);
    }else{
        // otherwise recursively call the function on remaning characters
        return Math.max(findLPSRecursion(s, i+1, j), findLPSRecursion(s, i, j-1));
    }
}

let longestPalindromeSubseq = function(s) {
    return findLPSRecursion(s, 0, s.length-1);
};

let str = "bbbab";
console.log(longestPalindromeSubseq(str));