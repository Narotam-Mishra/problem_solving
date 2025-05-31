
// Problem link - https://leetcode.com/problems/remove-duplicate-letters/?envType=problem-list-v2&envId=string

let removeDuplicateLetters = function(s) {
    // step 1 - count frequency of each letter of `s`
    const count = {};
    for(let ch of s){
        count[ch] = (count[ch] || 0) + 1;
    }

    // step 2 - initialize stack and set data structures
    // build resultant string in stack
    const stack = [];
    
    // track which character is already in resultant string
    const seen = new Set();

    // step 3 - iterate on each character of `s`
    for(let char of s){
        // decrease count since we are processing this occurrence
        count[char]--;

        // step 4 - if current charcter `char` already exist in seen set then skip it
        if(seen.has(char)){
            continue;
        }

        // current character `char` is smaller than stack top (for lexicographical order)
        // Stack top appears later in string (count > 0)
        // step 5 - this step ensures we always make the lexicographically smallest choice possible
        while(stack.length > 0 && stack[stack.length - 1] > char && count[stack[stack.length - 1]] > 0){
            const removed = stack.pop();
            seen.delete(removed);
        }

        // step 7 - add current character `char` to resultant stack and `seen` set
        stack.push(char);
        seen.add(char);
    }

    // step 8 - return stack by converting it into string
    return stack.join('');
};

// const s = "bcabc";

const s = "cbacdcbc";
console.log(removeDuplicateLetters(s));
