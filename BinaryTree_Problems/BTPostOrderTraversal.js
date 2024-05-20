
// Problem link - https://leetcode.com/problems/binary-tree-postorder-traversal/

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

    postOrderRec(node, res){
        // base case:
        if (node === null) return;
        // recursive case:
        this.postOrderRec(node.left, res);
        this.postOrderRec(node.right, res);
        res.push(node.val);
    }

    postorderTraversal = function(root) {
        let res = [];
        this.postOrderRec(root, res);
        return res;
    };
}

const bt = new BinaryTree();
let arr = [1,2,3,4,5,6,7];
bt.intializeTreeNode(arr,0);

console.log("Reading binary tree data using postOrder traversal:");
console.log(bt.postorderTraversal(bt.root));


