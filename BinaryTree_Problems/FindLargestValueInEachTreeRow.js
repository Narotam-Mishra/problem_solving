
// Problem link - https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

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

    addAtTail(data){
        if(this.head == null){
            // ll is empty
            const newNode = new Node(data);
            this.head = newNode;
            this.tail = newNode;
            return;
        }else{
            let newNode = new Node(data);
            // we are attaching the new node after the prev tail 
            this.tail.next = newNode;
            // update the tail property
            this.tail = newNode;
        }
    }

    removeAtHead(){
        // if ll is null
        if(this.head === null) return 
        else{
            // if ll is not empty
            // store the new head of ll
            let newHead = this.head.next;

            // disconnect the old head from ll
            this.head.next = null;
            // allocating the brand new head 
            this.head = newHead;

            // if head becomes null after removal of the node, means ll is empty
            if(this.head === null){
                // make tail also null
                this.tail = null;
            }
        }
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
        if(index < arr.length){
            let temp = new TreeNode(arr[index]);
            temp.left = this.createBinaryTree(arr, 2 * index + 1);
            temp.right = this.createBinaryTree(arr, 2 * index + 2);
            return temp;
        }
        return null;
    }

    intializeTreeNode(arr){
        this.root = this.createBinaryTree(arr,0);
    }
}

// Time Complexity is O(n) where n is the number of nodes in the tree
// O(n) complexity because we are adding once and removing every node of tree
let largestValues = function(root) {
    //corner case: if root is null then return empty array
    if(root === null) return [];
    let q = new CustomQueue();
    // first we insert root of the tree to the Queue
    q.enqueue(root);
    // marker null indicates end of the level
    q.enqueue(null);
    // to store maximum value on each level of tree in 'res' array
    const res = [];
    // maxVal will store maximum value on each level/row of tree
    let maxVal = -Infinity;
    // traverse queue
    while(!q.isEmpty()){
        // get front node from queue
        let cur = q.getFront();
        q.dequeue();
        if(cur === null){
            // this show end of last level
            res.push(maxVal);
            // reset maxVal 
            maxVal = -Infinity;

            // If the queue is not empty, we add a marker null for the next level
            if(!q.isEmpty()){
                q.enqueue(null);
            }
        }else{
            // Update maxVal with the current node value
            if(cur.val > maxVal){
                maxVal = cur.val;
            }
            // recursively traverse left and right node of tree for each level
            if(cur.left) q.enqueue(cur.left);
            if(cur.right) q.enqueue(cur.right);
        }
    }
    return res;
};

const bt = new BinaryTree();
let arr = [1,2,3,4,5,6,7];
bt.intializeTreeNode(arr,0);

const res = largestValues(bt.root);

console.log("Largest Value in each tree row/level:", res);