
// Problem link - https://leetcode.com/problems/lru-cache/description/

class Node{
    constructor(key, value){
        this.data = key;
        this.value = value;
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
    addAtHead(key, value){
        // if the DLL is empty, create a node
        if(this.isEmpty()){
            const newNode = new Node(key, value);
            // assign it as head and tail both
            this.head = newNode;
            // assign the same node as tail
            this.tail = newNode;
            // return newNode refernce that will be stored in map(object) as value
            return newNode;
        }else{
            // if DLL is not empty,
            // then create a new node
            const newNode = new Node(key, value);
            // attach it behind the old head by making next of newNode equal to old head
            newNode.next = this.head;
            // connect the previous head to the new Node
            this.head.prev = newNode;
            // make the newNode as the head of the DLL
            this.head = newNode;
            return newNode;
        }
    }

    // method to add node at tail
    addAtTail(key, value){
        if(this.isEmpty()){
            // if the DLL is empty, then adding at head is same as add at tail
            this.addAtHead(key, value);
        }else{
            // if DLL is not empty, create new Node at tail
            const newNode = new Node(key, value);
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

    // method to remove node from in between 
    removeNode(node){
        if(node.prev === null){
            // if the node is head node then call removeAtHead()
            this.removeAtHead();
        }else if(node.next === null){
            // if the node is tail node then call removeAtTail()
            this.removeAtTail();
        }else{
            // if the node is some node in between
            const prevNode = node.prev;
            const nextNode = node.next;
            // DLL current setup : prevnode - node - nextNode

            // break connection between prevnode and curnode
            prevNode.next = null;
            node.prev = null;

            // break connection between curnode and nextNode
            node.next = null;
            nextNode.prev = null;

            // connect prevnode with nextNode
            prevNode.next = nextNode;
            nextNode.prev = prevNode;
        }
    }

    // method check if DLL is empty or not
    isEmpty(){
        return this.head === null;
    }
}

/**
 * @param {number} capacity
 */
let LRUCache = function(capacity) {
    this.dll = new DoublyLinkedList();
    this.cacheCapacity = capacity;
    this.size = 0;  // current cache size
    this.cacheMap = {};
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    // if the key doesn't exist in cache then return -1
    if(this.cacheMap[key] === undefined) return -1;
    // otherwise get value from cache using key(node reference)
    let res = this.cacheMap[key].value;
    // and then we have to move this current node at head of cache
    // before moving at head we need to remove the node from its current place
    const nodeToBeRemoved = this.cacheMap[key];
    this.dll.removeNode(nodeToBeRemoved);
    // now add at head with current result value 'res'
    this.cacheMap[key] = this.dll.addAtHead(key,res);
    // and return result 'res'
    return res;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if(this.cacheMap[key] != undefined){
        // if the key already exist in cache map then remove existing one
        const nodeToBeRemoved = this.cacheMap[key];
        this.dll.removeNode(nodeToBeRemoved);
        // and add new entry corresponding to key
        this.cacheMap[key] = this.dll.addAtHead(key, value);
    }else{
        // otherwise new key, value pair to be added in cache map
        // before adding new entry, we will check cacheCapacity
        if(this.size === this.cacheCapacity){
            // cache is full
            // if cache is full then delete LRU element that is at tail of DLL
            delete this.cacheMap[this.dll.tail.data];
            this.dll.removeAtTail();
            this.size--;
        }
        this.cacheMap[key] = this.dll.addAtHead(key,value);
        this.size++;
    }
};

// check code

let lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
console.log(lRUCache.get(1));    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
console.log(lRUCache.get(2));    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
console.log(lRUCache.get(1));    // return -1 (not found)
console.log(lRUCache.get(3));    // return 3
console.log(lRUCache.get(4));    // return 4
