
// Design Stack using Linked List

var Node = function(data) {
    this.data = data;
    this.next = null; // until or unless we attach this new node to a list, the next property should be null
}


var MyLinkedList = function() {
    this.head = null; // because initially everything is empty
};

MyLinkedList.prototype.addAtHead = function(val) {
    if(this.head == null) {
        // means the ll is empty, so this node should become the head
        this.head = new Node(val);
    } else {
        // when ll is not. empty
        let n = new Node(val);
        n.next = this.head;
        this.head = n;
    }
};


MyLinkedList.prototype.deleteAtHead = function() {
    if(this.head == null) return;
    let nextHead = this.head.next;
    let nodeToBeDelete = this.head; // curr head
    this.head = nextHead;
    nodeToBeDelete.next = null; // prev head disconnected
}

class Stack{
    // private Linked List #ll
    #ll;

    constructor(){
        this.#ll = new MyLinkedList();
    }

    push(element){
        this.#ll.addAtHead(element);
    }

    pop(){
        this.#ll.deleteAtHead()
    }

    top(){
        return this.#ll.head !== null ? this.#ll.head.data : -1;
    }

    isEmpty(){
        return this.#ll.head === null;
    }
}

let st = new Stack();

st.push(10);
st.push(20);
st.push(40);
st.push(50);
st.push(70);
console.log(st.top());
st.pop();
console.log(st.top());
console.log(st.isEmpty());

