
// Problem link - https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

function TreeNode(val, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
}

// utility function to build a tree from an array 
function buildTree(arr) {
    if (!arr.length) return null;
    let root = new TreeNode(arr[0]);
    let queue = [root];
    let i = 1;
    while (i < arr.length) {
        let current = queue.shift();
        if (arr[i] !== null) {
            current.left = new TreeNode(arr[i]);
            queue.push(current.left);
        }
        i++;
        if (i < arr.length && arr[i] !== null) {
            current.right = new TreeNode(arr[i]);
            queue.push(current.right);
        }
        i++;
    }
    return root;
}

// utility function to convert tree to array
function treeToArray(root) {
    if (!root) return [];
    let result = [];
    let queue = [root];
    while (queue.length) {
        let node = queue.shift();
        if (node) {
            result.push(node.val);
            queue.push(node.left);
            queue.push(node.right);
        } else {
            result.push(null);
        }
    }
    while (result[result.length - 1] === null) {
        result.pop();
    }
    return result;
}

let sum;
function traverseBST(node){
    // base case: if tree's node doesn't exist then return
    if(!node) return;

    // perform reverse In-Order traversal
    // traverse right subtree
    traverseBST(node.right);

    // update the sum and the node's value
    sum += node.val;
    node.val = sum;

    // traverse left subtree
    traverseBST(node.left);
}

let bstToGst = function(root) {
    sum = 0;
    traverseBST(root);
    return root;
};

let arr = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
let root = buildTree(arr);
root = bstToGst(root);
console.log(treeToArray(root));