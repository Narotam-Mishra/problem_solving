
// Problem link - https://leetcode.com/problems/find-maximum-number-of-string-pairs/?envType=problem-list-v2&envId=string

let maximumNumberOfStringPairs1 = function(words) {
    // step 1 - counter to count maximum number of pairs
    let count = 0;

    // step 2 - iterate on each word of words
    for(let i=0; i<words.length; i++){
        // step 3 - iterate on each pair
        for(let j=i+1; j<words.length; j++){
            // step 4 - reverse the next string
            let revStr = words[j].split('').reverse().join('');

            // step 5 - check if ith word can be paired with jth word
            if(words[i] === revStr){
                // increment the counter
                count++;
            }
        }
    }

    // step 6 - return the counter `count`
    return count;
};

let maximumNumberOfStringPairs = function(words) {
    // step 1 - use a set to keep track of words we've seen but not yet paired
    const seen = new Set();
    let count = 0;

    // step 2 - iterate through each word of words
    for(let word of words){
        // step 3 - reverse the current word
        const revered = word[1] + word[0];

        // step 4 - check if the revered word has been seen before
        if(seen.has(revered)){
            count++;
        }else{
            // step 5 - if no match found, add to set
            seen.add(word);
        }
    }

    // step 6 - return maximum number of reversed string pairs
    return count;
};

const words = ["cd","ac","dc","ca","zz"];

// const words = ["ab","ba","cc"];

// const words = ["aa","ab"];
console.log(maximumNumberOfStringPairs(words));
