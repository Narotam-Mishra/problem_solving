
// Problem link - https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/?envType=daily-question&envId=2026-01-07

package BinaryTree_Problems;

import java.util.*;

public class MaximumProductOfSplittedBinaryTree {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    public static TreeNode buildTree(Integer[] arr) {
        if (arr.length == 0 || arr[0] == null) return null;

        TreeNode root = new TreeNode(arr[0]);
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        int i = 1;
        while (!q.isEmpty() && i < arr.length) {
            TreeNode curr = q.poll();

            // Left child
            if (i < arr.length && arr[i] != null) {
                curr.left = new TreeNode(arr[i]);
                q.offer(curr.left);
            }
            i++;

            // Right child
            if (i < arr.length && arr[i] != null) {
                curr.right = new TreeNode(arr[i]);
                q.offer(curr.right);
            }
            i++;
        }

        return root;
    }

    static long sum = 0;
    static  long maxP = 0;
    static final int MOD = 1_000_000_007;

    // utility function to find total sum of binary tree
    public static long findTreeSum(TreeNode root) {
        if (root == null) {
            return 0;
        }

        long leftSum = findTreeSum(root.left);
        long rightSum = findTreeSum(root.right);

        return root.val + leftSum + rightSum;
    }

    // utility function to find subtree sum and update max product
    public static long findSubtreeSum(TreeNode root) {
        if (root == null) {
            return 0;
        }

        long leftSum = findSubtreeSum(root.left);
        long rightSum = findSubtreeSum(root.right);
        long subtreeSum = root.val + leftSum + rightSum;

        long remainingSum = sum - subtreeSum;
        maxP = Math.max(maxP, subtreeSum * remainingSum);

        return subtreeSum;
    }

    public static int maxProduct(TreeNode root) {
        if (root == null) return 0;

        // reset
        sum = 0;
        maxP = 0;

        // step 1 - find total binary tree sum
        sum = findTreeSum(root);

        // step 2 - find subtree sum
        findSubtreeSum(root);

        // step 3 - return maximum product
        return (int)(maxP % MOD);
    }

    public static void main(String[] args) {
        // Integer[] nums = {1,2,3,4,5,6};

        Integer[] nums = {1,null,2,3,4,null,null,5,6};
        TreeNode root = buildTree(nums);
        System.out.println(maxProduct(root));
    }
}
