
// Problem link - https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

package BinaryTree_Problems;

public class BTMaximumPathSum {
    public static int ans = 0;
    private static int findMaxPathSumRec(TreeNode root){
        // base case:
        if(root == null) return 0;

        // recursive case: recusively find left and right subtree sum
        int lst = Math.max(0, findMaxPathSumRec(root.left));
        int rst = Math.max(0, findMaxPathSumRec(root.right));

        // calculate maximum sum
        int maxSumPath = root.val + lst + rst;

        // update max path sum in 'ans'
        ans = Math.max(ans, maxSumPath);

        // return maximum path sum
        return root.val + Math.max(lst, rst);
    }
    public static int maxPathSum(TreeNode root) {
        ans = Integer.MIN_VALUE;
        findMaxPathSumRec(root);
        return ans;
    }

    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();
        int[] arr = {-10, 9, 20, -1, -1, 15, 7};
        bt.initializeTreeUtil(arr);
        System.out.println(maxPathSum(bt.root));
    }
}