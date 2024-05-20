
// Problem link - https://leetcode.com/problems/design-circular-queue/

/**
 * @param {number} k
 */
let MyCircularQueue = function(k) {
    this.queue = [];
    this.maxSize = k;
    this.front = 0;
    this.rear = -1;
    this.count = 0;
};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularQueue.prototype.enQueue = function(value) {
    // if queue is full then return false
    if(this.isFull()){
        return false;
    }
    // insert element in circular queue (from rear(back))
    this.rear = (this.rear + 1) % this.maxSize;
    this.queue[this.rear] = value;
    // after insertion increment the counter, count
    this.count++;
    return true;
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.deQueue = function() {
    // if queue is empty then we can't perform deletion(deQueue operation)
    // so return false
    if(this.isEmpty()){
        return false;
    }
    // delete element in from Queue's front
    this.front = (this.front + 1) % this.maxSize;
    // after deletion decrement the counter, count
    this.count--;
    return true;
};

/**
 * @return {number}
 */
MyCircularQueue.prototype.Front = function() {
    // befor getting queue's front element check queue is empty or not
    if(this.isEmpty()){
        return -1;
    }
    // otherwise return queue's front element
    return this.queue[this.front];
};

/**
 * @return {number}
 */
MyCircularQueue.prototype.Rear = function() {
    // befor getting queue's rear element check queue is empty or not
    if(this.isEmpty()){
        return -1;
    }
    // otherwise return queue's rear element
    return this.queue[this.rear];
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.isEmpty = function() {
    return this.count === 0;
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.isFull = function() {
    return this.count === this.maxSize;
};


// Runner code
var circularQueue = new MyCircularQueue(3); // Initialize a circular queue with size 3
console.log(circularQueue.enQueue(1)); // Output: true
console.log(circularQueue.enQueue(2)); // Output: true
console.log(circularQueue.enQueue(3)); // Output: true
console.log(circularQueue.enQueue(4)); // Output: false (queue is full)
console.log(circularQueue.Rear()); // Output: 3
console.log(circularQueue.isFull()); // Output: true
console.log(circularQueue.deQueue()); // Output: true
console.log(circularQueue.enQueue(4)); // Output: true
console.log(circularQueue.Rear()); // Output: 4