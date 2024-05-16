
// Problem link - https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
    void preOrderRec(TreeNode* node, vector<int>& res){
        // base case:
        if(node == nullptr) return;
        res.push_back(node->val);

        // Recursive case:
        preOrderRec(node->left, res);
        preOrderRec(node->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        preOrderRec(root, res);
        return res;
    }
};

int main(){
    BinaryTree bt;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    bt.initializeTree(arr);
    cout << "Reading binary tree data using pre-order traversal:"<<endl;
    vector<int> res = bt.preorderTraversal(bt.root);
    for(int val : res){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}