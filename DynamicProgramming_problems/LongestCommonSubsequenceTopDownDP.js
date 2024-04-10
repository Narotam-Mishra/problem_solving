
// Problem link - https://leetcode.com/problems/longest-common-subsequence/

// Approach - using Top Down DP
let dp;

function findLCSTopDownDP(s1,s2,i,j){
    // Base case: if any of the string has been exhausted then return 0
    if(i === -1 || j === -1) return 0;
    
    // if dp[i][j] is already calculated then return dp[i][j]
    if(dp[i][j] != -1) return dp[i][j]

    // Recursive case1: if the current character from each string is equal
    // then add current character length and recursively call the function on remaining characters
    if(s1[i] === s2[j]){
        return dp[i][j] =  1 + findLCSTopDownDP(s1,s2, i-1, j-1);
    }else{
        // Recursive case2: either exclude current character from 1st string or 2nd string
        let l1 = findLCSTopDownDP(s1,s2,i-1,j)
        let l2 = findLCSTopDownDP(s1,s2,i,j-1)
        // and return maximum length 
        return dp[i][j] = Math.max(l1,l2);
    }
}

let longestCommonSubsequence1 = function(text1, text2) {
    dp = new Array(1005).fill(-1).map(() => new Array(1005).fill(-1));
    return findLCSTopDownDP(text1, text2, text1.length-1, text2.length-1);
};

let dpArr = Array.from({ length: 1005 }, () => Array(1005));

function findLCSBottomUp(s1, s2){
    for(let i = 0; i <= s1.length; i++){
        for(let j = 0; j <= s2.length; j++){
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

let longestCommonSubsequence = function(text1, text2) {
    return findLCSBottomUp(text1, text2);
};

let text1 = "abcde"
let text2 = "ace" 

// let text1 = "abc"
// let text2 = "abc" 

// let text1 = "abc"
// let text2 = "def" 
console.log(longestCommonSubsequence(text1, text2));