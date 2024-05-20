
// Problem link - https://leetcode.com/problems/cousins-in-binary-tree/description/

/*
===> Two nodes of a binary tree are cousins if they have the same depth with different parents.
===> In other words, we can say that two nodes of a binary tree are cousins if they are on same level(depth) and they have different parent.
*/

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
        // initialize the size property
        this.size = 0;
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
        this.size++;
    }

    removeAtHead() {
        if (this.head === null) return null;
        const removedNode = this.head;
        this.head = this.head.next;
        if (this.head === null) {
            this.tail = null;
        }
        this.size--;
        return removedNode.data;
    }

    getHeadData(){
        return this.head ? this.head.data : undefined;
    }

    getTailData(){
        return this.tail ? this.tail.data : undefined;
    }

    isEmpty(){
        return this.size === 0
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

    // get size of the queue
    getSize(){
        return this.ll.size;
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

let isCousins = function(root, x, y) {
    // using custom queue
    let queue = new CustomQueue();

    // push current node into custom queue
    queue.enqueue(root);
    // intially both nodes are at level are -1
    let l1 = -1, l2 = -1;
    
    // to maintain parent node for x and y
    let parentX = null, parentY = null;
    
    // calculate level
    let depth = 0;

    // traverse queue till it is empty
    while(!queue.isEmpty()){
        // get current size of queue
        let size = queue.getSize();

        // traverse current level of tree (by getting front element from queue)
        while(size > 0){
            let curr = queue.getFront();
            queue.dequeue();

            if(curr.left){
                queue.enqueue(curr.left);
                if(curr.left.val === x){
                    l1 = depth + 1;
                    parentX = curr;
                }
                if(curr.left.val === y){
                    l2 = depth + 1;
                    parentY = curr;
                }
            }

            if(curr.right){
                queue.enqueue(curr.right);
                if(curr.right.val === x){
                    l1 = depth + 1;
                    parentX = curr;
                }
                if(curr.right.val === y){
                    l2 = depth + 1;
                    parentY = curr;
                }
            }
            size--;
        }
        // after each level incrent the depth
        depth++;

        if(l1 !== -1 && l2 !== -1){
            // it means we get level (depth) for both nodes elements x & y
            // level may be equal or unequal
            break;
        } 
    }

    // Check if both nodes are at the same level and have different parents
    return (l1 === l2) && (parentX !== parentY);
};

const bt = new BinaryTree();
// let arr = [1,2,3,4];
// let x = 4, y = 3;

let arr = [1,2,3,null,4,null,5];
let x = 5, y = 4;
bt.intializeTreeNode(arr,0);

console.log("Are both nodes cousin:");
console.log(isCousins(bt.root, x, y));