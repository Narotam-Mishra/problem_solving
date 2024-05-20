
// Problem link - https://leetcode.com/problems/implement-queue-using-stacks/

// Approach - 1 (enqueue efficient)
let MyQueue1 = function() {
    // used two stacks where stack1 is primary stack
    this.stack1 = [];
    this.stack2 = []
};

/** 
 * @param {number} x
 * @return {void}
 */
MyQueue1.prototype.push = function(x) {
    this.stack1.push(x);
};

/**
 * @return {number}
 */
// pop() method wil removes the element from the front of the queue and returns it.
MyQueue1.prototype.pop = function() {
    // used stack2 as secondary stack to empty all stack1 elements into it
    if(this.stack2.length === 0){
        this.transferStack1ToStack2();
    }
    // stack1's front element will now be in stack2's top
    // so we can pop() front of stack1
    return this.stack2.pop();
};

/**
 * @return {number}
 */
//peek() method returns the element at the front of the queue.
MyQueue1.prototype.peek = function() {
    // used stack2 as secondary stack to empty all stack1 elements into it
    if(this.stack2.length === 0){
        this.transferStack1ToStack2();
    }
    // stack1's front element will now be in stack2's top
    return this.stack2[this.stack2.length - 1];
};

/**
 * @return {boolean}
 */
MyQueue1.prototype.empty = function() {
    return (this.stack1.length === 0) && (this.stack2.length === 0);
};

// method to transfer stack1 elements to stack2
MyQueue1.prototype.transferStack1ToStack2 = function(){
    while(this.stack1.length > 0){
        this.stack2.push(this.stack1.pop());
    }
};

// Approach - 2 (dequeue efficient)
let MyQueue = function() {
    // used two stacks
    this.st1 = [];
    this.st2 = [];
};

/** 
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function(x) {
    // Move all elements from stack2 to stack1
    while(this.st2.length > 0){
        this.st1.push(this.st2.pop());
    }

    this.st1.push(x);

    // Move all elements back to stack2
    while(this.st1.length > 0){
        this.st2.push(this.st1.pop());
    }
};

/**
 * @return {number}
 */
MyQueue.prototype.pop = function() {
    return this.st2.pop();
};

/**
 * @return {number}
 */
MyQueue.prototype.peek = function() {
    return this.st2[this.st2.length - 1];
};

/**
 * @return {boolean}
 */
MyQueue.prototype.empty = function() {
    return this.st2.length === 0;
};

// Create an instance of MyQueue (PushEfficient)
const queue = new MyQueue();

// Push some elements into the queue
queue.push(1);
queue.push(2);
queue.push(3);
queue.push(4);

// Print the queue
console.log("Queue after pushing elements:", queue);

// Peek at the front element
console.log("Peek:", queue.peek());

// Pop elements from the queue
console.log("Pop:", queue.pop());
console.log("Pop:", queue.pop());

