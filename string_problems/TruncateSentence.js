
// Problem link - https://leetcode.com/problems/truncate-sentence/description/?envType=problem-list-v2&envId=string

let truncateSentence = function(s, k) {
    // truncated sentence containing only the first k words.
    return s.split(' ').slice(0, k).join(' ')
};

// const s = "Hello how are you Contestant", k = 4;

// const s = "What is the solution to this problem", k = 4;

const s = "chopper is not a tanuki", k = 5;
console.log(truncateSentence(s, k));
