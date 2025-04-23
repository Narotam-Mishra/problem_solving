
// Problem link - https://leetcode.com/problems/find-special-substring-of-length-k/description/?envType=problem-list-v2&envId=string

let hasSpecialSubstring = function(s, k) {
    // edge cases:
    if(s.length < k) return false;

    // find string length
    let n = s.length;

    // step 1 - iterate through string in chunks
    for(let i=0; i<=n-k;){
        let currChar = s[i];
        let j = i;

        // step 2 - find end of the current run of the same character
        while(j < n && s[j] === currChar){
            j++;
        }

        // find length of current substring
        const runLength = j - i;

        // step 3 - if we found a run of exactly length k
        if(runLength === k){
            // check the character before (if exist)
            const beforeValid = (i === 0) || (s[i-1] !== currChar);

            // check the character after (if exist)
            const afterValid = (j === n) || (s[j] !== currChar);

            if(beforeValid && afterValid){
                return true;
            }
        }

        // move to next character after this run
        i = j;
    }

    // step 4 - return false if none of the conditions satisfy
    return false;
};

// const s = "aaabaaa", k = 3;

const s = "abc", k = 2;
console.log(hasSpecialSubstring(s, k));
