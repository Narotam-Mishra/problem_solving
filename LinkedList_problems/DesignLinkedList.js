
// Problem link - https://leetcode.com/problems/design-linked-list/

let Node = function(data){
    this.data = data;
    this.next = null;
}
var MyLinkedList = function() {
    // intially Linked List is empty
    this.head = null;
};

/** 
 * @param {number} index
 * @return {number}
 */
MyLinkedList.prototype.get = function(index) {
    let i = 0;
    let cur = this.head;
    while(i < index && cur !== null){
        i++;
        cur = cur.next;
    }
    return cur.data;
};

/** 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtHead = function(val) {
    if(this.head === null){
        // if LL is empty then the first node should become head
        this.head = new Node(val)
    }else{
        // when LL is not empty
        let newNode = new Node(val);
        newNode.next = this.head;
        this.head = newNode;
    }
};

/** 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtTail = function(val) {
    // if LL is empty
    if(this.head === null){
        this.head = new Node(val);
    }else{
        // if LL is not empty
        let cur = this.head;
        // iterate on LL to reach last node
        while(cur.next !== null){
            cur = cur.next;
        }
        // at nthe end create new node 
        let newNode = new Node(val);
        // and attach it to last node
        cur.next = newNode;
    }
};

/** 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtIndex = function(index, val) {
    // if LL is empty
    if(this.head  === null){
        this.head = new Node(val);
        return;
    }
    if(index === 0){
        this.addAtHead(val);
        return;
    }
    // if LL is not empty
    let i = 0;
    let prev = null;
    let curr = this.head;
    while(i < index && curr !== null){
        i++;
        prev = curr;
        curr = curr.next;
    }
    // if given is index is less than given length of LL
    if(i !== index) return;
    let newNode = new Node(val);
    prev.next = newNode;
    newNode.next = curr;
    return;
};

/** 
 * @param {number} index
 * @return {void}
 */
MyLinkedList.prototype.deleteAtIndex = function(index) {
    if(this.head === null) return;
    let i = 0;
    let prev = null;
    let nodeToBeDel = this.head;
    while(i < index && nodeToBeDel !== null){
        prev = nodeToBeDel;
        nodeToBeDel = nodeToBeDel.next;
        i++;
    }
    // if LL was not having the index then return
    if(i !== index){
        return;
    }
    // update node reference
    let newNext = nodeToBeDel.next;

    // if prev is not null then only we proceed further
    if(prev !== null){
        prev.next = newNext;
        nodeToBeDel.next = null;
    }
    if(index === 0){
        this.head = newNext;
    }
    return;
};

// Runner methods

/** 
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * obj.addAtHead(1)
 * obj.addAtTail(3)
 * obj.addAtIndex(1,2)
 * var param_1 = obj.get(1)
 * obj.deleteAtIndex(1)
 */