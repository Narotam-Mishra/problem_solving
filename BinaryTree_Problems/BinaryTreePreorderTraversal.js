
// Problem link - https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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

    preOrderRec(node, res){
        // base case:
        if (node === null) return;
        res.push(node.val);
        // recursive case:
        this.preOrderRec(node.left, res);
        this.preOrderRec(node.right, res);
    }

    preorderTraversal = function(root) {
        let res = [];
        this.preOrderRec(root, res);
        return res;
    };
}

const bt = new BinaryTree();
let arr = [1,2,3,4,5,6,7];
bt.intializeTreeNode(arr,0);

console.log("Reading binary tree data using preOrder traversal:");
console.log(bt.preorderTraversal(bt.root));



