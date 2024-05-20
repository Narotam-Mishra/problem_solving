
// Problem link - https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

package BinaryTree_Problems;

import java.util.*;

public class BTLevelOrderTraversalII {
    // Function to perform level order traversal of the binary tree
    public static List<List<Integer>> levelOrderBottom(TreeNodeUtil root){
        // to store tree's data in result 'res' array
        List<List<Integer>> res = new ArrayList<>();
        //corner case: if root is null then return empty array
        if(root == null) return res;

        Queue<TreeNodeUtil> qu = new LinkedList<>();
        // first we insert root of the tree to the Queue
        qu.offer(root);
        // traverse queue
        while (!qu.isEmpty()) {
            int size = qu.size();
            // to store each level data we used levelArr
            List<Integer> levelArr = new ArrayList<>();
            // iterate level array
            for(int i=0; i<size; i++){
                // get front node from queue
                TreeNodeUtil curr = qu.poll();
                // store first node's data (val) into level array 'levelArr' 
                levelArr.add(curr.val);
                // recursively traverse left and right node of tree for each level
                if(curr.left != null) qu.offer(curr.left); 
                if(curr.right != null) qu.offer(curr.right); 
            }
            // add levelArr into result list 'res'
            res.add(levelArr);
        }
        Collections.reverse(res);
        return res;
    }

    public static void main(String[] args) {
        BinaryTreeUtil bt = new BinaryTreeUtil();
        int[] arr = {1, 2, 3, 4, 5, 6, 7};
        bt.initializeTree(arr);

        System.out.println("Reading binary tree data using level Order traversal in reverse order:");
        List<List<Integer>> res = levelOrderBottom(bt.root);
        System.out.println(res);
    }
}
