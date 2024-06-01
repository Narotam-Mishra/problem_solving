
// Problem link - https://leetcode.com/problems/search-in-a-binary-search-tree/description/

package BinarySearchTree_problems;

public class SearchInBST {
    private static TreeNode serchBSTRec(TreeNode node, int val){
        // base case 1:
        if(node == null) return null;

        // base case 2:
        if(val == node.val) return node;

        else if(val < node.val){
            return serchBSTRec(node.left, val);
        }
        return serchBSTRec(node.right, val);
    }

    public static TreeNode searchBST(TreeNode root, int val) {
        return serchBSTRec(root, val);
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        int[] arr = {4, 2, 7, 1, 3};
        int value = 2;
        bst.buildBST(arr);

        bst.root = searchBST(bst.root, value);
        System.out.println(bst.printBST());
    }
}