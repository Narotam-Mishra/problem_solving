
// Problem link - https://leetcode.com/problems/validate-binary-search-tree/description/

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
            if(val !== null || val !== -1){
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

function isBSTRecursive(root, lowerVal = -Infinity, upperVal = Infinity){
    // Base case: if root doesn't exist then return true
    if(!root) return true;

    // base case: the current tree node's value must be within the range 
    // defined by lower value 'lowerVal' and upper value 'upperVal'
    if(root.val <= lowerVal || root.val >= upperVal) return false;

    // Recursively validate the left subtree with updated upper bound,
    // and the right subtree with updated lower bound.
    return isBSTRecursive(root.left, lowerVal, root.val) && isBSTRecursive(root.right, root.val, upperVal);
}

let isValidBST = function(root) {
    return isBSTRecursive(root);
};

const bst = new BinarySearchTree();
let arr = [2,1,3];

// let arr = [5,1,4,null,null,3,6];

bst.buildBSTUtil(arr);
console.log("Is Valid BST:", isValidBST(bst.root));
