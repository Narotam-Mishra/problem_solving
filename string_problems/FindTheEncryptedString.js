
// Problem link - https://leetcode.com/problems/find-the-encrypted-string/description/?envType=problem-list-v2&envId=string

let getEncryptedString = function(s, k) {
    // step 1 - initialize a `res` string to store result
    let res = "";

    // find length of input string `s`
    let n = s.length;

    // step 2 - iterate on input string `s`
    for(let i=0; i<n; i++){
        // step 3 - find `res`
        res += s[(i + k) % n];
    }

    // step 4 - return `res`
    return res;
};

// const s = "dart", k = 3;

const s = "aaa", k = 1;
console.log(getEncryptedString(s, k));
