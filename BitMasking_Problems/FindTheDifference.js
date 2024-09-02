
// Problem link : https://leetcode.com/problems/find-the-difference/description/?envType=problem-list-v2&envId=bit-manipulation

let findTheDifference = function(s, t) {
    let res = 0;

    // XOR all characters in both strings
    for(let i=0; i<s.length; i++){
        res ^= s.charCodeAt(i);
    }

    for(let i=0; i<t.length; i++){
        res ^= t.charCodeAt(i);
    }

    // convert the result to a character
    return String.fromCharCode(res);
};

let s = "", t = "y"

// let s = "abcd", t = "abcde"
console.log(findTheDifference(s,t));
