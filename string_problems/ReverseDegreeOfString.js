
// Problem link - https://leetcode.com/problems/reverse-degree-of-a-string/description/?envType=problem-list-v2&envId=string

let reverseDegree = function(s) {
    // step 1 - initialize variable to store reverse degree `rd` 
    let rd = 0;

    // step 2 - iterate on each character of `s`
    for (let i = 0; i < s.length; i++) {
        //step 3 - calculate the reverse position in the alphabet
        let reversePosition = 26 - (s[i].charCodeAt(0) - 'a'.charCodeAt(0));
        // step 4 - multiply with the 1-indexed position in the string
        rd += reversePosition * (i + 1);
    }

    // step 5 - return reverse degree `rd`
    return rd;
};

// const s = "abc";

const s = "zaza";
console.log(reverseDegree(s));
