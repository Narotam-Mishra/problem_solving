
// Problem link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

package BinarySearchTree_problems;

public class KthSmallestElementInBST {
    public static int ans, count;
    private static void inOrderTraversalRec(TreeNode node){
        // base case:
        if(node == null) return;

        // recursively traverse left and right subtree
        // recursive call to left subtree
        inOrderTraversalRec(node.left);

        // decrement count and check if the current node is the k-th smallest
        count--;
        if(count == 0){
            ans = node.val;
            return;
        }

        // recursive call to right subtree
        inOrderTraversalRec(node.right);
    }

    public static int kthSmallest(TreeNode root, int k) {
        count = k;
        ans = -1;
        inOrderTraversalRec(root);
        return ans;
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        int[] arr = {5, 3, 6, 2, 4, -1, -1, 1};
        int k = 3;
        bst.buildBST(arr);
        System.out.println("Kth Smallest element in BST: "+kthSmallest(bst.root, k));
    }
}