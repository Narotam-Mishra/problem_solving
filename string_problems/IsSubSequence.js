
// Problem link : https://leetcode.com/problems/is-subsequence/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let isSubsequence = function(s, t) {
    // pointer for source string 's'
    let i = 0;

    // pointer for target string 't'
    for(let j=0; j<t.length; j++){
        // check if the current character in t matches the current character in s
        if(t[j] === s[i]){
            i++;
        }

        // if we've found all characters of s in t, we can return true early
        if(i === s.length) return true;
    }

    // if we finished the loop and haven't matched all characters in s
    return i === s.length;
};

// let s = "abc", t = "ahbgdc"

let s = "axc", t = "ahbgdc";
console.log(isSubsequence(s, t));
