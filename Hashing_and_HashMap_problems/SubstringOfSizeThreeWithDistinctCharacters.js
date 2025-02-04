
// Problem link : https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/?envType=problem-list-v2&envId=hash-table

let countGoodSubstrings1 = function(s) {
    // edge case:
    if(s.length < 3){
        return 0;
    }

    // step 1 - initialize variable `count` to tack good substrings
    let count = 0;

    // step 2 - iterate through the string, extracting substrings of length 3
    for(let i=0; i<=s.length - 3; i++){
        // extract a substring of length 3
        const subString = s.substring(i, i+3);

        // step 3 - convert the substring to a Set to check for uniqueness
        const uniqueChars = new Set(subString);

        // step 4 - if the set size is 3, all characters are unique
        if(uniqueChars.size === 3){
            count++;
        }
    }

    // step 5 - return the count of good substrings
    return count;
};

let countGoodSubstrings = function(s) {
    // edge case
    if(s.length < 3) return 0;

    // step 1 - initialize variable `count` to tack good substrings
    let count = 0;

    // step 2 - iterate through the string, 
    for(let i=0; i<=s.length-3; i++){
        // extracting substrings of length 3
        const a = s[i], b =  s[i+1], c = s[i+2];
        // check all three characters are unique
        if(a !== b && a !== c && b !== c){
            // increment count if above condition met
            count++;
        }
    }

    // step 3 - return the counter `count`
    return count;
};

const s = "xyzzaz";

// const s = "aababcabc";
console.log(countGoodSubstrings(s));
