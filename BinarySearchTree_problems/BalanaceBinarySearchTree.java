
// Problem link - https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2026-02-09

package BinarySearchTree_problems;

import java.util.*;

public class BalanaceBinarySearchTree {
    // perform Inorder traversal
    private void performInOrder(TreeNode root, List<Integer> arr){
        if(root == null) return;

        performInOrder(root.left, arr);
        arr.add(root.val);
        performInOrder(root.right, arr);
    }

    // build Balanced BST using sorted array
    private TreeNode buildBalancedBST(int s, int e, List<Integer> arr){
        if(s > e) return null;

        int mid = s + (e - s) / 2;

        TreeNode root = new TreeNode(arr.get(mid));
        root.left = buildBalancedBST(s, mid - 1, arr);
        root.right = buildBalancedBST(mid + 1, e, arr);

        return root;
    }

    public TreeNode balanceBST(TreeNode root) {
        List<Integer> arr = new ArrayList<>();
        performInOrder(root, arr);
        return buildBalancedBST(0, arr.size() - 1, arr);
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        // int[] arr = {1,-1,2,-1,3,-1,4,-1,-1};

        int[] arr = {2,1,3};
        bst.buildBST(arr);
        BalanaceBinarySearchTree bt = new BalanaceBinarySearchTree();
        bst.root = bt.balanceBST(bst.root);
        System.out.println(bst.printBST());
    }
}
