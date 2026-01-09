
// Problem link - https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/?envType=daily-question&envId=2026-01-09

class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

function buildTree(arr) {
    if (!arr.length || arr[0] === null) return null;

    const root = new TreeNode(arr[0]);
    const queue = [root];

    let i = 1;
    while (queue.length && i < arr.length) {
        const curr = queue.shift();

        // Left child
        if (i < arr.length && arr[i] !== null) {
            curr.left = new TreeNode(arr[i]);
            queue.push(curr.left);
        }
        i++;

        // Right child
        if (i < arr.length && arr[i] !== null) {
            curr.right = new TreeNode(arr[i]);
            queue.push(curr.right);
        }
        i++;
    }

    return root;
}

// map to store each node value and its depth
let depthMap = new Map();

// keep track of maximum depth
let maxDepth = 0;

function findTreeDepth(root, d) {
    if (!root) return;

    maxDepth = Math.max(maxDepth, d);
    depthMap.set(root.val, d);

    findTreeDepth(root.left, d + 1);
    findTreeDepth(root.right, d + 1);
}

function findLCA(root) {
    // base case
    if (!root || depthMap.get(root.val) === maxDepth) {
        return root;
    }

    // recursive case
    let left = findLCA(root.left);
    let right = findLCA(root.right);

    if (left && right) return root;
    return left ? left : right;
}

let subtreeWithAllDeepest = function(root) {
    // reset
    depthMap = new Map();
    maxDepth = 0;

    // step 1 - find maximum depth and populate map
    findTreeDepth(root, 0);

    // step 2 - now find LCA of nodes having maximum depth
    return findLCA(root);
}

// print subtree in [2,7,4] format
function printSubtree(root) {
    if (!root) {
        console.log("[]");
        return;
    }

    let res = [];
    let q = [root];

    while (q.length) {
        let curr = q.shift();
        res.push(curr.val);

        if (curr.left) q.push(curr.left);
        if (curr.right) q.push(curr.right);
    }

    console.log(`[${res.join(",")}]`);
}

// const nums = [3,5,1,6,2,0,8,null,null,7,4];

// const nums = [1];

const nums = [0,1,3,null,2]
const root = buildTree(nums);
const res = subtreeWithAllDeepest(root);
printSubtree(res);
