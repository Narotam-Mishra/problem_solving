
// Problem link - https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=problem-list-v2&envId=string

let countPrefixSuffixPairs = function(words) {
    // step 1 - intialize count
    let count = 0;

    // step 2 - iterate on each word
    for(let i=0; i<words.length; i++){
        // get current word
        let curStr = words[i];
        // step 3 - iterate on each pair
        for(let j=i+1; j<words.length; j++){
            // step 4 - check if prefix and suffix exist
            if(words[j].startsWith(curStr) && words[j].endsWith(curStr)){
                count++;
            }
        }
    }

    // step5 - return count
    return count
};

// const words = ["a","aba","ababa","aa"];

// const words = ["pa","papa","ma","mama"];

const words = ["abab","ab"];
console.log(countPrefixSuffixPairs(words));
