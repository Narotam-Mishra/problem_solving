
// Problem link - https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/?envType=daily-question&envId=2026-02-24

package BinaryTree_Problems;

public class SumRootToLeafBinaryNumbers {
    
    // TreeNode definition
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    
    private static int solveRec(TreeNode root, int val) {
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

    public int sumRootToLeaf(TreeNode root) {
        return solveRec(root, 0);
    }
    
    public static void main(String[] args) {
        SumRootToLeafBinaryNumbers solution = new SumRootToLeafBinaryNumbers();
        
        // Test case: [1,0,1,0,1,0,1]
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(0);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(0);
        root.left.right = new TreeNode(1);
        root.right.left = new TreeNode(0);
        root.right.right = new TreeNode(1);
        
        int result = solution.sumRootToLeaf(root);
        System.out.println("Sum of root to leaf binary numbers: " + result);
    }
}
