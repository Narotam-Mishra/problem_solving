
// Problem link - https://leetcode.com/problems/maximum-product-of-word-lengths/?envType=problem-list-v2&envId=bit-manipulation

let maxProduct = function(words) {
    const n = words.length;
    const bitmask = new Array(n).fill(0);
    let maxProd = 0;

    // step 1: convert each word to a bit mask
    for(let i=0; i<n; i++){
        let word = words[i];

        // create bit mask for current word
        for(let ch of word){
            // set corresponding bit for each character
            // 'a' is 97 in ASCII, so char.charCodeAt(0) - 97 gives 0-25
            bitmask[i] |= 1 << (ch.charCodeAt(0) - 97);
        }
    }

    // step 2: compare each pair of words using their bit masks
    for(let i=0; i<n; i++){
        for(let j=i+1; j<n; j++){
            // if AND of masks is 0, words have no common letters
            if((bitmask[i] & bitmask[j]) === 0){
                // calculate maximum product
                let prod = words[i].length * words[j].length;
                maxProd = Math.max(maxProd, prod);
            }
        }
    }

    // return maximum product 'maxprod'
    return maxProd;
};

let words = ["abcw","baz","foo","bar","xtfn","abcdef"];

// let words = ["a","ab","abc","d","cd","bcd","abcd"];

// let words = ["a","aa","aaa","aaaa"];
console.log(maxProduct(words));
