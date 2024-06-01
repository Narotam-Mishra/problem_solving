
// Problem link - https://leetcode.com/problems/delete-node-in-a-bst/description/

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

class BinarySearchTree{
    constructor(){
        this.root = null;
    }

    // insert node into BST recursively
    insertIntoBSTRec(root, val){
        if(root === null){
            return new TreeNode(val);
        }
    
        // if root node value is greater than given val
        // then attach into left subtree
        if(root.val > val){
            root.left = this.insertIntoBSTRec(root.left, val);
        }else{
            // otherwise insert into right subtree
            root.right = this.insertIntoBSTRec(root.right, val);
        }
        return root;
    }

    // utility function to build BST
    buildBSTUtil(arr) {
        for (let val of arr) {
            if(val !== null){
                this.root = this.insertIntoBSTRec(this.root, val);
            }
        }
    }

    // utility function to search in BST recursively
    searchBSTRec(root, val){
        // base case1:
        if(root === null) return null;
    
        //base case2: 
        if(val === root.val){
            return root;
        }
        // recursive case:
        else if(val < root.val){
            return searchBSTRec(root.left, val);
        }
        return searchBSTRec(root.right, val);
    }

    // utility method to print BST
    printBST(){
        if(this.root === null) return [];

        let resArr = [];
        // using queue to print BST
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

let deleteNode = function(root, key) {
    // corner base case:
    if(root === null) return null;

    // recursively search for the node to be deleted
    if(key < root.val){
        root.left = deleteNode(root.left, key);
    }else if(key > root.val){
        root.right = deleteNode(root.right, key);
    }else{
        // node to be deleted found
        // case 1: node has no children (leaf node)
        if(root.left === null && root.right === null){
            return null;
        }
        // case 2: node has only one child
        else if(root.left === null){
            // if right child exist and left child is null
            return root.right;
        }
        else if(root.right === null){
            // if left child exist and right child is null
            return root.left;
        }
        // case 3: node has two children
        // find the inorder successor (smallest in the right subtree)
        else{
            // if both left and right child exist
            let temp = root.right;
            // find the left most node (that hold smallest value in current subtree)
            while(temp.left !== null){
                temp = temp.left;
            }
            // replace the node value that need to be deleted with leftmost node value
            root.val = temp.val;
            // now there are two occurences of replaced value exist, 
            // so we need to remove one recursively
            root.right = deleteNode(root.right, temp.val);
        }
    }
    // return root node after deletion
    return root;
};

const bst = new BinarySearchTree();
let arr = [5,3,6,2,4,null,7] , key = 3;

// let arr = [5,3,6,2,4,null,7], key = 0;

// build BST
bst.buildBSTUtil(arr);

// delete the node from BST
bst.root = deleteNode(bst.root, key);

// then print BST
const bstArr = bst.printBST();
console.log(bstArr);