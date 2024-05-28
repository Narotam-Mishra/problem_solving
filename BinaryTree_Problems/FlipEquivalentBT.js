
// Problem link - https://leetcode.com/problems/flip-equivalent-binary-trees/

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
}

function isFlipEqivalentBT(root1, root2) {
  // base case1: if both roots are null, then return true
  if (root1 === null && root2 === null) return true;

  // base case2: if either of the root is null then return false
  else if (root1 === null || root2 === null) return false;

  // base case3: if root's val are not equal then return false
  else if (root1.val !== root2.val) return false;

  // recursive case: recursively check for left and right subtree
  else {
    return (
      (isFlipEqivalentBT(root1.left, root2.left) &&
        isFlipEqivalentBT(root1.right, root2.right)) ||
      (isFlipEqivalentBT(root1.left, root2.right) &&
        isFlipEqivalentBT(root1.right, root2.left))
    );
  }
}

let flipEquiv = function(root1, root2) {
    return isFlipEqivalentBT(root1, root2);
};

const bt1 = new BinaryTree();
const arr1 = [1, 2, 3, 4, 5, 6, null, null, null, 7, 8];
bt1.buildBinaryTreeNodeUtil(arr1);

const bt2 = new BinaryTree();
const arr2 = [1, 3, 2, null, 6, 4, 5, null, null, null, null, 8, 7];
bt2.buildBinaryTreeNodeUtil(arr2);

console.log("Is Binary Tree Flip Equivalent: ", flipEquiv(bt1.root, bt2.root));