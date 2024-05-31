
// Problem link - https://leetcode.com/problems/construct-string-from-binary-tree/description/

package BinaryTree_Problems;

public class ConstructStringFromBT {
    private static String constructStringFromBT(TreeNode root){
        // base case: if root is null
        if(root == null) return "";

        // recursive case: recursively traverse left and right subtree
        String lst = constructStringFromBT(root.left);
        String rst = constructStringFromBT(root.right);

        // there will be total 4 possibilities : check for each one
        if(lst.isEmpty() && rst.isEmpty()){
            return String.valueOf(root.val);
        }else if(lst.isEmpty()){
            return root.val + "()(" + rst + ")";
        }else if(rst.isEmpty()){
            return root.val + "(" + lst + ")";
        }else{
            return root.val + "(" + lst + ")(" + rst + ")";
        }
    }

    public static String tree2str(TreeNode root) {
        return constructStringFromBT(root);
    }

    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();
        int[] arr = {1, 2, 3, -1, 4};
        bt.initializeTreeUtil(arr);
        System.out.println(tree2str(bt.root));
    }
}