
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        this->val = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree{
public:
    TreeNode* root;

    BinaryTree(){
        this->root = nullptr;
    }

    // Utility method to create a binary tree from an array
    TreeNode* createBinaryTree(const vector<int>& arr, int index){
        if(index < arr.size()){
            TreeNode* temp = new TreeNode(arr[index]);
            temp->left = createBinaryTree(arr, 2 * index + 1);
            temp->right = createBinaryTree(arr, 2 * index + 2);
            return temp;
        }
        return nullptr;
    }

    // Initialize the binary tree with the given array
    void initializeTree(const vector<int>& arr){
        this->root = createBinaryTree(arr, 0);
    }
};

int solveRec(TreeNode* root, int val){
    // base case
    if(root == NULL) return 0;

    // calculate sum for each level
    val = (2 * val) + root->val;

    // edge case 
    if(root->left == NULL && root->right == NULL){
        return val;
    }

    // recursively compute sum for left and right subtree
    return solveRec(root->left, val) + solveRec(root->right, val);
}

int sumRootToLeaf(TreeNode* root) {
    // step 1 - recursively solve and return
    return solveRec(root, 0);
}

int main(){
    BinaryTree bt;
    vector<int> arr = {1, 0, 1, 0, 1, 0, 1};
    bt.initializeTree(arr);
    cout<<sumRootToLeaf(bt.root);
    return 0;
}