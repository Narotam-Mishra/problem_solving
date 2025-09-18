
// Problem link - https://leetcode.com/problems/design-task-manager/?envType=daily-question&envId=2025-09-18

// simple Max Heap implementation for JS
class CustomMaxHeap {
    constructor() {
        this.heap = [];
    }
    
    push(item) {
        this.heap.push(item);
        this.heapifyUp(this.heap.length - 1);
    }
    
    pop() {
        if (this.heap.length === 0) return null;
        if (this.heap.length === 1) return this.heap.pop();
        
        const max = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.heapifyDown(0);
        return max;
    }
    
    isEmpty() {
        return this.heap.length === 0;
    }
    
    heapifyUp(index) {
        if (index === 0) return;
        
        const parentIndex = Math.floor((index - 1) / 2);
        if (this.compare(this.heap[index], this.heap[parentIndex]) > 0) {
            [this.heap[index], this.heap[parentIndex]] = [this.heap[parentIndex], this.heap[index]];
            this.heapifyUp(parentIndex);
        }
    }
    
    heapifyDown(index) {
        const leftChild = 2 * index + 1;
        const rightChild = 2 * index + 2;
        let largest = index;
        
        if (leftChild < this.heap.length && this.compare(this.heap[leftChild], this.heap[largest]) > 0) {
            largest = leftChild;
        }
        
        if (rightChild < this.heap.length && this.compare(this.heap[rightChild], this.heap[largest]) > 0) {
            largest = rightChild;
        }
        
        if (largest !== index) {
            [this.heap[index], this.heap[largest]] = [this.heap[largest], this.heap[index]];
            this.heapifyDown(largest);
        }
    }
    
    // Compare function: returns positive if a > b, negative if a < b, 0 if equal
    // Compares by priority first, then by taskId for tie-breaking
    compare(a, b) {
        if (a[0] !== b[0]) {
            return a[0] - b[0]; // higher priority first
        }
        return a[1] - b[1]; // higher taskId first for tie-breaking
    }
}

/**
 * @param {number[][]} tasks
 */
let TaskManager = function(tasks) {
    // map for task id and its priority mapping
    this.taskPriorityMap = new Map();
    
    // max heap for priority and task id
    // for efficient retrieval
    this.maxHeap = new CustomMaxHeap();
    
    // map for task id and user id mapping
    this.taskUserMap = new Map();
    
    // for each task call add function
    for (let task of tasks) {
        this.add(task[0], task[1], task[2]);
    }
};

/** 
 * @param {number} userId 
 * @param {number} taskId 
 * @param {number} priority
 * @return {void}
 */
TaskManager.prototype.add = function(userId, taskId, priority) {
    // add pair of priority and task id in max heap
    this.maxHeap.push([priority, taskId]);
    
    // store task id and priority mapping
    this.taskPriorityMap.set(taskId, priority);
    
    // store task id and user id mapping
    this.taskUserMap.set(taskId, userId);
};

/** 
 * @param {number} taskId 
 * @param {number} newPriority
 * @return {void}
 */
TaskManager.prototype.edit = function(taskId, newPriority) {
    // add updated priority in maxHeap
    // remove the older priority later on
    this.maxHeap.push([newPriority, taskId]);
    
    // update the new priority taskPriorityMap as well
    this.taskPriorityMap.set(taskId, newPriority);
};

/** 
 * @param {number} taskId
 * @return {void}
 */
TaskManager.prototype.rmv = function(taskId) {
    // in order to remove the task, set its priority to -1
    this.taskPriorityMap.set(taskId, -1);
};

/**
 * @return {number}
 */
TaskManager.prototype.execTop = function() {
    // find task with highest priority
    // and remove stale (old priority) as well
    while (!this.maxHeap.isEmpty()) {
        const top = this.maxHeap.pop();
        const currPriority = top[0];
        const taskId = top[1];
        
        // check if current priority is matching from updated priority
        if (currPriority === this.taskPriorityMap.get(taskId)) {
            // set old priority to -1
            this.taskPriorityMap.set(taskId, -1);
            
            // return corresponding user
            return this.taskUserMap.get(taskId);
        }
    }
    
    // if task id not available return -1
    return -1;
};

// Main function to test the TaskManager
function main() {
    console.log("Testing TaskManager JavaScript Implementation");
    console.log("===========================================");
    
    // Test the TaskManager
    const initialTasks = [
        [1, 101, 10],  // userId=1, taskId=101, priority=10
        [2, 102, 20],  // userId=2, taskId=102, priority=20
        [3, 103, 15]   // userId=3, taskId=103, priority=15cls
    ];
    
    const tm = new TaskManager(initialTasks);
    
    console.log("Initial tasks added:");
    console.log("Task 101 (User 1, Priority 10)");
    console.log("Task 102 (User 2, Priority 20)");
    console.log("Task 103 (User 3, Priority 15)");
    
    // Execute top priority task
    console.log("\nExecuting top priority task:");
    let user = tm.execTop();
    console.log(`User ID: ${user} (should be 2, highest priority 20)`);
    
    // Add a new task
    tm.add(4, 104, 25);
    console.log("\nAdded Task 104 (User 4, Priority 25)");
    
    // Execute top priority task
    console.log("Executing top priority task:");
    user = tm.execTop();
    console.log(`User ID: ${user} (should be 4, highest priority 25)`);
    
    // Edit a task's priority
    tm.edit(101, 30);
    console.log("\nEdited Task 101 priority to 30");
    
    // Execute top priority task
    console.log("Executing top priority task:");
    user = tm.execTop();
    console.log(`User ID: ${user} (should be 1, highest priority 30)`);
    
    // Remove a task
    tm.rmv(103);
    console.log("\nRemoved Task 103");
    
    // Execute remaining task
    console.log("Executing remaining task:");
    user = tm.execTop();
    console.log(`User ID: ${user} (should be -1, no tasks left or task was removed)`);
}

// Run the main function
main();