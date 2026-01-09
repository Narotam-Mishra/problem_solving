
// Problem link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

package BinaryTree_Problems;

import java.util.*;

public class LowestCommonAncestorOfBinaryTree {
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

    public static TreeNode findNode(TreeNode root, int value) {
        if (root == null) return null;
        if (root.val == value) return root;

        TreeNode left = findNode(root.left, value);
        if (left != null) return left;

        return findNode(root.right, value);
    }

    public static TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // base case: reached end of tree
        if (root == null)
            return null;

        // step 1: if current node is p or q, return it
        if (root == p || root == q) {
            return root;
        }

        // step 2 - search in left subtree
        TreeNode leftSubtree = lowestCommonAncestor(root.left, p, q);

        // step 3 - search in right subtree
        TreeNode rightSubtree = lowestCommonAncestor(root.right, p, q);

        // step 4 - check if p and q found in different subtrees
        if (leftSubtree != null && rightSubtree != null) {
            // then root will be LCA
            return root;
        }

        // step 5 - otherwise return the non-null subtree result
        return (leftSubtree != null) ? leftSubtree : rightSubtree;
    }

    public static void main(String[] args) {
        // Integer[] nums = {3,5,1,6,2,0,8,null,null,7,4};
        // TreeNode root = buildTree(nums);
        // TreeNode p = findNode(root, 5);
        // TreeNode q = findNode(root, 4);

        // Integer[] nums = {3,5,1,6,2,0,8,null,null,7,4};
        // TreeNode root = buildTree(nums);
        // TreeNode p = findNode(root, 5);
        // TreeNode q = findNode(root, 1);

        Integer[] nums = {1,2};
        TreeNode root = buildTree(nums);
        TreeNode p = findNode(root, 1);
        TreeNode q = findNode(root, 2);

        TreeNode lca = lowestCommonAncestor(root, p, q);

        // output result
        if (lca != null) {
            System.out.println("Lowest Common Ancestor: " + lca.val);
        } else {
            System.out.println("LCA not found");
        }
    }
}
