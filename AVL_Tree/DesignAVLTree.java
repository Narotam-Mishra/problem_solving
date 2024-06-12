
// Design your own AVL Tree with its important methods

package AVL_Tree;

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
    Node rightRotate(Node alpha){
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
    Node leftRotate(Node alpha){
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

    int calcHeight(Node node){
        if(node == null) return 0;
        return node.height;
    }
}

public class DesignAVLTree {
    public static void main(String[] args) {
        
    }
}