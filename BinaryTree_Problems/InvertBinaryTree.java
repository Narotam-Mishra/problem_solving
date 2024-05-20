
// Problem link - https://leetcode.com/problems/invert-binary-tree/

package BinaryTree_Problems;

import java.util.*;

public class InvertBinaryTree {

    public static void printInOrder(TreeNodeUtil root, List<Integer> res){
        // base case:
        if(root == null) return;
        // recursive case:
        printInOrder(root.left, res);
        res.add(root.val);
        printInOrder(root.right, res);
    }

    public static void invertTreeRec(TreeNodeUtil root){
        // base case:
        if(root == null) return;

        // recursive case:
        // recursively invert left subtree
        invertTree(root.left);

        // recursively invert right subtree
        invertTree(root.right);

        // swap nodes
        TreeNodeUtil temp = root.left;
        root.left = root.right;
        root.right = temp;
    }
    public static TreeNodeUtil invertTree(TreeNodeUtil root) {
        invertTreeRec(root);
        return root;
    }

    public static void main(String[] args) {
        BinaryTreeUtil bt = new BinaryTreeUtil();
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        bt.initializeTree(arr);

        invertTree(bt.root);

        List<Integer> res = new ArrayList<>();
        printInOrder(bt.root, res);
        System.out.print("Invert Binary Tree:"+res);
    }
}