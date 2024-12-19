
// Problem link : https://leetcode.com/problems/counting-words-with-a-given-prefix/description/

let prefixCount = function(words, pref) {
    // intialize counter `countPrefix` to count number of prefix exist in words array
    let countPrefix = 0;
    
    // step 1 - iterate through words array
    for(const word of words){
        // step 2 - check if prefix exists
        if(word.startsWith(pref)){
            // step 3 - increment the prefix count
            countPrefix++;
        }
    }

    // step 4 - return `countPrefix` counter
    return countPrefix;
};

// let words = ["pay","attention","practice","attend"], pref = "at";

let words = ["leetcode","win","loops","success"], pref = "code";
console.log(prefixCount(words, pref));
