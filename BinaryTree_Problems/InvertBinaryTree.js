
// Problem link - https://leetcode.com/problems/invert-binary-tree/

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

    // print tree nodes in in order
    printInOrder(treeNode, res){
        if(treeNode !== null){
            this.printInOrder(treeNode.left, res);
            res.push(treeNode.val);
            this.printInOrder(treeNode.right, res);
        }
    }
}

function invertBTRec(root){
    // base case:
    if(root === null) return;

    // Recursive case:
    // invert left subtree
    invertBTRec(root.left);

    // invert right subtree
    invertBTRec(root.right);

    // swap nodes
    let temp = root.left;
    root.left = root.right;
    root.right = temp;
}

let invertTree = function(root) {
    invertBTRec(root);
    return root;
};

const bt = new BinaryTree();
let arr = [1,2,3,4,5,6,7];
bt.intializeTreeNode(arr,0);

invertTree(bt.root);


let res = []
bt.printInOrder(bt.root, res);
console.log("Inverted Binary Tree:", ...res);

