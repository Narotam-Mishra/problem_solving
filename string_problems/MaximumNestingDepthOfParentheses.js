
// Problem link - https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/?envType=problem-list-v2&envId=string

let maxDepth = function(s) {
    // step 1 - track current depth in `depth` 
    // and maximum depth in `maxiDepth`
    let depth = maxiDepth = 0;

    // step 2 - iterate on string `s`
    for(let ch of s){
        if(ch === '('){
            // step 3 - increase depth for every opening parenthesis
            depth++;
            // step 4 - find maximum depth `maxiDepth`
            maxiDepth = Math.max(maxiDepth, depth);
        }else if(ch === ')'){
            // step 5 - decrease depth for every closing parenthesis
            depth--;
        }
    }

    // step 6 - return max depth
    return maxiDepth;
};

// const s = "(1+(2*3)+((8)/4))+1";

// const s = "(1)+((2))+(((3)))";

const s = "()(())((()()))";
console.log(maxDepth(s));
