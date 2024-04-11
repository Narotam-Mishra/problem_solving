
// Problem link - https://leetcode.com/problems/longest-palindromic-subsequence/description/

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

let longestPalindromeSubseq = function(s) {
    let s1 = s.split('').reverse().join('');
    return findLCSBottomUpUtility(s,s1);
};

// let str = "bbbab"

let str = "cbbd"
console.log(longestPalindromeSubseq(str));
