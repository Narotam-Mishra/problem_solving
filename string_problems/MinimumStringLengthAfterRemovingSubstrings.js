
// Problem link - https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/?envType=problem-list-v2&envId=string

let minLength = function(s) {
    // step 1 - uing stack to perform string operation
    let stack = [];

    // step 2 - iterate on each chacter of `s`
    for(let char of s){
        // get stack's top
        let top = stack[stack.length - 1];

        // step 3 - if top + char form "AB" or "CD", then remove them, (pop top, skip char)
        if((top === 'A' && char === 'B') || (top === 'C' && char === 'D')){
            // remove pair
            stack.pop();
        }else{
            // step 4 - no pair formed, keep the character
            stack.push(char);
        }
    }

    // step 5 - return length of remaining characters in stack form the reduced string
    return stack.length;
};

// const s = "ABFCACDB";

const s = "ACBBD";
console.log(minLength(s));
