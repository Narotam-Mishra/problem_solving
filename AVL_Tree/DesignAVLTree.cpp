
// Design your own AVL Tree with its important methods

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree(){
        root = nullptr;
    }

    // Utility method to perform right rotation in AVL Tree
    Node* rightRotate(Node* alpha){
        // alpha is the unbalanced node
        // Initialize nodes
        Node* beta = alpha->left;
        Node* sigma = beta->right;

        // Right rotation
        beta->right = alpha;
        alpha->left = sigma;

        // Update heights of alpha and beta nodes
        // Update height of alpha first, because height of beta depends on it
        alpha->height = max(calcHeight(alpha->left), calcHeight(alpha->right)) + 1;
        beta->height = max(calcHeight(beta->left), calcHeight(beta->right)) + 1;

        // Return the new root beta
        return beta;
    }

    // Utility method to perform left rotation in AVL Tree
    Node* leftRotate(Node* alpha){
        // alpha is the unbalanced node
        // Initialize nodes
        Node* beta = alpha->right;
        Node* sigma = beta->left;

        // Left rotation
        beta->left = alpha;
        alpha->right = sigma;

        // Update heights of alpha and beta nodes
        // Update height of alpha first, because height of beta depends on it
        alpha->height = max(calcHeight(alpha->left), calcHeight(alpha->right)) + 1;
        beta->height = max(calcHeight(beta->left), calcHeight(beta->right)) + 1;

        // Return the new root beta
        return beta;
    }

    // Utility method to calculate the height for each node in AVL Tree
    int calcHeight(Node* node){
        if(node == nullptr) return 0;
        return node->height;
    }

    // Utility method to calculate the balacing factor for each node 
    int getBalancingFactor(Node* node){
        if(node == nullptr) return 0;
        return calcHeight(node->left) - calcHeight(node->right);
    }

    // Utility method to insert into AVL Tree node
    Node* insert(Node* alpha, int data){
        // edgae case;
        if(alpha == nullptr) return new Node(data);

        // If alpha is not null, then you are on an existing node
        // Now decide whether this data should be inserted in the left or right subtree of the current node
        if(alpha->data > data){
            // Go to left subtree
            alpha->left = insert(alpha->left, data);
        }else if(alpha->data < data){
            // Go to right subtree
            alpha->right = insert(alpha->right, data);
        }

        // Update the height as new data has been inserted
        alpha->height = max(calcHeight(alpha->left), calcHeight(alpha->right)) + 1;

        // This part is executing while coming back in the recursion
        // Start balancing
        int balanceFactor = getBalancingFactor(alpha);

        // If the 'balanceFactor' is greater than 1 or less than -1, then we have alpha(root) unbalanced
        if(balanceFactor > 1){
            // It means tree is left heavy
            // How to decide if we need to do right rotation or left-right rotation
            Node* beta = alpha->left;
            if(data < beta->data){
                // Right rotation
                return rightRotate(alpha);
            }else{
                // Left-right rotation
                alpha->left = leftRotate(alpha->left);
                return rightRotate(alpha);
            }
        } else if(balanceFactor < -1){
            // Otherwise tree is right heavy
            // How to decide if we need to do left rotation or right-left rotation
            Node* beta = alpha->right;
            if(data > beta->data){
                // Left rotation
                return leftRotate(alpha);
            }else{
                // Right-left rotation
                alpha->right = rightRotate(alpha->right);
                return leftRotate(alpha);
            }
        }

        // If BST is already balanced, then return balanced root, alpha
        return alpha;
    }

    // insert helper method
    void insertInAVLTree(int data){
        root = insert(root, data);
    }

    // Utility method to perfrom preorder traversal
    void preOrderRec(Node* node, vector<int>& res) {
        // Base case
        if (node == nullptr) return;
        res.push_back(node->data);
        // Recursive case
        preOrderRec(node->left, res);
        preOrderRec(node->right, res);
    }

    vector<int> preorderTraversal() {
        vector<int> res;
        preOrderRec(root, res);
        return res;
    }

    // Utility method to perfrom inorder traversal
    void inOrderRec(Node* node, vector<int>& res) {
        // Base case
        if (node == nullptr) return;
        
        // Recursive case
        inOrderRec(node->left, res);
        res.push_back(node->data);
        inOrderRec(node->right, res);
    }

    vector<int> inorderTraversal() {
        vector<int> res;
        inOrderRec(root, res);
        return res;
    }

    // Utility method to perfrom postorder traversal
    void postOrderRec(Node* node, vector<int>& res) {
        // Base case
        if (node == nullptr) return;
        // Recursive case
        postOrderRec(node->left, res);
        postOrderRec(node->right, res);
        res.push_back(node->data);
    }

    vector<int> postorderTraversal() {
        vector<int> res;
        postOrderRec(root, res);
        return res;
    }

    // Utility method to perfrom levelorder traversal
    vector<vector<int>> levelOrder(Node* root) {
        // Corner case: if root is null then return empty array
        if (root == nullptr) return {};
        queue<Node*> qu;
        // First we insert root of the tree to the Queue
        qu.push(root);
        // Marker nullptr indicates end of the level
        qu.push(nullptr);
        // To store tree's data in result 'res' array
        vector<vector<int>> res;
        // To store each level data we used levelArr
        vector<int> levelArr;
        // Traverse queue
        while (!qu.empty()) {
            // Get front node from queue
            Node* curr = qu.front();
            qu.pop();
            if (curr == nullptr) {
                // This shows end of last level
                if (!qu.empty()) {
                    // If queue is not empty then we have all elements in queue of the next level
                    // Before we refresh level array it has data of the last level, so we push into result 'res' array
                    res.push_back(levelArr);
                    // Again add marker nullptr
                    qu.push(nullptr);
                    // In the end refresh level array
                    levelArr.clear();
                } else {
                    res.push_back(levelArr);
                }
            } else {
                levelArr.push_back(curr->data);
                // Recursively traverse left and right node of tree for each level
                if (curr->left != nullptr) qu.push(curr->left);
                if (curr->right != nullptr) qu.push(curr->right);
            }
        }
        return res;
    }

    vector<vector<int>> levelOrderTraversal() {
        return levelOrder(root);
    }
};

int main(){
    AVLTree tree;
    tree.insertInAVLTree(1);
    tree.insertInAVLTree(2);
    tree.insertInAVLTree(3);
    tree.insertInAVLTree(4);
    tree.insertInAVLTree(5);
    tree.insertInAVLTree(6);
    tree.insertInAVLTree(7);

    vector<int> preOrder = tree.preorderTraversal();
    cout << "Preorder Traversal: ";
    for (int data : preOrder) {
        cout << data << " ";
    }
    cout << endl;

    vector<int> inOrder = tree.inorderTraversal();
    cout << "Inorder Traversal: ";
    for (int data : inOrder) {
        cout << data << " ";
    }
    cout << endl;

    vector<int> postOrder = tree.postorderTraversal();
    cout << "Postorder Traversal: ";
    for (int data : postOrder) {
        cout << data << " ";
    }
    cout << endl;

    vector<vector<int>> levelOrder = tree.levelOrderTraversal();
    cout << "Level Order Traversal: " << endl;
    for (auto level : levelOrder) {
        for (int data : level) {
            cout << data << " ";
        }
        cout << endl;
    }

    return 0;
}