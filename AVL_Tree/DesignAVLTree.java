
// Design your own AVL Tree with its important methods

package AVL_Tree;

import java.util.*;

class Node {
    int data;
    Node left, right;
    int height;

    public Node(int data){
        this.data = data;
        this.left = this.right = null;
        this.height = 1;
    }
}

class AVLTree {
    Node root;

    public AVLTree(){
        root = null;
    }

    // Utility method to perform right rotation in AVL Tree
    private Node rightRotate(Node alpha){
        // alpha is the unbalanced node
        // Initialize nodes
        Node beta = alpha.left;
        Node sigma = beta.right;

        // Right rotation
        beta.right = alpha;
        alpha.left = sigma;

        // Update heights of alpha and beta nodes
        // Update height of alpha first, because height of beta depends on it
        alpha.height = Math.max(calcHeight(alpha.left), calcHeight(alpha.right)) + 1;
        beta.height = Math.max(calcHeight(beta.left), calcHeight(beta.right)) + 1;

        // Return the new root beta
        return beta;
    }

    // Utility method to perform left rotation in AVL Tree
    private Node leftRotate(Node alpha){
        // alpha is the unbalanced node
        // Initialize nodes
        Node beta = alpha.right;
        Node sigma = beta.left;

        // Left rotation
        beta.left = alpha;
        alpha.right = sigma;

        // Update heights of alpha and beta nodes
        // Update height of alpha first, because height of beta depends on it
        alpha.height = Math.max(calcHeight(alpha.left), calcHeight(alpha.right)) + 1;
        beta.height = Math.max(calcHeight(beta.left), calcHeight(beta.right)) + 1;

        // Return the new root beta
        return beta;
    }

    // Utility method to calculate the height for each node in AVL Tree
    public int calcHeight(Node node){
        if(node == null) return 0;
        return node.height;
    }

    // Utility method to calculate the balacing factor for each node 
    public int getBalancingFactor(Node node){
        if(node == null) return 0;
        return calcHeight(node.left) - calcHeight(node.right);
    }

    // insert helper method
    public void insertIntoAVLTree(int data){
        root = insert(root, data);
    }

    // Utility method to insert into AVL Tree node
    private Node insert(Node alpha, int data){
        if(alpha == null) return new Node(data);

        // If alpha is not null, then you are on an existing node
        // Now decide whether this data should be inserted in the left or right subtree of the current node
        if(alpha.data > data){
            // Go to left subtree for insertion
            alpha.left = insert(alpha.left, data);
        }else if(alpha.data < data){
            // Go to right subtree for insertion
            alpha.right = insert(alpha.right, data);
        }

        // Update the height as new data has been inserted
        alpha.height = Math.max(calcHeight(alpha.left), calcHeight(alpha.right)) + 1;

        // This part is executing while coming back in the recursion
        // Start balancing
        int balacingFactor = getBalancingFactor(alpha);

        // If the 'balanceFactor' is greater than 1 or less than -1, then we have alpha(root) unbalanced
        if(balacingFactor > 1){
            // It means tree is left heavy
            // How to decide if we need to do right rotation or left-right rotation
            Node beta = alpha.left;
            if(data < beta.data){
                // Right rotation
                return rightRotate(alpha);
            }else{
                // Left-right rotation
                alpha.left = leftRotate(alpha.left);
                return rightRotate(alpha);
            }
        }else if(balacingFactor < -1){
            // Otherwise tree is right heavy
            // How to decide if we need to do left rotation or right-left rotation
            Node beta = alpha.right;
            if(data > beta.data){
                // Left rotation
                return leftRotate(alpha);
            }else{
                // Right-left rotation
                alpha.right = rightRotate(alpha.right);
                return leftRotate(alpha);
            }
        }

        // If BST is already balanced, then return balanced node alpha
        return alpha;
    }

    // Utility method to perfrom preorder traversal
    private void preOrderRec(Node node, ArrayList<Integer> res) {
        // Base case
        if (node == null) return;
        res.add(node.data);
        // Recursive case
        preOrderRec(node.left, res);
        preOrderRec(node.right, res);
    }

    public ArrayList<Integer> preorderTraversal() {
        ArrayList<Integer> res = new ArrayList<>();
        preOrderRec(root, res);
        return res;
    }

    // Utility method to perfrom inorder traversal
    private void inOrderRec(Node node, ArrayList<Integer> res) {
        // Base case
        if (node == null) return;
        
        // Recursive case
        inOrderRec(node.left, res);
        res.add(node.data);
        inOrderRec(node.right, res);
    }

    public ArrayList<Integer> inorderTraversal() {
        ArrayList<Integer> res = new ArrayList<>();
        inOrderRec(root, res);
        return res;
    }

    // Utility method to perfrom postorder traversal
    private void postOrderRec(Node node, ArrayList<Integer> res) {
        // Base case
        if (node == null) return;
        // Recursive case
        postOrderRec(node.left, res);
        postOrderRec(node.right, res);
        res.add(node.data);
    }

    public ArrayList<Integer> postorderTraversal() {
        ArrayList<Integer> res = new ArrayList<>();
        postOrderRec(root, res);
        return res;
    }

    // Utility method to perfrom levelorder traversal
    private ArrayList<ArrayList<Integer>> levelOrder(Node root) {
        // Corner case: if root is null then return empty array
        if (root == null) return new ArrayList<>();
        Queue<Node> qu = new LinkedList<>();
        // First we insert root of the tree to the Queue
        qu.add(root);
        // Marker null indicates end of the level
        qu.add(null);
        // To store tree's data in result 'res' array
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        // To store each level data we used levelArr
        ArrayList<Integer> levelArr = new ArrayList<>();
        // Traverse queue
        while (!qu.isEmpty()) {
            // Get front node from queue
            Node curr = qu.poll();
            if (curr == null) {
                // This shows end of last level
                if (!qu.isEmpty()) {
                    // If queue is not empty then we have all elements in queue of the next level
                    // Before we refresh level array it has data of the last level, so we push into result 'res' array
                    res.add(levelArr);
                    // Again add marker null 
                    qu.add(null);
                    // In the end refresh level array
                    levelArr = new ArrayList<>();
                } else {
                    res.add(levelArr);
                }
            } else {
                levelArr.add(curr.data);
                // Recursively traverse left and right node of tree for each level
                if (curr.left != null) qu.add(curr.left);
                if (curr.right != null) qu.add(curr.right);
            }
        }
        return res;
    }

    public ArrayList<ArrayList<Integer>> levelOrderTraversal() {
        return levelOrder(root);
    }
}

public class DesignAVLTree {
    public static void main(String[] args) {
        AVLTree tree = new AVLTree();
        tree.insertIntoAVLTree(1);
        tree.insertIntoAVLTree(2);
        tree.insertIntoAVLTree(3);
        tree.insertIntoAVLTree(4);
        tree.insertIntoAVLTree(5);
        tree.insertIntoAVLTree(6);
        tree.insertIntoAVLTree(7);

        ArrayList<Integer> preOrder = tree.preorderTraversal();
        System.out.print("Preorder Traversal: ");
        for (int data : preOrder) {
            System.out.print(data + " ");
        }
        System.out.println();

        ArrayList<Integer> inOrder = tree.inorderTraversal();
        System.out.print("Inorder Traversal: ");
        for (int data : inOrder) {
            System.out.print(data + " ");
        }
        System.out.println();

        ArrayList<Integer> postOrder = tree.postorderTraversal();
        System.out.print("Postorder Traversal: ");
        for (int data : postOrder) {
            System.out.print(data + " ");
        }
        System.out.println();

        ArrayList<ArrayList<Integer>> levelOrder = tree.levelOrderTraversal();
        System.out.println("Level Order Traversal: ");
        for (ArrayList<Integer> level : levelOrder) {
            for (int data : level) {
                System.out.print(data + " ");
            }
            System.out.println();
        }
    }
}