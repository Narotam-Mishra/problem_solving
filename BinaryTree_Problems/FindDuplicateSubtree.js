
// Problem link - https://leetcode.com/problems/find-duplicate-subtrees/description/

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

const treeToArray = (root) => {
    if (!root) return [];
    const result = [];
    const queue = [root];
    while (queue.length > 0) {
        const node = queue.shift();
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
};

let nodeMp;
let res;

function fDSRec(root){
    // base case: if tree node has no child then return '#' to indicate null
    if(root === null) return '#';

    // recursive case: recursively traverse left and right subtrees
    let lst = fDSRec(root.left);
    let rst = fDSRec(root.right);

    // arrange node's value
    const nodeStr = "" + root.val + "," + lst + "," + rst;
    
    // maitain node's value entry in map 'nodeMp'
    if(!nodeMp[nodeStr]){
        nodeMp[nodeStr] = 1;
    }else{
        if(nodeMp[nodeStr] === 1){
            // this is the first time we detected duplicate
            // so store its root into result array 'res'
            res.push(root);
        }
        // increment duplicate node's val frequency
        nodeMp[nodeStr] += 1
    }

    return nodeStr;
}

let findDuplicateSubtrees = function(root) {
    nodeMp = {};
    res = [];
    fDSRec(root);
    return res;
};

const bt = new BinaryTree();
let arr = [1,2,3,4,2,4,4];
// let arr = [2,1,1];
bt.intializeTreeNode(arr,0);

const duplicates = findDuplicateSubtrees(bt.root);
const ans = duplicates.map(treeToArray);
console.log("Duplicate Subtree: ",ans);