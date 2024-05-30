
// Problem link - https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

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
}

class CustomQueue{

    constructor(){
        // we will create a brand new empty ll
        this.ll = new LinkedList();
        this.size = 0;
    }

    // utility method to insert element into queue
    enqueue(data){
        this.ll.addAtTail(data);
        this.size++;
    }

    // utility method to delete element from queue
    dequeue(){
        if(this.ll.isEmpty()) return;
        this.ll.removeAtHead();
        this.size--;
    }

    // check if queue is empty or not
    isEmpty(){
        return this.ll.isEmpty();
    }

    // get front element of queue
    getFront(){
        return this.ll.getHeadData();
    }

    // get back/rear element of queue
    getBack(){
        return this.ll.getTailData();
    }

    getSize() {
        return this.size;
    }
}

class TreeNode{
    constructor(val){
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree{
    constructor(){
        this.root = null;
    }

    createBinarySearchTree(arr) {
        for (let val of arr) {
            if(val !== null){
                this.root = insertIntoBST(this.root, val);
            }
        }
    }

    printBST(){
        if(this.root === null) return [];

        let resArr = [];
        // using que to print BST
        let queue = new CustomQueue();
        queue.enqueue(this.root);

        // iterate queue untill it is empty
        while(queue.getSize() > 0){
            let treeNode = queue.getFront();
            queue.dequeue();
            if(treeNode){
                resArr.push(treeNode.val);
                queue.enqueue(treeNode.left);
                queue.enqueue(treeNode.right);
            }else{
                resArr.push(null);
            }
        }

        // Remove trailing nulls
        while (resArr[resArr.length - 1] === null) {
            resArr.pop();
        }

        return resArr;
    }
}

function insertIntoBSTRec(root, val){
    if(root === null){
        return new TreeNode(val);
    }

    // if root node value is greater than given val
    // then attach into left subtree
    if(root.val > val){
        root.left = insertIntoBSTRec(root.left, val);
    }else{
        // otherwise insert into right subtree
        root.right = insertIntoBSTRec(root.right, val);
    }
    return root;
}

let insertIntoBST = function(root, val) {
    return insertIntoBSTRec(root, val);
};

const bt = new BinaryTree();
// let arr = [4,2,7,1,3];
// let value = 5;

let arr = [40,20,60,10,30,50,70];
let value = 25;
bt.createBinarySearchTree(arr);

// insert value into BST
bt.root = insertIntoBST(bt.root, value);
// print BST into array
console.log(bt.printBST());