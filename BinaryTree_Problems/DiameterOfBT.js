
// Problem link - https://leetcode.com/problems/diameter-of-binary-tree/

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

function findMaxDepthRec(root){
    // base case: if root is null then maximum depth is 0
    if(root === null) return 0;

    // recursively compute maximum dpeth of left and right subtree
    let lst = findMaxDepthRec(root.left);
    let rst = findMaxDepthRec(root.right);

    // update global anwer 'ans' in each recurisve call
    ans = Math.max(ans, 1 + lst + rst);

    // calculate maximum depth of left and right subtree
    return 1 + Math.max(lst, rst);
}

let diameterOfBinaryTree = function(root) {
    ans = -1;
    findMaxDepthRec(root);
    // actual diameter will be ans - 1, 
    // as we are calculating diameter on the basis of edges
    return ans-1;
};

const bt = new BinaryTree();
let arr = [1,2,3,4,5,6,7];
bt.intializeTreeNode(arr,0);

let diameter = diameterOfBinaryTree(bt.root);
console.log("Diameter of BT:", diameter);