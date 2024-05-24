
// Problem link - https://leetcode.com/problems/balanced-binary-tree/

package BinaryTree_Problems;

public class BalancedBinaryTree {
    static boolean ans;
    public static int findMaxDepthOfBT(TreeNodeUtil node){
        // base case:
        if(node == null) return 0;

        // recursive case:
        int lstHeight = findMaxDepthOfBT(node.left);
        int rstHeight = findMaxDepthOfBT(node.right);

        // calculate answer 'ans'
        ans = ans && (Math.abs(rstHeight - lstHeight) <= 1);

        // return maximum height of tree
        return 1 + Math.max(lstHeight, rstHeight);
    }
    public static boolean isBalanced(TreeNodeUtil root) {
        ans = true;
        findMaxDepthOfBT(root);
        return ans;
    }

    public static void main(String[] args) {
        BinaryTreeUtil bt = new BinaryTreeUtil();
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        bt.initializeTree(arr);

        boolean res = isBalanced(bt.root);
        System.out.print("Is Binary Tree Height Balanced:"+res);
    }
}