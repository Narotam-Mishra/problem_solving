
// Problem link - https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/?envType=daily-question&envId=2026-01-06

package BinaryTree_Problems;

import java.util.*;

public class MaximumLevelSumOfBinaryTree {
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

    public static int maxLevelSum(TreeNode root) {
        int maxSum = Integer.MIN_VALUE;
        int resLevel = 0;
        int currLevel = 1;

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while (!q.isEmpty()) {
            int size = q.size();
            int currSum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode curr = q.poll();
                currSum += curr.val;

                if (curr.left != null) q.offer(curr.left);
                if (curr.right != null) q.offer(curr.right);
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                resLevel = currLevel;
            }

            currLevel++;
        }

        return resLevel;
    }


    public static void main(String[] args) {
        // Integer[] nums = {1, 7, 0, 7, -8, null, null};

        Integer[] nums = {989,null,10250,98693,-89388,null,null,null,-32127};
        TreeNode root = buildTree(nums);
        System.out.println(maxLevelSum(root));
    }
}
