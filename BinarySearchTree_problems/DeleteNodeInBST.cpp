
// Problem link - https://leetcode.com/problems/delete-node-in-a-bst/description/

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree(){
        this->root = nullptr;
    }

    // insert node into BST recursively
    TreeNode* insertNodeIntoBST(TreeNode* root, int val){
        if(root == nullptr){
            return new TreeNode(val);
        }
        if(root->val > val){
            root->left = insertNodeIntoBST(root->left, val);
        }else{
            root->right = insertNodeIntoBST(root->right, val);
        }
        return root;
    }

    // utility method to build BST
    void buildBST(vector<int>& arr){
        for(int value : arr){
            if(value != -1){
                this->root = insertNodeIntoBST(this->root, value);
            }
        }
    }

    // utility method to search into BST recursively
    TreeNode* serachIntoBSTRec(TreeNode* curr, int val) {
        // base case 1:
        if (curr == nullptr) return nullptr;

        // base case 2:
        if (val == curr->val) return curr;

        // recursive case:
        else if (val < curr->val) {
            return serachIntoBSTRec(curr->left, val);
        }
        return serachIntoBSTRec(curr->right, val);
    }

    // utility method to print BST Nodes
    vector<int> printBST(){
        // corner case:
        vector<int> resList;
        if(this->root == nullptr) return resList;

        // using queue to print BST
        queue<TreeNode*> q;
        q.push(this->root);

        // iterate queue until it is empty
        while (!q.empty()){
            TreeNode* treeNode = q.front();
            q.pop();
            if(treeNode != nullptr){
                resList.push_back(treeNode->val);
                q.push(treeNode->left);
                q.push(treeNode->right);
            }else{
                resList.push_back(-1);
            }
        }
        
        // remove trailing NULLs
        while(!resList.empty() && resList.back() == -1){
            resList.pop_back();
        }

        // return result list
        return resList;
    }

    // utility method to print 1-D Vector
    void printOneDVectorFormat(vector<int>& result) {
        cout << "[";
        for (size_t i = 0; i < result.size(); ++i) {
            cout<<result[i]<<" ";
            // Only add a comma and space if not the last element
            if (i != result.size() - 1) { 
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
};

TreeNode* deleteNode(TreeNode* root, int key) {
    // base case: if the tree is empty
    if (root == nullptr) return nullptr;

    // recursively search for the node to be deleted
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // node to be deleted found
        // case 1: node has no children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        // case 2: node has only one child
        // case 2.1 : only right child exist
        if (root->left == nullptr) {
            return root->right;
        }
        else if (root->right == nullptr) {
            // case 2.2 : only left child exist
            return root->left;
        }

        // case 3: node has two children
        // find the inorder successor (smallest in the right subtree)
        TreeNode* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        // replace node's value with inorder successor's value
        root->val = temp->val;
        // delete the inorder successor
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main(){
    BinarySearchTree bst;
    vector<int> arr = {5, 3, 6, 2, 4, -1, 7};
    int key = 3;

    // build BST
    bst.buildBST(arr);

    // delete the node from BST
    bst.root = deleteNode(bst.root, key);

    // then print BST
    vector<int> resList = bst.printBST();
    bst.printOneDVectorFormat(resList); 
    return 0;
}
