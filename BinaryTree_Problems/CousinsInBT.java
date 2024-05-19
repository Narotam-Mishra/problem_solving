
// Problem link - https://leetcode.com/problems/cousins-in-binary-tree/description/

/*
===> Two nodes of a binary tree are cousins if they have the same depth with different parents.
===> In other words, we can say that two nodes of a binary tree are cousins if they are on same level(depth) and they have different parent.
*/

package BinaryTree_Problems;

import java.util.*;

public class CousinsInBT {
    public static boolean isCousins(TreeNodeUtil root, int x, int y) {
        if(root == null) return false;

        // using queue
        Queue<TreeNodeUtil> queue = new LinkedList<>();
        // push current node into queue
        queue.add(root);

        // intially both nodes are at level are -1
        int l1 = -1, l2 = -1;
        // to maintain parent node for x and y
        TreeNodeUtil parentX = null, parentY = null;
        // calculate level (depth)
        int depth = 0;

        // traverse queue till it is empty
        while (!queue.isEmpty()) {
            int size = queue.size();

            // traverse current level of tree (by getting front element from queue using queue poll() method)
            while (size > 0) {
                TreeNodeUtil curr = queue.poll();

                // if left subtree of current node exist
                if(curr.left != null){
                    queue.add(curr.left);
                    if(curr.left.val == x){
                        l1 = depth + 1;
                        parentX = curr;
                    }
                    if(curr.left.val == y){
                        l2 = depth + 1;
                        parentY = curr;
                    }
                }

                // if right subtree of current node exist
                if(curr.right != null){
                    queue.add(curr.right);
                    if(curr.right.val == x){
                        l1 = depth + 1;
                        parentX = curr;
                    }
                    if(curr.right.val == y){
                        l2 = depth + 1;
                        parentY = curr;
                    }
                }
                size--;
            }
            // after each level incrent the depth
            depth++;

            if(l1 != -1 && l2 != -1){
                // it means we get level (depth) for both nodes elements x & y
                // level may be equal or unequal
                break;
            }
        }
        // Check if both nodes are at the same level and have different parents
        return (l1 == l2) && (parentX != parentY);
    }

    public static void main(String[] args) {
        BinaryTreeUtil bt = new BinaryTreeUtil();
        // int[] arr = {1,2,3,-1,4,-1,5};
        // int x = 5, y = 4;

        int[] arr = {1,2,3,4,};
        int x = 4, y = 3;
        bt.initializeTree(arr);

        System.out.print("Are both nodes cousin:");
        System.out.println(isCousins(bt.root, x, y));
    }
}
