
// Problem link - https://leetcode.com/problems/clear-digits/description/?envType=problem-list-v2&envId=string

let clearDigits = function(s) {
    // step 1 - use stack to store non-digit characters
    let stack = [];

    // step 2 - iterate on each character of input string `s`
    for(let ch of s){
        // step 3 - check if it is digit, remove the closest non-digit from stack
        if(/\d/.test(ch)){
            // check stack size to remove top element
            if(stack.length > 0){
                stack.pop();
            }
        }else{
            // step 4 - if current char is non-digit then push into stack
            stack.push(ch)
        }
    }

    // step 5 - construct and return the final output string from stack
    return stack.join('');
};

// const s = "abc";

const s = "cb34";
console.log(clearDigits(s));


