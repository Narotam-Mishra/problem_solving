
// Problem link : https://leetcode.com/problems/string-matching-in-an-array/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let stringMatching1 = function(words) {
    return words.filter(w1 => {
        return words.find(w2 => {
            // ensure we are comparing different words
            if(w2 !== w1){
                // check if word1 is a substring of word2
                if(w2.includes(w1)){
                    // found a match
                    return true;
                }
            }
            // no match
            return false;
        })
    })
};

let stringMatching = function(words) {
    // step 1: sort words by length (shorter strings come first)
    words.sort((a,b) => a.length - b.length);

    // store result in res
    let res = new Set();

    // step 2: check each string against longer strings
    for(let i=0; i<words.length; i++){
        for(let j=i+1; j<words.length; j++){
            // check if words[i] is a substring of words[j]
            if(words[j].includes(words[i])){
                // add to the result set 'res'
                res.add(words[i]);
                // no need to check further for this word
                break;
            }
        }
    }
    // step 3: convert result set to an array and return
    return Array.from(res);
};

let words = ["mass","as","hero","superhero"];

// let words = ["leetcode","et","code"];

// let words = ["blue","green","bu"];
console.log(stringMatching(words));
