
// Problem link - https://leetcode.com/problems/number-of-changing-keys/description/?envType=problem-list-v2&envId=string

let countKeyChanges = function(s) {
    // step 1 - intialize count
    let count = 0;

    // step 2 - change input string `s` to lowercase
    s = s.toLowerCase();

    // step 3 - iterate on input string `s`
    for(let i=1; i<s.length; i++){
        // get current character of string
        let ch = s[i];
        // step 4 - check if current current is not equsl to previous then increment counter
        if(ch !== s[i-1]) count++;
    }

    // step 5 - return count
    return count;
};

// const s = "aAbBcC";

const s = "AaAaAaaA";
console.log(countKeyChanges(s));
