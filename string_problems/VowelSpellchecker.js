
// Problem link - https://leetcode.com/problems/vowel-spellchecker/?envType=daily-question&envId=2025-09-14

let spellchecker = function(wordlist, queries) {
    // step 1: create data structures for efficient lookup
    // store all words for exact match (case sensitive)
    const exactWords = new Set(wordlist);

    // map for capitalization matches 
    const capWords = new Map();

    // map for vowel pattern matches 
    const vowelsMap = new Map();

    // helper function to convert vowels to a pattern (replace vowels with `*`)
    const getVowelsPattern = (word) => {
        return word.toLowerCase().replace(/[aeiou]/g, '*');
    }

    // step 2 - iterate on wordlist and populate map
    for(const word of wordlist){
        const lowerWord = word.toLowerCase();
        const vowelWordPattern = getVowelsPattern(word);

        // store first occurrence for capitalization matches
        if(!capWords.has(lowerWord)){
            capWords.set(lowerWord, word);
        }

        // store first occurrence for vowel pattern matches
        if(!vowelsMap.has(vowelWordPattern)){
            vowelsMap.set(vowelWordPattern, word);
        }
    }

    // step 3 - process each query according to given precedence rule
    const res = [];
    for(let query of queries){
        let ans = "";

        // rule1 - check for exact match
        if(exactWords.has(query)){
            ans = query;
        }

        // rule 2 - check for capitalization match (case insensitive)
        else if(capWords.has(query.toLowerCase())){
            ans = capWords.get(query.toLowerCase());
        }

        // rule 3 - check for vowel error match
        else{
            const queryVowelPattern = getVowelsPattern(query);
            if(vowelsMap.has(queryVowelPattern)){
                ans = vowelsMap.get(queryVowelPattern);
            }

            // rule 4 - for no match, return empty 
            // for which ans is set to ""
        }

        // store result for current query
        res.push(ans);
    }

    // step 4 - return final result `res`
    return res;
};

const wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"];

// const wordlist = ["yellow"], queries = ["YellOw"];
console.log(spellchecker(wordlist, queries));