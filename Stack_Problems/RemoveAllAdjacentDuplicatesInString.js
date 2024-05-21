
// Problem link - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

let removeDuplicates = function(s) {
    let stack = [];
    for(let i=0; i<s.length; i++){
        if(stack.length > 0 && s[i] === stack[stack.length - 1]){
            // if current character of string is equal to stack's top then pop from stack
            stack.pop();
        }else{
            // otherwise push current character of string into string
            stack.push(s[i]);
        }
    }
    return stack.join('');
};

let str = "abbaca";
console.log(removeDuplicates(str));