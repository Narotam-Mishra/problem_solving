
// Problem link - https://leetcode.com/problems/design-front-middle-back-queue/

let FrontMiddleBackQueue = function() {
    this.queue = [];
};

/** 
 * @param {number} val
 * @return {void}
 */
FrontMiddleBackQueue.prototype.pushFront = function(val) {
    // push element at front of queue using unshift()
    this.queue.unshift(val);
};

/** 
 * @param {number} val
 * @return {void}
 */
FrontMiddleBackQueue.prototype.pushMiddle = function(val) {
    // push element at the middle of queue using splice()
    let midIdx = Math.floor(this.queue.length/2);
    this.queue.splice(midIdx, 0, val);
};

/** 
 * @param {number} val
 * @return {void}
 */
FrontMiddleBackQueue.prototype.pushBack = function(val) {
    // push element at the back of queue using push()
    this.queue.push(val);
};

/**
 * @return {number}
 */
FrontMiddleBackQueue.prototype.popFront = function() {
    if(this.queue.length === 0) return -1;
    // pop element from the back of queue using shift()
    let val = this.queue.shift();
    return val;
};

/**
 * @return {number}
 */
FrontMiddleBackQueue.prototype.popMiddle = function() {
    // pop middle element from the queue using splice()
    if(this.queue.length === 0) return -1;
    let midIdx = Math.floor(this.queue.length/2);
    if(this.queue.length % 2 === 0) midIdx--;
    let val = this.queue.splice(midIdx, 1)[0];
    return val;
};

/**
 * @return {number}
 */
FrontMiddleBackQueue.prototype.popBack = function() {
    // pop back/rear element from the queue using pop()
    if(this.queue.length === 0) return -1;
    let val = this.queue.pop();
    return val;
};

let obj = new FrontMiddleBackQueue();
obj.pushFront(1);
obj.pushBack(2);
obj.pushMiddle(3);
obj.pushMiddle(4);

console.log(obj.popFront());
console.log(obj.popMiddle());
console.log(obj.popMiddle());
console.log(obj.popBack());
console.log(obj.popFront());
