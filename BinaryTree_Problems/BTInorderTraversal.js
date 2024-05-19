
// Problem link - https://leetcode.com/problems/binary-tree-inorder-traversal/

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

function InOrderRec(node, res){
    // base case:
    if (node === null) return;
    
    // recursive case:
    InOrderRec(node.left, res);
    res.push(node.val);
    InOrderRec(node.right, res);
}

let inorderTraversal = function(root) {
    let res = [];
    InOrderRec(root, res);
    return res;
};

const bt = new BinaryTree();
let arr = [1,2,3,4,5,6,7];
bt.intializeTreeNode(arr,0);

console.log("Reading binary tree data using InOrder traversal:");
console.log(inorderTraversal(bt.root));