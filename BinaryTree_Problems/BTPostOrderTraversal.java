
// Problem link - https://leetcode.com/problems/binary-tree-postorder-traversal/

package BinaryTree_Problems;

import java.util.*;

public class BTPostOrderTraversal {
    public static void postOrderRec(TreeNodeUtil node, List<Integer> res){
        // base case:
        if(node == null) return;

        // Recursive case:
        postOrderRec(node.left, res);
        postOrderRec(node.right, res);
        res.add(node.val);
    }
    public static List<Integer> postorderTraversal(TreeNodeUtil root) {
        List<Integer> res = new ArrayList<>();
        postOrderRec(root, res);
        return res;
    }

    public static void main(String[] args) {
        BinaryTreeUtil bt = new BinaryTreeUtil();
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        bt.initializeTree(arr);

        System.out.println("Reading binary tree data using post Order traversal:");
        List<Integer> res = postorderTraversal(bt.root);
        for(int val : res){
            System.out.print(val + " ");
        }
        System.out.println();
    }
}