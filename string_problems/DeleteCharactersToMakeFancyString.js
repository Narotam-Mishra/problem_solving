
// Problem link - https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=problem-list-v2&envId=string

let makeFancyString = function(s) {
    // step 1 - store resultant string in `res` array
    const res = [];

    // step 2 - iterate on input string `s`
    for(let i=0; i<s.length; i++){
        // calculate of length `len` of result `res` array
        let len = res.length;

        // step 3 - check if last two characters in `res` are same as current character
        if(len >= 2 && res[len-1] === s[i] && res[len-2] === s[i]){
            // skip this character to avoid three consecutive characters
            continue;
        }

        // step 4 - otherwise add character to `res` array
        res.push(s[i]);
    }

    // step 5 - return `res` array by converting it into string
    return res.join('');
};

// const s = "leeetcode";

// const s = "aaabaaaa";

const s = "aab"
console.log(makeFancyString(s));
