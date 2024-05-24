
// Problem link - https://leetcode.com/problems/balanced-binary-tree/

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

    bool ans;

    // recursive helper function to find maximum depth of BT
    int findMaxDepthOfBT(TreeNode* root){
        //base case: depth of empty tree is zero
        if(root == nullptr) return 0;

        // recursively compute maximum dpeth of left and right subtree
        int lst = findMaxDepthOfBT(root->left);
        int rst = findMaxDepthOfBT(root->right);

        // update global anwer 'ans' in each recurisve call
        ans = ans && (abs(lst - rst) <= 1);

        // calculate maximum depth of left and right subtree
        return 1 + max(lst, rst);
    }

    // is BT height balanced
    bool isBalanced(TreeNode* root) {
        ans = true;
        findMaxDepthOfBT(root);
        return ans;
    }
};

int main(){
    BinaryTree bt;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    bt.initializeTree(arr);
    if(bt.isBalanced(bt.root)){
        cout <<"Is Binary Tree Height Balanced:"<<"true"<<endl;
    }else{
        cout <<"Is Binary Tree Height Balanced:"<<"false"<<endl;
    }
    
    return 0;
}