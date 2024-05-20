
// Problem link - https://leetcode.com/problems/binary-tree-preorder-traversal/description/

package BinaryTree_Problems;

import java.util.*;

class TreeNodeUtil{
    int val;
    TreeNodeUtil left;
    TreeNodeUtil right;

    TreeNodeUtil(int value){
        this.val = value;
        this.left = null;
        this.right = null;
    }
}

class BinaryTreeUtil{
	TreeNodeUtil root;

	BinaryTreeUtil(){
        this.root = null;
    }

    // Utility method to create a binary tree from an array
    TreeNodeUtil createBinaryTreeNode(int[] arr, int index){
        if(index < arr.length){
        	TreeNodeUtil temp = new TreeNodeUtil(arr[index]);
            temp.left = createBinaryTreeNode(arr, 2 * index + 1);
            temp.right = createBinaryTreeNode(arr, 2 * index + 2);
            return temp;
        }
        return null;
    }

    // Initialize the binary tree with the given array
    void initializeTree(int[] arr){
        this.root = createBinaryTreeNode(arr, 0);
    }

    // Recursive method for pre-order traversal
    void preOrderRec(TreeNodeUtil node, List<Integer> res){
        // base case:
        if(node == null) return;
        res.add(node.val);

        // Recursive case:
        preOrderRec(node.left, res);
        preOrderRec(node.right, res);
    }

    // Public method to start pre-order traversal
    List<Integer> preorderTraversal(TreeNodeUtil root){
        List<Integer> res = new ArrayList<>();
        preOrderRec(root, res);
        return res;
    }
    
}

public class BinaryTreePreorderTraversal {

	public static void main(String[] args) {
		BinaryTreeUtil bt = new BinaryTreeUtil();
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        bt.initializeTree(arr);

        System.out.println("Reading binary tree data using pre-order traversal:");
        List<Integer> res = bt.preorderTraversal(bt.root);
        for(int val : res){
            System.out.print(val + " ");
        }
        System.out.println();
	}
}
