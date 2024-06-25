
//Problem link - https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

package BinarySearchTree_problems;

public class BST_To_GST {

    public static int sum;
    private static void traverseBST(TreeNode node){
        // base case: if root doesn't exist, return null
        if(node == null) return;

        // perform reverse In-Order traversal
        // traverse right subtree
        traverseBST(node.right);

        // update the sum and the node's value
        sum += node.val;
        node.val = sum;

        // traverse left subtree
        traverseBST(node.left);
    }
    
    public static TreeNode bstToGst(TreeNode root) {
        sum = 0;
        traverseBST(root);
        return root;
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        int[] arr = { 4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8 };
        bst.buildBST(arr);
        bst.root = bstToGst(bst.root);
        System.out.println(bst.printBST());
    }
}