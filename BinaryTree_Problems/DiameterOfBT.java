
// Problem link - https://leetcode.com/problems/diameter-of-binary-tree/

package BinaryTree_Problems;

public class DiameterOfBT {
    static int ans;

    private static int findMaxDepthRec(TreeNodeUtil root){
        // base case: if root is null then maximum depth is 0
        if(root == null) return 0;

        // recursively compute maximum dpeth of left and right subtree
        int lst = findMaxDepthRec(root.left);
        int rst = findMaxDepthRec(root.right);

        // update global anwer 'ans' in each recurisve call
        ans = Math.max(ans, lst + rst + 1);

        // calculate maximum depth of left and right subtree
        return 1 + Math.max(lst, rst);
    }

    public static int diameterOfBinaryTree(TreeNodeUtil root) {
        ans = -1;
        findMaxDepthRec(root);
        // actual diameter will be ans - 1, 
        // as we are calculating diameter on the basis of edges
        return ans-1;
    }

    public static void main(String[] args) {
        BinaryTreeUtil bt = new BinaryTreeUtil();
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        bt.initializeTree(arr);

        int res = diameterOfBinaryTree(bt.root);
        System.out.print("Diameter of BT:"+res);
    }
}
