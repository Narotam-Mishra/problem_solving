
// Problem link - https://leetcode.com/problems/flip-equivalent-binary-trees/

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
        if(index < arr.length && arr[index] !== null){
            let temp = new TreeNode(arr[index]);
            temp.left = this.createBinaryTree(arr, 2 * index + 1);
            temp.right = this.createBinaryTree(arr, 2 * index + 2);
            return temp;
        }
        return null;
    }

    initializeTreeNode(arr){
        this.root = this.createBinaryTree(arr,0);
    }
}

function isFlipEqivalentBT(root1, root2) {
  // base case1: if both roots are null, then return true
  if (root1 === null && root2 === null) return true;

  // base case2: if either of the root is null then return false
  else if (root1 === null || root2 === null) return false;

  // base case3: if root's val are not equal then return false
  else if (root1.val !== root2.val) return false;

  // recursive case: recursively check for left and right subtree
  else {
    return (
      (isFlipEqivalentBT(root1.left, root2.left) &&
        isFlipEqivalentBT(root1.right, root2.right)) ||
      (isFlipEqivalentBT(root1.left, root2.right) &&
        isFlipEqivalentBT(root1.right, root2.left))
    );
  }
}

let flipEquiv = function(root1, root2) {
    return isFlipEqivalentBT(root1, root2);
};

const bt1 = new BinaryTree();
const arr1 = [1, 2, 3, 4, 5, 6, null, null, null, 7, 8];
bt1.initializeTreeNode(arr1);

const bt2 = new BinaryTree();
const arr2 = [1, 3, 2, null, 6, 4, 5, null, null, null, null, 8, 7];
bt2.initializeTreeNode(arr2);

console.log("Is Binary Tree Flip Equivalent: ", flipEquiv(bt1.root, bt2.root));