
// Problem link - https://leetcode.com/problems/binary-tree-level-order-traversal/

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

    insertData(val){
        const newNode = new TreeNode(val);
        if(this.root === null){
            this.root = newNode;
        }else{
            this.insertNode(this.root, newNode);
        }
    }

    insertNode(node, newNode){
        if(node.left === null){
            node.left = newNode;
        }else if(node.right === null){
            node.right = newNode;
        }else{
            // If both left and right children are already present,
            // we recursively try to insert into left and right subtrees.
            this.insertNode(node.left, newNode);
        }
    }
    // Time Complexity is O(n) where n is the number of nodes in the tree
    // O(n) complexity because we are adding once and removing every node of tree
    levelOrder = function(root) {
        //corner case: if root is null then return empty array
        if(root === null) return [];
        let qu = new CustomQueue();
        // first we insert root of the tree to the Queue
        qu.enqueue(root);
        // marker null indicates end of the level
        qu.enqueue(null);
        // to store tree's data in result 'res' array
        const res = [];
        // to store each level data we used levelArr
        let levelArr = new Array();
        // traverse queue
        while(!qu.isEmpty()){
            // get front node from queue
            const curr = qu.getFront();
            qu.dequeue();
            if(curr === null){
                // this show end of last level
                if(!qu.isEmpty()){
                    // if queue is not empty then we have all elements in queue of of next level
                    // befor we refresh level array it has data of lst level, so we push into result 'res' array 
                    res.push(levelArr);
                    // again add marker null 
                    qu.enqueue(null);
                    // in the end refresh level array
                    levelArr = new Array();
                }else{
                    res.push(levelArr);
                }
            }else{
                levelArr.push(curr.val);
                // recursively traverse left and right node of tree for each level
                if(curr.left) qu.enqueue(curr.left);
                if(curr.right) qu.enqueue(curr.right);
            }
        }
        return res;
    };
}


// Example usage:
const bt = new BinaryTree();
bt.insertData(1);
bt.insertData(2);
bt.insertData(3);
bt.insertData(4);
bt.insertData(5);
bt.insertData(6);
bt.insertData(7);

console.log("Reading binary tree data in level order traversal:");
console.log(bt.levelOrder(bt.root));