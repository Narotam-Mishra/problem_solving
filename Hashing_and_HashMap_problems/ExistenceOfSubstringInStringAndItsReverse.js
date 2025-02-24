
// Problem link - https://leetcode.com/problems/existence-of-a-substring-in-a-string-and-its-reverse/description/?envType=problem-list-v2&envId=hash-table

let isSubstringPresent = function(s) {
    // edge case:
    if(s.length === 2){
        return s[0] == s[1];
    }

    // step 1 - store all substrings of length 2 from s in set
    const subStringsSet = new Set();
    for(let i=0; i<s.length-1; i++){
        subStringsSet.add(s[i]+s[i+1]);
    }

    // step 2 - check if any substring from reversed string exists in the set
    for(let i=s.length-1; i>=0; i--){
        if(subStringsSet.has(s[i]+s[i-1])){
            // return true if substring found
            return true;
        }
    }
    
    // step 3 - if no substring found, return false
    return false;
};

const s = "leetcode";

// const s = "abcba";

// const s = "abcd";
console.log(isSubstringPresent(s));
