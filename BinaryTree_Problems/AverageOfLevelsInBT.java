
// Problem link - https://leetcode.com/problems/average-of-levels-in-binary-tree/

package BinaryTree_Problems;

import java.util.*;

public class AverageOfLevelsInBT {
    public static List<Double> averageOfLevels(TreeNodeUtil root) {
        // to store tree's data in result 'res' array
        List<Double> res = new ArrayList<>();
        //corner case: if root is null then return empty array
        if(root == null) return res;
        Queue<TreeNodeUtil> qu = new LinkedList<>();
        // first we insert root of the tree to the Queue
        qu.offer(root);
        // traverse queue
        while (!qu.isEmpty()) {
            int size = qu.size();
            // to calculate each level average we used levelSum and levelCount
            double levelSum = 0; 
            int levelCount = 0;

            // iterate level array
            for(int i=0; i<size; i++){
                // get front node from queue
                TreeNodeUtil curr = qu.poll();
                // Add current node's value to the level sum
                levelSum += curr.val;
                // Increment the level node count
                levelCount++;

                // recursively traverse left and right node of tree for each level
                if(curr.left != null) qu.offer(curr.left); 
                if(curr.right != null) qu.offer(curr.right); 
            }
            // calculate average 
            double levelAvg = levelSum / levelCount;
            res.add(levelAvg);
        }
        return res;
    }

    public static void main(String[] args) {
        BinaryTreeUtil bt = new BinaryTreeUtil();
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        bt.initializeTree(arr);

        System.out.println("Average of each Level in BT:");
        System.out.println(averageOfLevels(bt.root));
    }
}
