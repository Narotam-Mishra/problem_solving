
// Design Doubly Linked List

class Node{
    constructor(data){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList{
    constructor() {
        this.head = null;
    }

    // add node at the beginning of the DLL
    addAtHead(data){
        // if head is null add at the head of Node
        if(this.head == null){
            let newNode = new Node(data);
            this.head = newNode;
        }else{
            let newNode = new Node(data);
            newNode.next = this.head;
            this.head.prev = newNode;
            this.head = newNode;
        }
    }

    // add a new node at the tail of the DLL
    addAtTail(data){
        // if head is null
        if(this.head === null){
            this.addAtHead(data);
            return;
        }
        // otherwise traverse the DLL and insert node at end
        let temp = this.head;
        while(temp.next !== null){
            temp = temp.next;
        }
        let newNode = new Node(data);
        temp.next = newNode;
        newNode.prev = temp;
    }

    // add Node at the middle of DLL
    addAtMiddle(data){
        if(this.head === null){
            this.addAtHead(data);
            return;
        }
        let fast = this.head;
        let slow = this.head;
        while(fast && fast.next){
            fast = fast.next.next;
            slow = slow.next;
        }
        let newNode = new Node(data);
        let nextNode = slow.next;
        if(nextNode){
            nextNode.prev = newNode;
        }
        newNode.next = nextNode;
        slow.next = newNode;
        newNode.prev = slow;
    }

    // remove the node from start of DLL
    removeAtHead(){
        if(this.head === null) return;
        if(this.head.next === null){
            this.head = null;
            return;
        }
        let nextNode = this.head.next;
        nextNode.prev = null;
        this.head.next = null;
        this.head = nextNode;
    }

    // remove the node at the tail of DLL
    removeAtTail(){
        if(this.head === null) return;
        if(this.head.next === null){
            this.head = null;
            return;
        }
        // if DLL is not empty, iterate through it and remove Node from end
        let temp = this.head;
        while(temp.next.next !== null){
            temp = temp.next;
        }
        temp.next.prev = null;
        temp.next = null;
    }

    // remove the node from the middle of the DLL
    removeAtMiddle(){
        if(this.head === null) return;
        let fast = this.head;
        let slow = this.head;
        let prev = null;
        while(fast && fast.next){
            fast = fast.next.next;
            prev = slow;
            slow = slow.next;
        }
        prev.next = slow.next;
        if(slow.next){
            slow.next.prev = prev;
        }
    }
    
    // display the elements of DLL
    display(){
        let temp = this.head;
        let str = "X <-> ";
        while(temp != null){
            str += temp.data + " <-> ";
            temp = temp.next;
        }
        str += 'X';
        console.log(str);
    }
}

// example usage

let dll = new DoublyLinkedList();
dll.addAtHead(10);
dll.addAtTail(20);
dll.addAtHead(30);
dll.addAtTail(40);
dll.addAtMiddle(15);
dll.addAtTail(50);
dll.addAtTail(60);
dll.addAtHead(71);
dll.display();
dll.removeAtHead();
dll.display();
dll.removeAtTail();
dll.display();
dll.removeAtMiddle();
dll.display();
dll.removeAtHead();
dll.addAtMiddle(30);
dll.display();