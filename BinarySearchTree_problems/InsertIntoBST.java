package BinarySearchTree_problems;

public class InsertIntoBST {
    public static TreeNode insertIntoBST(TreeNode root, int val) {
        if(root == null){
            return new TreeNode(val);
        }
        if(root.val > val){
            root.left = insertIntoBST(root.left, val);
        }else{
            root.right = insertIntoBST(root.right, val);
        }
        return root;
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        int[] arr = { 40, 20, 60, 10, 30, 50, 70 };
        int value = 25;
        bst.buildBST(arr);
        bst.root = insertIntoBST(bst.root, value);
        System.out.println("After Insertion: "+bst.printBST());
    }
}