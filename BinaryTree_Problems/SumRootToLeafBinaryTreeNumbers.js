
// Problem link - https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/?envType=daily-question&envId=2026-02-24

let sumRootToLeaf = function(root) {

    function solveRec(root, val) {
        // base case
        if (root == null) return 0;

        // calculate sum for each level
        val = (2 * val) + root.val;

        // edge case
        if (root.left == null && root.right == null) {
            return val;
        }

        // recursively compute sum for left and right subtree
        return solveRec(root.left, val) + solveRec(root.right, val);
    }

    return solveRec(root, 0);
};