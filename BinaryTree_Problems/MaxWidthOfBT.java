
// Problem link - https://leetcode.com/problems/maximum-width-of-binary-tree/

package BinaryTree_Problems;

import java.util.*;

class PairNode {
    TreeNodeUtil treeNode;
    int index;
    PairNode(TreeNodeUtil treeNode, int index) {
        this.treeNode = treeNode;
        this.index = index;
    }
}

public class MaxWidthOfBT {
    public static int widthOfBinaryTree(TreeNodeUtil root) {
        // edge case: if root is null then return 0
        if(root == null) return 0;

        // 'maxWidth' to store maximum width of BT
        int maxWidth = 0;
        // create queue to store tree node and perfrom level order traversal
        Queue<PairNode> queue = new LinkedList<>();
        // Store the node and its index
        queue.offer(new PairNode(root, 0));

        // traverse queue until it is empty
        while(!queue.isEmpty()){
            int size = queue.size();
            // get the index of the first node in this level
            int leftIdx = queue.peek().index;
            // initialize rightIdx to leftIdx
            int rightIdx = leftIdx;

            // iterate through each node of a level
            for(int i=0; i<size; i++){
                PairNode curr = queue.poll();
                rightIdx = curr.index;

                // push left and right child of tree (if exist) into queue
                if(curr.treeNode.left != null){
                    queue.offer(new PairNode(curr.treeNode.left, 2 * curr.index + 1));
                }

                if(curr.treeNode.right != null){
                    queue.offer(new PairNode(curr.treeNode.right, 2 * curr.index + 2));
                }
            }
            // calculate max width for each level
            maxWidth = Math.max(maxWidth, rightIdx - leftIdx + 1);
        }
        // return maximum width
        return maxWidth;
    }
    
    public static void main(String[] args) {
        BinaryTreeUtil bt = new BinaryTreeUtil();
        // int[] arr = {1, 3, 2, 5, 3, -1, 9};
        int[] arr = {1, 3, 2, 5, -1, -1, 9, 6, -1, 7};
        bt.initializeTree(arr);
        System.out.println("Maximum Width of BT: "+widthOfBinaryTree(bt.root)); 
    }
}