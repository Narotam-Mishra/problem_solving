
// Problem link - https://leetcode.com/problems/binary-tree-inorder-traversal/

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

    // InOrder Traversal : left --> root ---> right
    void InOrderRec(TreeNode* node, vector<int>& res){
        // base case:
        if(node == nullptr) return;
        
        // Recursive case:
        InOrderRec(node->left, res);
        res.push_back(node->val);
        InOrderRec(node->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        InOrderRec(root, res);
        return res;
    }

    void printOneDVector(vector<int>& result) {
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

int main(){
    BinaryTree bt;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    bt.initializeTree(arr);
    cout << "Reading binary tree data using InOrder traversal:"<<endl;
    vector<int> res = bt.inorderTraversal(bt.root);
    bt.printOneDVector(res);
    return 0;
}