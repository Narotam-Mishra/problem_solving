
// Design your own Deque using DLL

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

    // utility method to display the DLL data
    displayDLLUtils(){
        // head to tail
        let temp = this.head;
        let res = "";
        while(temp != null){
            // console.log(temp.data);
            res += temp.data + " ";
            temp = temp.next;
        }
        console.log("From head to tail");
        console.log(res);
        console.log("*******************************");
        // tail to head;
        res = "";
        temp = this.tail;
        while(temp != null){
            // console.log(temp.data);
            res += temp.data + " ";
            temp = temp.prev;
        }
        console.log("From tail to head");
        console.log(res);
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

    printDequeUtils(){
        let temp = this.dll.head;
        let res = "Deque: ";
        while(temp !== null){
            res += temp.data + " ";
            temp = temp.next;
        }
        console.log(res);
    }
}

let dq = new Deque();
dq.addAtFront(11);
dq.addAtFront(13);
dq.addAtFront(19);
dq.addAtFront(21);
dq.addAtBack(91);
dq.addAtBack(87);
dq.addAtBack(77);
dq.printDequeUtils();

console.log("Front Element:", dq.getFront());
console.log("Rear Element:", dq.getBack());

dq.removeAtFront();
dq.removeAtBack();

dq.printDequeUtils();

console.log("Front Element:", dq.getFront());
console.log("Rear Element:", dq.getBack());




