
// Problem link - https://leetcode.com/problems/maximum-width-of-binary-tree/

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
        // to keep track of the length of LL
        this.length = 0; 
    }

    // Add a node at the tail of the linked list
    addAtTail(data) {
        const newNode = new Node(data);
        if (this.head === null) {
            // If the linked list is empty
            this.head = newNode;
            this.tail = newNode;
        } else {
            // If the linked list is not empty
            this.tail.next = newNode;
            this.tail = newNode;
        }
        // Increment the length
        this.length++;
    }

    // Remove the head node of the linked list
    removeAtHead() {
        if (this.head === null) return;
        let newHead = this.head.next;
        this.head.next = null;
        this.head = newHead;
        if (this.head === null) this.tail = null;
        // decrement the length
        this.length--; 
    }

    getHeadData(){
        if(this.head === null) return undefined;
        return this.head.data;
    }

    getTailData(){
        if(this.tail === null) return undefined;
        return this.tail.data;
    }

    isEmpty(){
        return this.head === null
    }

    // get the size of the linked list
    size(){
        return this.length;
    }
}

class CustomQueue{

    constructor(){
        // we will create a brand new empty ll
        this.ll = new LinkedList();
    }

    // utility method to insert element into queue
    enqueue(data){
        this.ll.addAtTail(data);
    }

    // utility method to delete element from queue
    dequeue(){
        if(this.ll.isEmpty()) return;
        this.ll.removeAtHead();
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

    // get the size of the queue
    size() {
        return this.ll.size();
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

    createBinaryTree(arr, index){
        if(index < arr.length && arr[index] !== null){
            let temp = new TreeNode(arr[index]);
            temp.left = this.createBinaryTree(arr, 2 * index + 1);
            temp.right = this.createBinaryTree(arr, 2 * index + 2);
            return temp;
        }
        return null;
    }

    initializeTreeNode(arr){
        this.root = this.createBinaryTree(arr,0);
    }
}


let widthOfBinaryTree = function(root) {
    // edge case: if root is null then return 0
    if(root == null) return 0;

    // 'maxWidth' to store maximum width of BT
    let maxWidth = 0;

    // create queue to store tree node and perfrom level order traversal
    const queue = new CustomQueue();
    // Store the node and its index
    queue.enqueue([root, 0]);

    // traverse queue until it is empty
    while(!queue.isEmpty()){
        const size = queue.size();
        // get the index of the first node in this level
        let minIndex = queue.getFront()[1];
        // to keepp track of left and right child index
        let leftIdx, rightIdx;

        // iterate through each node of a level
        for(let i=0; i<size; i++){
            const [treeNode, index] = queue.getFront();
            queue.dequeue();

            // normalize index value to prevent overflow
            let currIdx = index - minIndex;
            if(i === 0) leftIdx = currIdx;
            if(i === size - 1) rightIdx = currIdx;

            // push left and right child of tree (if exist) into queue
            if(treeNode.left) queue.enqueue([treeNode.left, 2 * currIdx + 1]);
            if(treeNode.right) queue.enqueue([treeNode.right, 2 * currIdx + 2]);
        }
        // calculate max width for each level
        maxWidth = Math.max(maxWidth, rightIdx-leftIdx+1);
    }
    return maxWidth;
};

const bt = new BinaryTree();
// let arr = [1, 3, 2, 5, 3, null, 9];
let arr = [1, 3, 2, 5, null, null, 9, 6, null, 7];

bt.initializeTreeNode(arr);
console.log("Maximum Width of BT: ",widthOfBinaryTree(bt.root)); 