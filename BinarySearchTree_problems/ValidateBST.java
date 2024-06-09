
// Problem link - https://leetcode.com/problems/validate-binary-search-tree/description/

package BinarySearchTree_problems;

public class ValidateBST {
    private static boolean isValidBSTRec(TreeNode node, long lowerVal, long upperVal){
        // Base case: if root doesn't exist then return true
        if(node == null) return true;

        // base case: the current tree node's value must be within the range 
        // and the right subtree with updated lower bound.
        if(node.val <= lowerVal || node.val >= upperVal) return false;

        // Recursively validate the left subtree with updated upper bound,
        // and the right subtree with updated lower bound.
        return isValidBSTRec(node.left, lowerVal, node.val) && isValidBSTRec(node.right, node.val, upperVal);
    }

    public static boolean isValidBST(TreeNode root) {
        return isValidBSTRec(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        // int[] arr = {2, 1, 3};

        int[] arr = {5, 1, 4, -1, -1, 3, 6};
        bst.buildBST(arr);
        System.out.println("Is Valid BST : "+isValidBST(bst.root));
    }
}