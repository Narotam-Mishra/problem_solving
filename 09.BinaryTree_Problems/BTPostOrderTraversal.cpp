
// Problem link - https://leetcode.com/problems/binary-tree-postorder-traversal/

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

    // preOrder Traversal : root --> left --> right
    void postOrderRec(TreeNode* node, vector<int>& res){
        // base case:
        if(node == nullptr) return;
        
        // Recursive case:
        postOrderRec(node->left, res);
        postOrderRec(node->right, res);
        res.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root){
        vector<int> res;
        postOrderRec(root, res);
        return res;
    }
};

int main(){
    BinaryTree bt;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    bt.initializeTree(arr);
    cout << "Reading binary tree data using post-order traversal:"<<endl;
    vector<int> res = bt.postorderTraversal(bt.root);
    for(int val : res){
        cout<<val<<" ";
    }
    cout<<endl;
    // Output - 4 5 2 6 7 3 1
    return 0;
}