
// Problem link - https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

package BinaryTree_Problems;

public class MaxDepthOfBT {
    private static int findMaxDepthOfBT(TreeNodeUtil root){
        //base case: depth of empty tree is zero
        if(root == null) return 0;

        // recursive case:
        return 1 + Math.max(findMaxDepthOfBT(root.left), findMaxDepthOfBT(root.right));
    }
    public static int maxDepth(TreeNodeUtil root) {
        return findMaxDepthOfBT(root);
    }

    public static void main(String[] args) {
        BinaryTreeUtil bt = new BinaryTreeUtil();
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        bt.initializeTree(arr);
        System.out.print("Maximum Depth of Binary Tree:"+maxDepth(bt.root));
    }
}