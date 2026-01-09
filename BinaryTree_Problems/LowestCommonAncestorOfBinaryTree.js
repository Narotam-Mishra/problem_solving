
// Problem link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

// TreeNode definition
class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

/*
 Utility function to build binary tree from level-order array
 null represents missing nodes
*/
function buildTree(arr) {
    if (!arr.length || arr[0] === null) return null;

    const root = new TreeNode(arr[0]);
    const queue = [root];
    let i = 1;

    while (queue.length && i < arr.length) {
        const curr = queue.shift();

        // left child
        if (i < arr.length && arr[i] !== null) {
            curr.left = new TreeNode(arr[i]);
            queue.push(curr.left);
        }
        i++;

        // right child
        if (i < arr.length && arr[i] !== null) {
            curr.right = new TreeNode(arr[i]);
            queue.push(curr.right);
        }
        i++;
    }
    return root;
}

/*
 Utility function to find node by value
*/
function findNode(root, value) {
    if (root === null) return null;
    if (root.val === value) return root;

    const left = findNode(root.left, value);
    if (left !== null) return left;

    return findNode(root.right, value);
}

/*
 Lowest Common Ancestor
*/
let lowestCommonAncestor = function(root, p, q) {
    // base case
    if (root === null) return null;

    // step 1 - if current node is p or q
    if (root === p || root === q) return root;

    // step 2 - search left subtree
    const left = lowestCommonAncestor(root.left, p, q);

    // step 3 - search right subtree
    const right = lowestCommonAncestor(root.right, p, q);

    // step 4 - p and q found in different subtrees
    if (left !== null && right !== null) {
        return root;
    }

    // step 5 - otherwise return non-null
    return left !== null ? left : right;
}

/* ================= Runner ================= */

// const nums = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4];
// const root = buildTree(nums);

// const p = findNode(root, 5);
// const q = findNode(root, 4);

const nums = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4];
const root = buildTree(nums);

const p = findNode(root, 5);
const q = findNode(root, 1);

const lca = lowestCommonAncestor(root, p, q);
console.log("Lowest Common Ancestor:", lca ? lca.val : null);
