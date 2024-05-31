
// Problem link - https://leetcode.com/problems/construct-string-from-binary-tree/description/

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

    TreeNode* buildTreeNodeUtil(const vector<int>& arr) {
        if (arr.empty() || arr[0] == -1) return nullptr;

        TreeNode* root = new TreeNode(arr[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        // iterate on queue and build tree
        while (!q.empty() && i < arr.size()) {
            TreeNode* curr = q.front();
            q.pop();
            if (i < arr.size() && arr[i] != -1) {
                curr->left = new TreeNode(arr[i]);
                q.push(curr->left);
            }
            i++;
            if (i < arr.size() && arr[i] != -1) {
                curr->right = new TreeNode(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
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

string constructStringFromBT(TreeNode* root){
    // base case: if root is null
    if(root == nullptr) return "";

    // recursive case: recursively traverse left and right subtree
    string lst = constructStringFromBT(root->left);
    string rst = constructStringFromBT(root->right);

    // there will be total 4 possibilities : check for each one
    if(lst.empty() && rst.empty()){
        return to_string(root->val);
    }else if(lst.empty()){
        return to_string(root->val) + "()" + "(" + rst + ")";
    }else if(rst.empty()){
        return to_string(root->val) + "(" + lst + ")";
    }else{
        return to_string(root->val) + "(" + lst + ")" + "(" + rst + ")";
    }
}

string tree2str(TreeNode* root) {
    return constructStringFromBT(root);
}

int main(){
    BinaryTree bt;
    vector<int> arr = {1, 2, 3, -1, 4};
    bt.initializeTree(arr);
    cout<<tree2str(bt.root)<<endl;
    return 0;
}