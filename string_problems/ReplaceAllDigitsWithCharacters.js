
// Problem link - https://leetcode.com/problems/replace-all-digits-with-characters/description/?envType=problem-list-v2&envId=string

let replaceDigits = function(s) {
    // step 1 - convert input string `s` to char array
    const arr = s.split('');

    // step 2 - iterate through each character and perform shift operation
    for(let i=1; i<arr.length; i+=2){
        // get character
        let ch = arr[i-1];

        // get digit
        let digit = Number(s[i]);

        // step 3 - perform shift operation 
        arr[i] = String.fromCharCode(ch.charCodeAt(0) + digit);
    }

    // step 4 - return char array `arr` by convert back to string
    return arr.join('');
};

// const s = "a1c1e1";

const s = "a1b2c3d4e";
console.log(replaceDigits(s));
