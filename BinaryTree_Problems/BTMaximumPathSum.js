
// Problem link - https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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

    // build BT using Queue
    buildBinaryTreeNodeUtil(arr){
        // corner case:
        if(arr.length === 0 || arr[0] === null) return null;

        // create tree's root node
        let root = new TreeNode(arr[0]);
        // using queue to build binary tree
        let queue = new CustomQueue();
        queue.enqueue(root);
        let i = 1;

        // iterate on queue and build tree
        while(queue.getSize() > 0 && i < arr.length){
            let curr = queue.getFront();
            if(i < arr.length && arr[i] !== null){
                curr.left = new TreeNode(arr[i]);
                queue.enqueue(curr.left);
            }
            i++;
            if(i < arr.length && arr[i] !== null){
                curr.right = new TreeNode(arr[i]);
                queue.enqueue(curr.right);
            }
            i++;
        }
        return root;
    }

    // utility method to create BT
    createBinaryTree(arr, index){
        if(index < arr.length && arr[index] !== null){
            let temp = new TreeNode(arr[index]);
            temp.left = this.createBinaryTree(arr, 2 * index + 1);
            temp.right = this.createBinaryTree(arr, 2 * index + 2);
            return temp;
        }
        return null;
    }

    // initialize BT node
    intializeTreeNode(arr){
        this.root = this.createBinaryTree(arr,0);
    }
}

let ans;
function findMaxPathSumRec(root){
    // base case: if root is null then return 0
    if(root === null) return 0;

    // recursive case: recusively find left and right subtree sum
    let lst = Math.max(0, findMaxPathSumRec(root.left));
    let rst = Math.max(0, findMaxPathSumRec(root.right));

    // calculate the maximum path sum passing through the current node
    let mPathSum = root.val + lst + rst;

    // update the max path sum
    ans = Math.max(ans, mPathSum);

    // return maximum path sum
    return root.val + Math.max(lst, rst);
}

let maxPathSum = function(root) {
    ans = -Infinity;
    findMaxPathSumRec(root);
    return ans;
};

const bt = new BinaryTree();
const arr = [1,2,3];

// const arr = [-10,9,20,null,null,15,7];
bt.intializeTreeNode(arr);
console.log("Maximum Path Sum: ", maxPathSum(bt.root));
