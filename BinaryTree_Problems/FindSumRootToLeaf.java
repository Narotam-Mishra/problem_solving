
// Problem link - https://leetcode.com/problems/sum-root-to-leaf-numbers/

package BinaryTree_Problems;

public class FindSumRootToLeaf {
    public static int ans;
    
    public static void findSumRootToLeafRec(TreeNodeUtil node, int sum){
        //base case: if current node is leaf node, then return root to leaf sum
        if(node.left == null && node.right == null){
            ans += (sum * 10) + node.val;
            return;
        }

        int num = (sum * 10) + node.val;
        // recursively calculate sum for left and right subtree
        if(node.left != null) findSumRootToLeafRec(node.left, num);
        if(node.right != null) findSumRootToLeafRec(node.right, num);
        return;
    }

    public static int sumNumbers(TreeNodeUtil root) {
        ans = 0;
        findSumRootToLeafRec(root, 0);
        return ans;
    }

    public static void main(String[] args) {
        BinaryTreeUtil bt = new BinaryTreeUtil();
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        bt.initializeTree(arr);
        System.out.print("Find Sum of Root to Leaf Nodes: "+sumNumbers(bt.root));
    }
}
