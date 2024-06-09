
// Problem link - https://leetcode.com/problems/validate-binary-search-tree/description/

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
};

bool isValidBSTRec(TreeNode* root, long long lowerVal, long long upperVal){
    // Base case: if root doesn't exist then return true
    if(root == nullptr) return true;

    // base case: the current tree node's value must be within the range 
    // and the right subtree with updated lower bound.
    if(root->val <= lowerVal || root->val >= upperVal) return false;

    // Recursively validate the left subtree with updated upper bound,
    // and the right subtree with updated lower bound.
    return isValidBSTRec(root->left, lowerVal, root->val) && isValidBSTRec(root->right, root->val, upperVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTRec(root, LLONG_MIN, LLONG_MAX);
}

int main(){
    BinarySearchTree bst;
    // vector<int> arr = {2, 1, 3};

    vector<int> arr = {5, 1, 4, -1, -1, 3, 6};
    bst.buildBST(arr);
    if(isValidBST(bst.root)){
        cout<<"Is valid BST : "<<"true"<<endl; 
    }else{
        cout<<"Is valid BST : "<<"false"<<endl; 
    }
    return 0;
}