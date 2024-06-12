
// Design your own AVL Tree with its important methods

class ListNode{
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
            const newNode = new ListNode(data);
            this.head = newNode;
            this.tail = newNode;
            return;
        }else{
            let newNode = new ListNode(data);
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

// Node for AVL Tree

class Node {
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
        this.height = 1;
    }
}

class AVLTree {
    constructor(){
        this.root = null;
    }

    // utility method to perform right rotation in AVL Tree
    rightRotate(alpha){
        // alpha is the unbalanced node
        // intialize nodes
        let beta = alpha.left;
        let sigma = beta.right;

        // right rotation
        beta.right = alpha;
        alpha.left = sigma;

        // update heights of alpha and beta nodes
        // update height of alpha first, because height of beta depend on it
        alpha.height = Math.max(this.calcHeight(alpha.left), this.calcHeight(alpha.right)) + 1;
        beta.height = Math.max(this.calcHeight(beta.left), this.calcHeight(beta.right)) + 1;
        
        // return the new root beta
        return beta;
    }

    // utility method to perform left rotation in AVL Tree
    leftRotate(alpha){
        // alpha is the unbalanced node

        // intialize nodes
        let beta = alpha.right
        let sigma = beta.left

        // left rotation
        beta.left = alpha;
        alpha.right = sigma;

        // update heights of alpha and beta nodes
        // update height of alpha first, because height of beta depend on it
        alpha.height = Math.max(this.calcHeight(alpha.left), this.calcHeight(alpha.right)) + 1;
        beta.height = Math.max(this.calcHeight(beta.left), this.calcHeight(beta.right)) + 1;

        // return the new root beta
        return beta;
    }

    calcHeight(node){
        if(node === null) return 0;
        return node.height;
    }

    getBalancingFactor(node){
        if(node === null) return 0;
        return this.calcHeight(node.left) - this.calcHeight(node.right);
    }

    insertInAVLTree(data){
       this.root = this.insert(this.root, data);
    }

    insert(alpha, data){
        if(alpha === null) return new Node(data);

        // if alpha is not null, then you are on existing node
        // now decide whether this data should be inserted in the lst or rst of current node
        if(alpha.data > data){
            // go to lst
            alpha.left = this.insert(alpha.left, data);
        }else if(alpha.data < data){
            // go to rst
            alpha.right = this.insert(alpha.right, data);
        }

        // update the height as new data has been inserted
        alpha.height = Math.max(this.calcHeight(alpha.left), this.calcHeight(alpha.right)) + 1;

        // this part is executing while coming back in the recursion
        // start balancing
        const balanceFactor = this.getBalancingFactor(alpha);

        // if the 'balanceFactor' is greater than 1 or less than -1, then we have alpha(root) unbalanced
        if(balanceFactor > 1){
            // it means tree is left heavy
            // how to decide if we need to do right rotation or left-right rotation
            let beta = alpha.left;
            if(data < beta.data){
                // right rotation
                return this.rightRotate(alpha);
            }else{
                // left-right rotation
                alpha.left = this.leftRotate(alpha.left);
                return this.rightRotate(alpha);
            }
        }else if(balanceFactor < -1){
            // otherwise tree is right heavy
            // how to decide if we need to do left rotation or right-left rotation
            let beta = alpha.right;
            if(data > beta.data){
                // left rotate
                return this.leftRotate(alpha);
            }else{
                // right-left rotate
                alpha.right = this.rightRotate(alpha.right);
                return this.leftRotate(alpha);
            }
        }

        // if BST is already balanced
        return alpha
    }

    preOrderRec(node, res){
        // base case:
        if (node === null) return;
        res.push(node.data);
        // recursive case:
        this.preOrderRec(node.left, res);
        this.preOrderRec(node.right, res);
    }

    preorderTraversal() {
        let res = [];
        this.preOrderRec(this.root, res);
        return res;
    };

    InOrderRec(node, res){
        // base case:
        if (node === null) return;
        
        // recursive case:
        this.InOrderRec(node.left, res);
        res.push(node.data);
        this.InOrderRec(node.right, res);
    }
    
    inorderTraversal() {
        let res = [];
        this.InOrderRec(this.root, res);
        return res;
    };

    postOrderRec(node, res){
        // base case:
        if (node === null) return;
        // recursive case:
        this.postOrderRec(node.left, res);
        this.postOrderRec(node.right, res);
        res.push(node.data);
    }

    postorderTraversal() {
        let res = [];
        this.postOrderRec(this.root, res);
        return res;
    }

    levelOrderTraversal(){
        return this.levelOrder(this.root);
    }

    levelOrder(root) {
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
                levelArr.push(curr.data);
                // recursively traverse left and right node of tree for each level
                if(curr.left) qu.enqueue(curr.left);
                if(curr.right) qu.enqueue(curr.right);
            }
        }
        return res;
    };
}

const avl = new AVLTree();
avl.insertInAVLTree(1);
avl.insertInAVLTree(2);
avl.insertInAVLTree(3);
avl.insertInAVLTree(4);
avl.insertInAVLTree(5);
avl.insertInAVLTree(6);
avl.insertInAVLTree(7);

const pre = avl.preorderTraversal();
const post = avl.postorderTraversal();
const inorder = avl.inorderTraversal();
const levelOrderArr = avl.levelOrderTraversal();

console.log(`PreOrder Traversal: `, pre);
console.log(`InOrder Traversal: `, inorder);
console.log(`PostOrder Traversal: `, post);
console.log(`LevelOrder Traversal: `, levelOrderArr);




