package BinaryTree_Problems;

import java.util.*;

class TreeNode{
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int value){
        this.val = value;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree{
	TreeNode root;

	BinaryTree(){
        this.root = null;
    }

    // utility method to convert tree to array 
    private List<Integer> treeToArrayUtil(TreeNode root){
        List<Integer> res = new ArrayList<>();
        List<TreeNode> queue = new ArrayList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.remove(0);
            if(node != null){
                res.add( node.val);
                queue.add(node.left);
                queue.add(node.right);
            }else{
                res.add(null);
            }
        }
        while(res.get(res.size() - 1) == null){
            res.remove(res.size() - 1);
        }
        return res;
    }

    public List<List<Integer>> convertTreesToArraysUtil(List<TreeNode> nodes){
        List<List<Integer>> res = new ArrayList<>();
        for(TreeNode tree : nodes){
            res.add(treeToArrayUtil(tree));
        }
        return res;
    }

    // Utility method to create a binary tree from an array
    TreeNode createBinaryTreeNodeUtil(Integer[] arr, int index){
        if(index < arr.length && arr[index] != null){
        	TreeNode temp = new TreeNode(arr[index]);
            temp.left = createBinaryTreeNodeUtil(arr, 2 * index + 1);
            temp.right = createBinaryTreeNodeUtil(arr, 2 * index + 2);
            return temp;
        }
        return null;
    }

    // Initialize the binary tree with the given array
    void initializeTreeUtil(Integer[] arr){
        this.root = createBinaryTreeNodeUtil(arr, 0);
    }
}

public class BinaryTreeTemplate {
    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();
        Integer[] arr = {1, 2, 3, 4, 5, 6, 7};
        bt.initializeTreeUtil(arr);

        // Creating a list of trees to pass to the convertTreesToArrays method
        List<TreeNode> nodeList = new ArrayList<>();
        nodeList.add(bt.root);

        // Convert the list of trees to arrays
        List<List<Integer>> res = bt.convertTreesToArraysUtil(nodeList);
        System.out.println("Converted Trees to Arrays: " + res);
    }
}
