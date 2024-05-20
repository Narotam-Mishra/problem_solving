
// Problem link - https://leetcode.com/problems/valid-parentheses/description/

let isValid = function(s) {
    let stack = [];
    for(let i=0; i<s.length; i++){
        let curChar = s[i];
        // if current character is opening parentheses, then push into stack
        if(curChar === '(' || curChar === '{' || curChar === '['){
            stack.push(curChar);
        }else{
            // if stack is empty then return false
            if(stack.length === 0) return false;
            // Pop the top element from the stack
            let top = stack.pop();
            // Check if the current closing bracket matches the last opening bracket
            if((curChar === ')' && top !== '(') || (curChar === '}' && top !== '{') || (curChar === ']' && top !== '[')){
                return false;
            }
        }
    }
    return stack.length === 0;
};

let str = "()[]{}";

// let str = "(]";
console.log(isValid(str));