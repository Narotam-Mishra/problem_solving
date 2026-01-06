
// Problem link - https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/?envType=daily-question&envId=2026-01-06

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

let maxLevelSum = function(root) {
    let maxSum = -Infinity;
    let resLevel = 0;
    let currLevel = 1;

    const queue = [root];

    while (queue.length) {
        let size = queue.length;
        let currSum = 0;

        while (size--) {
            const curr = queue.shift();
            currSum += curr.val;

            if (curr.left) queue.push(curr.left);
            if (curr.right) queue.push(curr.right);
        }

        if (currSum > maxSum) {
            maxSum = currSum;
            resLevel = currLevel;
        }

        currLevel++;
    }

    return resLevel;
}

// ---------- RUN ----------
// const nums = [1, 7, 0, 7, -8, null, null];

const nums = [989,null,10250,98693,-89388,null,null,null,-32127]
const root = buildTree(nums);
console.log(maxLevelSum(root));
