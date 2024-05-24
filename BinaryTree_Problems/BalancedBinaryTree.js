
// Problem link - https://leetcode.com/problems/balanced-binary-tree/

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

let ans;
function findMaxDepthOfBT(root){
    // base case:
    if(root === null) return 0;

    // recursive case:
    let lstHeight = findMaxDepthOfBT(root.left);
    let rstHeight = findMaxDepthOfBT(root.right);

    ans = ans && (Math.abs(lstHeight - rstHeight) <= 1);

    return 1 + Math.max(lstHeight, rstHeight);
}

let isBalanced = function(root) {
    ans = true;
    findMaxDepthOfBT(root);
    return ans;
};

const bt = new BinaryTree();
let arr = [1,2,3,4,5,6,7];
bt.intializeTreeNode(arr,0);

let isHeightBalanced = isBalanced(bt.root);
console.log("Is Binary Tree Height Balanced:", isHeightBalanced);