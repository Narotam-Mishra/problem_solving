
// Problem link - https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

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

function findMidOfLinkedList(head){
    let prev = null;
    let slow = head;
    let fast = head;

    // traverse LL and update fast and slow pointers
    while(fast !== null && fast.next !== null){
        prev = slow;
        slow = slow.next;
        fast = fast.next.next;
    }

    // disconnect the left half of LL from the middle of LL
    if(prev !== null){
        prev.next = null;
    }

    // return slow pointer which now points at mid of LL
    return slow;
}

function buildBSTRec(head){
    // edge case:
    if(head === null) return null;

    // Find the middle element of LL
    let mid = findMidOfLinkedList(head);

    // middle element of LL should be the root of BST
    let bstNode = new TreeNode(mid.data);

    // Base case: when there is just one element in the linked list
    if(head === mid) return bstNode;

    // Recursive case: recursively build the left and right subtrees
    bstNode.left = buildBSTRec(head);
    bstNode.right = buildBSTRec(mid.next);

    // return bst node
    return bstNode;
}

let sortedListToBST = function(head) {
    return buildBSTRec(head);
};

const linkedList = new LinkedList();
let arr = [-10,-3,0,5,9];

// build LL
for(let num of arr){
    linkedList.addAtTail(num);
}

bstRoot = sortedListToBST(linkedList.head);

const bst = new BinarySearchTree();
bst.root = bstRoot;

console.log(bst.printBST());
