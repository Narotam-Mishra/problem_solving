
// Problem link - https://leetcode.com/problems/maximum-repeating-substring/description/?envType=problem-list-v2&envId=string

let maxRepeating = function(sequence, word) {
    // step 1 - maximum number of times word can repeat within sequence
    let k = 1;

    // step 2 - repeat word k-times and check if it is substring of `sequence`
    while(sequence.includes(word.repeat(k))){
        // increment k
        k++;
    }

    // step 3 - the loop will break when substring is not found, so return k - 1
    return k - 1;
};

// const sequence = "ababc", word = "ab";

// const sequence = "ababc", word = "ba";

const sequence = "ababc", word = "ac";
console.log(maxRepeating(sequence, word));
