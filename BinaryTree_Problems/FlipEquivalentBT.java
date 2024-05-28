
// Problem link - https://leetcode.com/problems/flip-equivalent-binary-trees/

package BinaryTree_Problems;

public class FlipEquivalentBT {
    private static boolean isFlipEquivalentBTRec(TreeNode root1, TreeNode root2) {
        // base case1: if both roots are null, then return true
        if (root1 == null && root2 == null)
            return true;

        // base case2: if either of the root is null then return false
        else if (root1 == null || root2 == null)
            return false;

        // base case3: if root's val are not equal then return false
        else if (root1.val != root2.val)
            return false;
        
        // recursive case: recursively check for left and right subtree
        else {
            return ((isFlipEquivalentBTRec(root1.left, root2.left) &&
                    isFlipEquivalentBTRec(root1.right, root2.right)) ||
                    (isFlipEquivalentBTRec(root1.left, root2.right) &&
                            isFlipEquivalentBTRec(root1.right, root2.left)));
        }
    }

    public static boolean flipEquiv(TreeNode root1, TreeNode root2) {
        return isFlipEquivalentBTRec(root1, root2);
    }

    public static void main(String[] args) {
        BinaryTree bt1 = new BinaryTree();
        Integer[] arr1 = {1,2,3,4,5,6,null,null,null,7,8};
        bt1.initializeTreeUtil(arr1);

        BinaryTree bt2 = new BinaryTree();
        Integer[] arr2 = {1,3,2,null,6,4,5,null,null,null,null,8,7};
        bt2.initializeTreeUtil(arr2);

        System.out.println("Is Binary Tree Flip Equivalent : "+flipEquiv(bt1.root, bt2.root));
    }
}