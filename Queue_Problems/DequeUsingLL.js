
// Deque using Linked List

class Node{
    constructor(element){
        this.element = element;
        this.next = null;
    }
}

class Deque{
    constructor(){
        this.front = null;
        this.rear = null;
        this.size = 0;
    }

    // add element to the front of deque
    addAtFront(element){
        let newNode = new Node(element);
        if(this.isEmpty()){
            this.front = newNode;
            this.rear = newNode;
        }else{
            newNode.next = this.front;
            this.front = newNode;
        }
        this.size++;
    }

    // Adds element to the end of the deque
    addAtBack(element){
        let newNode = new Node(element);
        if(this.isEmpty()){
            this.front = newNode;
            this.rear = newNode;
        }else{
            this.rear.next = newNode;
            this.rear = newNode;
        }
        this.size++;
    }

     // Removes and returns element from the front of the deque
    removeAtFront(){
        if(this.isEmpty()) return null;
        const nodeToBeDel = this.front;
        this.front = this.front.next;
        if(!this.front){
            // If the deque becomes empty after removal
            this.rear = null;
        }
        this.size--;
        return nodeToBeDel.element;
    }

    // Removes and returns element from the end of the deque
    removeAtBack(){
        if(this.isEmpty()) return null;
        let current = this.front;
        let prev = null;
        while(current.next){
            prev = current;
            current = current.next;
        }
        const nodeToBeDel = current;
        if(prev){
            // Update the next pointer of the second-to-last node
            prev.next = null;
            // Update rear pointer
            this.rear = prev;
        }else{
            this.front = null;
            this.rear = null;
        }
        this.size--;
        return nodeToBeDel.element;
    }

    // Returns the front element of the deque
    getFront(){
        return this.front ? this.front.element : null;
    }

    // Returns the rear/back element of the deque
    getBack(){
        return this.rear ? this.rear.element : null;
    }

    isEmpty(){
        return this.size === 0;
    }

    printDeque(){
        let cur = this.front;
        let res = "";
        while(cur){
            res += cur.element + " ";
            cur = cur.next;
        }
        console.log(res);
    }
}

const dq = new Deque();

dq.addAtFront(1);
dq.addAtFront(2);
dq.addAtBack(3);
dq.addAtBack(4);
dq.addAtBack(5);
dq.addAtBack(6);
dq.addAtFront(7);
dq.printDeque(); // Output: 7 2 1 3 4 5 6 
console.log(dq.removeAtFront()); // Output: 7
console.log(dq.removeAtBack()); // Output: 6
dq.printDeque(); // Output: 2 1 3 4 5