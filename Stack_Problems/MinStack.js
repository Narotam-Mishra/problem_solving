
// Problem link - https://leetcode.com/problems/min-stack/description/

let MinStack = function() {
    // using array as stack to implement basic stack's functions
    this.stack = [];
    // Auxiliary stack to track minimum elements
    this.minStack = [];
};

/** 
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function(val) {
    // Push the value onto the main stack
    this.stack.push(val);
    // If the minStack is empty or the new value is less than or equal to the current minimum,
    // push the new value onto the minStack
    if(this.minStack.length === 0 || val <= this.getMin()){
        this.minStack.push(val);
    }
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    // If the value being popped is the current minimum, also pop it from the minStack
    if(this.stack.pop() === this.getMin()){
        this.minStack.pop();
    }
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    // Returns the top element of the stack without removing it
    return this.stack[this.stack.length - 1];
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
    // Retrieves the minimum element in the stack
    return this.minStack[this.minStack.length - 1];
};

let minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
console.log(minStack.getMin()); // return -3
minStack.pop();
console.log(minStack.top());    // return 0
console.log(minStack.getMin()); // return -2