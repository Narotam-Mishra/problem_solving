
// Problem link - https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

package BinaryTree_Problems;

import java.util.*;

public class FindLargestValueInEachTreeRow {
    public static List<Integer> largestValues(TreeNodeUtil root) {
        List<Integer> res = new ArrayList<>();
        // Corner case: if root is null, return an empty list
        if(root == null) return res;

        // Initialize the queue for level-order traversal
        Queue<TreeNodeUtil> queue = new LinkedList<>();
        // first we insert root of the tree to the Queue
        queue.offer(root);

        // Traverse the tree level by level
        while (!queue.isEmpty()){
            // get number of nodes at the current level
            int levelSize = queue.size();
            // Initialize max value for current level
            int maxVal = Integer.MIN_VALUE;

            // Process all nodes at the current level
            for(int i=0; i<levelSize; i++){
                // get current tree Node from queue
                TreeNodeUtil curr = queue.poll();

                // Update the maximum value for the current level
                maxVal = Math.max(maxVal, curr.val);

                // Enqueue left and right children if they exist
                if(curr.left != null) queue.offer(curr.left);
                if(curr.right != null) queue.offer(curr.right); 
            }

            // After processing each level, add the max value to the result list 'res'
            res.add(maxVal);
        }
        
        // return list 'res'
        return res;
    }

    public static void main(String[] args) {
        BinaryTreeUtil bt = new BinaryTreeUtil();
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        bt.initializeTree(arr);
        List<Integer> res = largestValues(bt.root);
        System.out.print("Largest Value for each tree row/level: "+res);
    }
}
