
// Problem link - https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
function findSumRootToLeafRec(root, num){
    // base case: if current node is leaf node, then return root to leaf sum
    if(root.left === null && root.right === null){
        ans  += (10 * num) + root.val;
        return;
    }

    let n = (10 * num) + root.val;
    // recursively calculate sum for left and right subtree
    if(root.left) findSumRootToLeafRec(root.left, n);
    if(root.right) findSumRootToLeafRec(root.right, n);
    return;
}

let sumNumbers = function(root) {
    ans = 0;
    findSumRootToLeafRec(root, 0);
    return ans;
};

const bt = new BinaryTree();
let arr = [1,2,3,4,5,6,7];
bt.intializeTreeNode(arr,0);

console.log("Sum of Root to Leaf numbers:", sumNumbers(bt.root));