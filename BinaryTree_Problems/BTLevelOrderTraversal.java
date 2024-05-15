
// Problem link - https://leetcode.com/problems/binary-tree-level-order-traversal/


package BinaryTree_Problems;

import java.util.*;

class TreeNode{
    int val;
    TreeNode left, right;

    public TreeNode(int val){
        this.val = val;
        left = right = null;
    }
}

class BinaryTree{
    TreeNode root;

    // constructor to initialize the root
    public BinaryTree(){
        root = null;
    }

    // Function to insert data into the binary tree
    void insertData(int val) {
        TreeNode newNode = new TreeNode(val);
        if (root == null) {
            root = newNode;
        } else {
            insertNode(root, newNode);
        }
    }

    // Function to recursively insert a node into the binary tree
    void insertNode(TreeNode node, TreeNode newNode) {
        if (node.left == null) {
            node.left = newNode;
        } else if (node.right == null) {
            node.right = newNode;
        } else {
            insertNode(node.left, newNode);
        }
    }

    // Utility method to create a binary tree
    public TreeNode createBinaryTree(int[] arr, int index){
        TreeNode temp = null;
        if(index < arr.length){
            temp = new TreeNode(arr[index]);
            temp.left = createBinaryTree(arr, 2 * index + 1);
            temp.right = createBinaryTree(arr, 2 * index + 2);
        }
        return temp;
    }

    // Function to perform level order traversal of the binary tree
    public List<List<Integer>> levelOrder(TreeNode root){
        // to store tree's data in result 'res' array
        List<List<Integer>> res = new ArrayList<>();
        //corner case: if root is null then return empty array
        if(root == null) return res;

        Queue<TreeNode> qu = new LinkedList<>();
        // first we insert root of the tree to the Queue
        qu.offer(root);
        // traverse queue
        while (!qu.isEmpty()) {
            int size = qu.size();
            // to store each level data we used levelArr
            List<Integer> levelArr = new ArrayList<>();
            // iterate level array
            for(int i=0; i<size; i++){
                // get front node from queue
                TreeNode curr = qu.poll();
                // store first node's data (val) into level array 'levelArr' 
                levelArr.add(curr.val);
                // recursively traverse left and right node of tree for each level
                if(curr.left != null) qu.offer(curr.left); 
                if(curr.right != null) qu.offer(curr.right); 
            }
            // add levelArr into result list 'res'
            res.add(levelArr);
        }
        return res;
    }

    // Utility method to display level order traversal result
    public void displayLevelOrder(List<List<Integer>> result){
        for(List<Integer> level : result){
            for(int val : level){
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}

public class BTLevelOrderTraversal {
    public static void main(String[] args) {
        /*int[] arr = {3, 9, 20, -1, -1, 15, 7};
        BinaryTree bt = new BinaryTree();
        bt.root = bt.createBinaryTree(arr, 0);
        // List<List<Integer>> result = bt.levelOrder(bt.root);
        System.out.println("Reading binary tree data in level order traversal:");
        // bt.displayLevelOrder(result);
        System.out.println(bt.levelOrder(bt.root)); */

        BinaryTree bt = new BinaryTree();
        bt.insertData(1);
        bt.insertData(2);
        bt.insertData(3);
        bt.insertData(4);
        bt.insertData(5);
        bt.insertData(6);
        bt.insertData(7);

        System.out.println("Reading binary tree data in level order traversal:");
        System.out.println(bt.levelOrder(bt.root));
    }
}