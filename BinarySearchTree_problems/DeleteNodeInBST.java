
// Problem link - https://leetcode.com/problems/delete-node-in-a-bst/description/

package BinarySearchTree_problems;

import java.util.*;

public class DeleteNodeInBST {

    public static TreeNode deleteNode(TreeNode root, int key) {
        // base case: if the tree is empty
        if(root == null) return null;

        // recursively search for the node to be deleted
        if(key < root.val){
            root.left = deleteNode(root.left, key);
        }else if(key > root.val){
            root.right = deleteNode(root.right, key);
        }else{
            // node to be deleted found
            // case 1: node has no children (leaf node)
            if(root.left == null && root.right == null){
                return null;
            }
            // case 2: node has only one child
            // case 2.1 : only right child exist
            if(root.left == null){
                return root.right;
            }else if(root.right == null){
                // case 2.2 : only left child exist
                return root.left;
            }

            // case 3: node has two children
            // find the inorder successor (smallest in the right subtree)
            TreeNode temp = root.right;
            while(temp.left != null){
                temp = temp.left;
            }
            // replace node's value with inorder successor's value
            root.val = temp.val;
            // delete the inorder successor
            root.right = deleteNode(root.right, temp.val);
        }
        return root;
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        int[] arr = {5, 3, 6, 2, 4, -1, 7};
        int key = 3;

        // build BST
        bst.buildBST(arr);

        // delete the node from BST
        bst.root = deleteNode(bst.root, key);

        // then print BST
        List<Integer> resList = bst.printBST();
        System.out.println("BST After deletion: "+ resList);
    }
}
