
// Problem link - https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/?envType=daily-question&envId=2026-01-09

package BinaryTree_Problems;

import java.util.*;

public class SmallestSubtreeWithAllTheDeepestNodes {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    private static TreeNode buildTree(Integer[] arr) {
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

    private static Map<Integer, Integer> depthMap;
    private static int maxDepth;

    private static void findTreeDepth(TreeNode root, int d) {
        if (root == null) return;

        maxDepth = Math.max(maxDepth, d);
        depthMap.put(root.val, d);

        findTreeDepth(root.left, d + 1);
        findTreeDepth(root.right, d + 1);
    }

    private static TreeNode findLCA(TreeNode root) {
        if (root == null || depthMap.get(root.val) == maxDepth) {
            return root;
        }

        TreeNode left = findLCA(root.left);
        TreeNode right = findLCA(root.right);

        if (left != null && right != null) return root;
        return left != null ? left : right;
    }

    public static TreeNode subtreeWithAllDeepest(TreeNode root) {
        // reset
        depthMap = new HashMap<>();
        maxDepth = 0;

        // step 1 - find maximum depth and populate map
        findTreeDepth(root, 0);

        // step 2 - now find LCA of nodes having maximum depth
        return findLCA(root);
    }

    // 🔹 Print subtree in [2,7,4] format
    private static void printSubtree(TreeNode root) {
        if (root == null) {
            System.out.println("[]");
            return;
        }

        List<Integer> res = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            TreeNode curr = q.poll();
            res.add(curr.val);

            if (curr.left != null) q.add(curr.left);
            if (curr.right != null) q.add(curr.right);
        }

        System.out.println(res.toString().replace(" ", ""));
    }

    public static void main(String[] args) {
        Integer[] nums = {3,5,1,6,2,0,8,null,null,7,4};
        TreeNode root = buildTree(nums);
        TreeNode res = subtreeWithAllDeepest(root);
        printSubtree(res);
    }
}
