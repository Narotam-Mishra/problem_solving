
// Implement your own HashMap using Hashing function

/*

Implementation Approach :-
1). Create structure that should contain array of Linked List
2). use Load factor (lambda), at any point of time if load factor > 0.5 then we rehash

*/

let Node = function(key, value) {
    this.key = key; // key
    this.value = value;
    this.next = null; // until or unless we attach this new node to a list, the next property should be null
}


var MyLinkedList = function() {
    this.head = null; // because initially everything is empty
};

/** 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtHead = function(key, val) {
    if(this.head == null) {
        // means the ll is empty, so this node should become the head
        this.head = new Node(key, val);
    } else {
        // when ll is not. empty
        let n = new Node(key,  val);
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

class HashMap {
    constructor(){
        // threshold lambda factor
        this.lambdaFactor = 0.5;
        this.arr = [];
        // to know how many key-value pairs are inserted into hashMap (i.e size of HashMap)
        this.currSize = 0;
    }

    // this hashFunction(key) will takes key as parameter, apply hashFunction() logic on the key and
    // the result of this hashFunction will be the bucket index in the given array
    hashFunction(key){
        let hashedValue = 0;
        // this 'hashedValue' will be the final hashed value
        let primeNo = 101;
        // prime number to keep

        let pow = 1;
        // initially power p^0 i.e 1

        // iterate on each character of input key
        for(let i=0; i<key.length; i++){
            let asciiValue = this.getASCIIValue(key, i);
            hashedValue = (hashedValue + asciiValue*pow) % this.currSize;

            // for next iteration we will increment the power
            pow = pow * primeNo;
        }
        return hashedValue;
    }

    // utility function to find ASCII of a character
    getASCIIValue(key, index){
        return key.charCodeAt(index);
    }
}