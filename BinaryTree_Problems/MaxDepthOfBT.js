
// Problem link - https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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

function findMaxDepthRec(root){
    //base case: depth of empty tree is zero
    if(root === null) return 0;

    // recursive case:
    return 1 + Math.max(findMaxDepthRec(root.left), findMaxDepthRec(root.right));
}

let maxDepth = function(root) {
    return findMaxDepthRec(root);
};

const bt = new BinaryTree();
let arr = [1,2,3,4,5,6,7];
bt.intializeTreeNode(arr,0);

let md = maxDepth(bt.root);
console.log("Maximum Depth of BT:", md);
