
// Problem link - https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/?envType=daily-question&envId=2026-01-07

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

let maxProduct = function(root) {
    const MOD = 1000000007n;

    let sum = 0n;
    let maxP = 0n;

    // utility function to find total sum of tree
    function findTreeSum(node) {
        if (node === null) return 0n;

        let left = findTreeSum(node.left);
        let right = findTreeSum(node.right);

        return BigInt(node.val) + left + right;
    }

    // utility function to find subtree sum
    function findSubtreeSum(node) {
        if (node === null) return 0n;

        let left = findSubtreeSum(node.left);
        let right = findSubtreeSum(node.right);
        let subtreeSum = BigInt(node.val) + left + right;

        let remaining = sum - subtreeSum;
        maxP = maxP > subtreeSum * remaining ? maxP : subtreeSum * remaining;

        return subtreeSum;
    }

    // step 1 - find binary tree sum
    sum = findTreeSum(root);

    // step 2 - find subtree sum
    findSubtreeSum(root);

    // step 3 - return maximum product
    return Number(maxP % MOD);
};

// const nums = [1,2,3,4,5,6];

const nums = [1,null,2,3,4,null,null,5,6];
const root = buildTree(nums);
console.log(maxProduct(root));
