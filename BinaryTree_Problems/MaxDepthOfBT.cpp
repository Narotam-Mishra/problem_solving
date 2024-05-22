
// Problem link - https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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

    // recursive helper function to find maximum depth of BT
    int findMaxDepthOfBT(TreeNode* root){
        //base case: depth of empty tree is zero
        if(root == nullptr) return 0;

        // recursive case:
        return 1 + max(findMaxDepthOfBT(root->left), findMaxDepthOfBT(root->right));
    }

    // find maximum depth of BT
    int maxDepth(TreeNode* root) {
        return findMaxDepthOfBT(root);
    }
};

int main(){
    BinaryTree bt;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    bt.initializeTree(arr);
    cout <<"Maximum Depth of Binary Tree:"<<bt.maxDepth(bt.root)<<endl;
    return 0;
}