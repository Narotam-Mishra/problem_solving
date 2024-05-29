
// Problem link - https://leetcode.com/problems/house-robber-iii/description/

package BinaryTree_Problems;

import java.util.*;

public class HouseRobberIII {
    private static Map<TreeNode, Integer> mpTrue;
    private static Map<TreeNode, Integer> mpFalse;

    public static int rob(TreeNode root) {
        mpTrue = new HashMap<>();
        mpFalse = new HashMap<>();
        return maxMoneyRobbed(root, false);
    }

    private static int maxMoneyRobbed(TreeNode root, boolean isParentRobbed){
        // base case: if root doesn't exist then return 0
        if(root == null) return 0;

        // if answer is already computed then return computed answer
        if(isParentRobbed && mpTrue.containsKey(root)){
            return mpTrue.get(root);
        }

        if(!isParentRobbed && mpFalse.containsKey(root)){
            return mpFalse.get(root);
        }

        // recursive case: recursively find maximum robber amount for left and right subtree
        // two cases: either parent node is robbed or not robbed

        // case1: if parent is not robbed
        if(!isParentRobbed){
            int leave = maxMoneyRobbed(root.left, false) + maxMoneyRobbed(root.right, false);
            int take = root.val + maxMoneyRobbed(root.left, true) + maxMoneyRobbed(root.right, true);

            // calculate maximum robbed amount in 'ans'
            int ans = Math.max(leave, take);
            // store answer 'ans' into map
            mpFalse.put(root, ans);
            return ans;
        }else{
            // otherwise parent is robbed
            int leave = maxMoneyRobbed(root.left, false) + maxMoneyRobbed(root.right, false);
            int ans = leave;
            // store answer 'ans' into map
            mpTrue.put(root, ans);
            return ans;
        }
    }

    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();
        // int[] arr = {3, 2, 3, -1, 3, -1, 1};

        int[] arr = {3, 4, 5, 1, 3, -1, 1};
        bt.initializeTreeUtil(arr);
        System.out.println("Maximum Amount of money the thief can rob : "+rob(bt.root));
    }
}
