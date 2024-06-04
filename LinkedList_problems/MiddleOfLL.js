
// Problem link - https://leetcode.com/problems/middle-of-the-linked-list/

class Node{
    constructor(data){
        this.data = data;
        this.next = null;
    }
}

class LinkedList{
    constructor(){
        // head of ll
        this.head = null;
        // tail of ll
        this.tail = null;
    }

    addAtTail(data) {
        const newNode = new Node(data);
        if (this.head === null) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.next = newNode;
            this.tail = newNode;
        }
    }

    removeAtHead() {
        if (this.head === null) return;
        const newHead = this.head.next;
        this.head.next = null;
        this.head = newHead;
        if (this.head === null) {
            this.tail = null;
        }
    }

    getHeadData(){
        return this.head ? this.head.data : undefined;
    }

    getTailData(){
        return this.tail ? this.tail.data : undefined;
    }

    isEmpty(){
        return this.head === null
    }

    displayLinkedList(head){
        let temp = head;
        let res = "";
        while(temp != null){
            res = res + temp.data + " -> ";
            temp = temp.next;
        }
        res += "X";
        console.log(res);
    }
}

let middleNode = function(head) {
    let prev = null;
    let slow = head;
    let fast = head;

    // traverse LL and update fast and slow pointers
    while(fast !== null && fast.next !== null){
        prev = slow;
        slow = slow.next;
        fast = fast.next.next;
    }

    // disconnect the left half of LL from the middle of LL
    if(prev !== null){
        prev.next = null;
    }

    // return slow pointer which now points at mid of LL
    return slow;
};

const linkedList = new LinkedList();
let arr = [1,2,3,4,5];

// build LL
for(let num of arr){
    linkedList.addAtTail(num);
}

let head = middleNode(linkedList.head);
linkedList.displayLinkedList(head);