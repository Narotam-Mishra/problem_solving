
// Problem link - https://leetcode.com/problems/longest-palindromic-subsequence/description/

// Approach1 - using LCS Bottom up DP Utility
function findLCSBottomUpUtility(s1,s2){
    let dpArr = Array.from({ length: 1005 }, () => Array(1005));
    for(let i=0; i <= s1.length; i++){
        for(let j=0; j <= s2.length; j++){
            if(i === 0 || j === 0) dpArr[i][j] = 0;
            else{
                if(s1[i - 1] === s2[j - 1]){
                    dpArr[i][j] = 1 + dpArr[i - 1][j - 1];
                }else{
                    dpArr[i][j] = Math.max(dpArr[i - 1][j], dpArr[i][j - 1]);
                }
            }
        }
    }
    return dpArr[s1.length][s2.length];
}

let longestPalindromeSubseq1 = function(s) {
    let s1 = s.split('').reverse().join('');
    return findLCSBottomUpUtility(s,s1);
};

// Approach2 - using Top Down DP

let dp;
function findLPSTopDownDP(s,i,j){
    // Base case if bothe indices i and j are equal return 1
    if(i === j) return 1;
    
    // if ith index surpass jth index that means no pallindromic string is possible
    // return 0
    if(i > j) return 0;

    // if dp[i][j] is already computed then return dp[i][j]
    if(dp[i][j] !== -1) return dp[i][j]
    
    // if terminal characters are equal , add their contribution
    // and recursively call the function on remaning characters
    if(s[i] === s[j]){
        return dp[i][j] = 2 + findLPSTopDownDP(s, i + 1, j - 1);
    }else{
        // otherwise recursively call the function on remaning characters
        return dp[i][j] = Math.max(findLPSTopDownDP(s, i+1, j), findLPSTopDownDP(s, i, j-1));
    }
}

let longestPalindromeSubseq = function(s) {
    // initialize 2-DP array with -1
    dp = new Array(1005).fill(-1).map(() => new Array(1005).fill(-1));
    return findLPSTopDownDP(s,0,s.length-1);
};

let str = "bbbab"

// let str = "cbbd"
console.log(longestPalindromeSubseq(str));
