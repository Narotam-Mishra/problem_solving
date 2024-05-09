
// Design Generic Tree (n-Ary Tree)

package BinaryTree_Problems;

import java.util.ArrayList;
import java.util.List;

class TreeNode{
    int value;
    List<TreeNode> children;

    TreeNode(int value){
        this.value = value;
        children = new ArrayList<>();
    }
}

class GenericTree{
    TreeNode root;

    GenericTree(){
        root = null;
    }

    void insertInTree(int value, int parentValue){
        TreeNode newNode = new TreeNode(value);
        if(parentValue == 0){
            if(root == null){
                root = newNode;
            }else{
                System.out.println("Cannot insert root node more than once!");
            }
        }else{
            TreeNode parentNode = findNode(root, parentValue);
            if(parentNode != null){
                parentNode.children.add(newNode);
            }else{
                System.out.println("Parent node not found!");
            }
        }
    }

    TreeNode findNode(TreeNode node, int value){
        if(node == null) return null;
        if(node.value == value) return node;
        for(TreeNode child : node.children){
            TreeNode foundNode = findNode(child, value);
            if(foundNode != null) return foundNode;
        }
        return null;
    }

    boolean searchInTree(int value){
        return searchNode(root, value);
    }

    boolean searchNode(TreeNode node, int value){
        if(node == null) return false;
        if(node.value == value) return true;
        for(TreeNode child : node.children){
            if(searchNode(child, value)) return true;
        }
        return false;
    }
}

public class DesignGenericTree {
    public static void main(String[] args) {
        GenericTree tree = new GenericTree();
        tree.insertInTree(1, 0);
        tree.insertInTree(2, 1);
        tree.insertInTree(3, 1);
        tree.insertInTree(4, 2);
        tree.insertInTree(5, 2);
        tree.insertInTree(6, 3);
        tree.insertInTree(7, 3);

        System.out.println(tree.searchInTree(5));
        System.out.println(tree.searchInTree(8));
    }
}