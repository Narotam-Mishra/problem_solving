
// Problem link - https://leetcode.com/problems/binary-tree-inorder-traversal/

package BinaryTree_Problems;

import java.util.*;

public class BTInOrderTraversal {
    public static void InOrderRec(TreeNodeUtil root, List<Integer> res){
        // base case:
        if(root == null) return;

        // recursive case:
        InOrderRec(root.left, res);
        res.add(root.val);
        InOrderRec(root.right, res);
    }
    public static List<Integer> inorderTraversal(TreeNodeUtil root) {
        List<Integer> res = new ArrayList<>();
        InOrderRec(root, res);
        return res;
    }

    public static void main(String[] args) {
        BinaryTreeUtil bt = new BinaryTreeUtil();
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        bt.initializeTree(arr);

        System.out.println("Reading binary tree data using InOrder traversal:");
        List<Integer> res = inorderTraversal(bt.root);
        System.out.println(res);
    }
}