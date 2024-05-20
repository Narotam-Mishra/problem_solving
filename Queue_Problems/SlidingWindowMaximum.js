
// Problem link - https://leetcode.com/problems/sliding-window-maximum/description/

class Node{
    constructor(data){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList{
    constructor(){
        this.head = null;
        this.tail = null;
    }
    // method to add node at head
    addAtHead(data){
        // if the DLL is empty, create a node
        if(this.isEmpty()){
            const newNode = new Node(data);
            // assign it as head and tail both
            this.head = newNode;
            // assign the same node as tail
            this.tail = newNode;
        }else{
            // if DLL is not empty,
            // then create a new node
            const newNode = new Node(data);
            // attach it behind the old head by making next of newNode equal to old head
            newNode.next = this.head;
            // connect the previous head to the new Node
            this.head.prev = newNode;
            // make the newNode as the head of the DLL
            this.head = newNode;
        }
    }

    // method to add node at tail
    addAtTail(data){
        if(this.isEmpty()){
            // if the DLL is empty, then adding at head is same as add at tail
            this.addAtHead(data);
        }else{
            // if DLL is not empty, create new Node at tail
            const newNode = new Node(data)
            // setup the connection
            this.tail.next = newNode;
            newNode.prev = this.tail;
            // reassign the tail as the newNode
            this.tail = newNode;
        }
    }
    // method to remove node from head of DLL
    removeAtHead() {
        if(this.isEmpty()){
            // if DLL is empty, we can't do anything
            return;
        }else if(this.head.next === null){
            // you have now a single node,so just destroy the node
            this.head = null;
            this.tail = null;
        }else{
            // DLL has size more than 1 node,
            // remember the new incoming head
            const newHead = this.head.next;
            // break the connection
            this.head.next = null;
            newHead.prev = null;
            // assign new head as the head of DLL
            this.head = newHead;
        }
    }

    // method to remove node from tail of DLL
    removeAtTail(){
        // if DLL is empty, we can't do anything
        if(this.isEmpty()) return;
        // if DLL of size 1, then remove the single node
        else if(this.head.next == null){
            this.head = null;
            this.tail = null;
        }else{
            // DLL of size more than 1, remeber new tail
            const newTail = this.tail.prev;
            // break the connection
            newTail.next = null;
            this.tail.prev = null;
            // reassign the tail
            this.tail = newTail;
        }
    }

    // method check if DLL is empty or not
    isEmpty(){
        return this.head === null;
    }
}

class Deque{
    constructor(){
        this.dll = new DoublyLinkedList();
    }

    addAtFront(data){
        this.dll.addAtHead(data);
    }

    addAtBack(data){
        this.dll.addAtTail(data);
    }

    removeAtFront(){
        this.dll.removeAtHead();
    }

    removeAtBack(){
        this.dll.removeAtTail();
    }

    getFront(){
        return this.dll.head ? this.dll.head.data : -1;
    }

    getBack(){
        return this.dll.tail ? this.dll.tail.data : -1;
    }

    isEmpty(){
        return this.dll.isEmpty();
    }
}

let maxSlidingWindow = function(nums, k) {
    let dq = new Deque();
    let res = [];

    // prepare the first window size of k
    for (let i = 0; i < k; i++) {
      // if deque is empty then directly add element index
      if (dq.isEmpty()) dq.addAtBack(i);
      else {
        // if deque is not empty then check upcoming element
        while (!dq.isEmpty() && nums[i] > nums[dq.getBack()]) {
          // till the time upcoming element is greater than deque back element
          // we will pop the element from back of deque
          dq.removeAtBack();
        }
        // Add the current index to the deque
        dq.addAtBack(i);
      }
    }
    res.push(nums[dq.getFront()]);

    // iterate on remaining elements
    for (let i = k; i < nums.length; i++) {
      // remove those element's indices(from front) that is not in proximity of the window
      while (!dq.isEmpty() && dq.getFront() <= i - k) {
        dq.removeAtFront();
      }
      // now start adding remaining element's index
      // if deque is empty then directly add element index
      if (dq.isEmpty()) dq.addAtBack(i);
      else {
        // if deque is not empty then check upcoming element
        while (!dq.isEmpty() && nums[i] > nums[dq.getBack()]) {
          // till the time upcoming element is greater than deque back element
          // pop the element from back
          dq.removeAtBack();
        }
        // Add the current index to the deque
        dq.addAtBack(i);
      }
      // Push the maximum of the current window to the result array
      res.push(nums[dq.getFront()]);
    }
    return res;
};

let arr = [1,3,-1,-3,5,3,6,7], k = 3;

// let arr = [1,-1], k = 1;
console.log(maxSlidingWindow(arr,k));