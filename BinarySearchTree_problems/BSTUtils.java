package BinarySearchTree_problems;

import java.util.*;

class TreeNode{
    int val;
    TreeNode left, right;

    public TreeNode(int val){
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

class BinarySearchTree{
    TreeNode root;

    public BinarySearchTree(){
        this.root = null;
    }

    public void buildBST(int[] arr){
        for(int val : arr){
            if(val != -1){
                this.root = insertNodeIntoBST(root, val);
            }
        }
    }

    public TreeNode insertNodeIntoBST(TreeNode root, int val){
        if(root == null){
            return new TreeNode(val);
        }
        if(root.val > val){
            root.left = insertNodeIntoBST(root.left, val);
        }else{
            root.right = insertNodeIntoBST(root.right, val);
        }
        return root;
    }

    public List<Integer> printBST(){
        // corner case:
        List<Integer> resList = new ArrayList<>();
        if(this.root == null) return resList;

        // using que to print BST
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(this.root);

        // iterate queue untill it is empty
        while (!queue.isEmpty()) {
            TreeNode treeNode = queue.poll();
            if(treeNode != null){
                resList.add(treeNode.val);
                queue.add(treeNode.left);
                queue.add(treeNode.right);
            }else{
                resList.add(null);
            }
        }

        // remove trailing null
        while(resList.get(resList.size() - 1) == null){
            resList.remove(resList.size() - 1);
        }

        // return result list
        return resList;
    }
}

public class BSTUtils {
    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        int[] arr = { 40, 20, 60, 10, 30, 50, 70 };
        int value = 25;
        bst.buildBST(arr);
        bst.root = bst.insertNodeIntoBST(bst.root, value);
        System.out.println("After Insertion: "+bst.printBST());
    }
}
