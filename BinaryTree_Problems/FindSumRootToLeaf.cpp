
// Problem link - https://leetcode.com/problems/sum-root-to-leaf-numbers/

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

    int ans;
    // recursive helper function to find maximum depth of BT
    void findSumRootToLeafRec(TreeNode* root, int sum){
        //base case: if current node is leaf node, then return root to leaf sum
        if(root->left == nullptr && root->right == nullptr){
            ans += (sum * 10) + root->val;
            return;
        }

        int num = (sum * 10) + root->val;
        // recursively calculate sum for left and right subtree
        if(root->left) findSumRootToLeafRec(root->left, num);
        if(root->right) findSumRootToLeafRec(root->right, num);
        return;
    }

    int sumNumbers(TreeNode* root) {
        ans = 0;
        findSumRootToLeafRec(root, 0);
        return ans;
    }
};

int main(){
    BinaryTree bt;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    bt.initializeTree(arr);
    cout <<"Find Sum of Root to Leaf Nodes:"<<bt.sumNumbers(bt.root)<<endl;
    return 0;
}