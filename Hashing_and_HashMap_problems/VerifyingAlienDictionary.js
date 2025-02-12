
// Problem link - https://leetcode.com/problems/verifying-an-alien-dictionary/description/?envType=problem-list-v2&envId=hash-table

let isAlienSorted = function(words, order) {
    // step 1 - create a mapping of the alien alphabet
    // this helps us quickly look up the "weight" of each letter
    const orderMap = new Map();
    for(let i=0; i<order.length; i++){
        orderMap.set(order[i], i);
    }
    
    // step 2 - compare adjacent words
    for(let i=0; i<words.length-1; i++){
        const word1 = words[i];
        const word2 = words[i+1];

        // get length of shorter word
        const minLength = Math.min(word1.length, word2.length);
        let isDifferent = false;

        // compare the two words character by character
        for(let j=0; j<minLength; j++){
            const weight1 = orderMap.get(word1[j]);
            const weight2 = orderMap.get(word2[j]);

            // if characters are different
            if(weight1 !== weight2){
                // if current character in word1 has higher weight,
                // then words are not sorted
                if(weight1 > weight2){
                    return false;
                }

                // mark that we found a difference and break
                isDifferent = true;
                break;
            }
        }

        // if no difference found in common prefix and word1 is longer,
        // then words are not sorted (e.g., "apple" vs "app")
        if(!isDifferent && word1.length > word2.length){
            return false;
        }
    }

    // step 3 - if all pairs are in order, return true
    return true;
};

const words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz";

// const words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz";

// const words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz";
console.log(isAlienSorted(words, order));
