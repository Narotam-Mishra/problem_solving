
// Problem link : https://leetcode.com/problems/count-prefixes-of-a-given-string/description/

let countPrefixes1 = function(words, s) {
    let cp = 0;
    for(let word of words){
        if(s.startsWith(word)){
            cp++;
        }
    }
    return cp;
};

let countPrefixes = function(words, s) {
    // using the reduce() method to accumulate the count of valid prefixes
    return words.reduce((prefixCount, currWord) => {
        // check if 's' starts with the current word using startsWith()
        // 's.startsWith(currentWord)' returns true (1) if currentWord is a prefix, otherwise false (0)
        return prefixCount + s.startsWith(currWord);
    }, 0);  //initialize prefixCount (accumulator) to 0
};

let words = ["a","b","c","ab","bc","abc"], s = "abc";

// let words = ["a","a"], s = "aa";
console.log(countPrefixes(words, s));
