
// Problem link - https://leetcode.com/problems/build-an-array-with-stack-operations/description/

let buildArray = function(target, n) {
    // Initialize an empty stack to store operations
    let stack = [];
    // Initialize a variable to track the current integer in the stream
    let i = 1;

    // Iterate through each number in the target array
    for(let num of target){
        // While the current integer in the stream is less than the target number
        while(i < num){
            // Push the current integer to the stack
            stack.push("Push");
            // Pop the integer immediately after pushing
            stack.push("Pop");
            // Move to the next integer in the stream
            i++;
        }
        // Push the target number to the stack
        stack.push("Push");
        // Move to the next integer in the stream
        i++;
    }
    // Return the stack operations
    return stack;
};

// let target = [1,3], n = 3;

let target = [1,2,3], n = 3;
console.log(buildArray(target, n));