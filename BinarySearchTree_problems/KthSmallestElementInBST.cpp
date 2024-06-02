
// Problem link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
};

int cnt, ans;
void inOrderTraversalRec(TreeNode* root){
    // base case:
    if(root == nullptr) return;

    // recursively traverse left and right subtree
    // recursive call to left subtree
    inOrderTraversalRec(root->left);

    // decrement count and check if the current node is the k-th smallest
    cnt--;
    if(cnt == 0){
        ans = root->val;
        return;
    }

    // recursive call to right subtree
    inOrderTraversalRec(root->right);
    return;
}

int kthSmallest(TreeNode* root, int k) {
    cnt = k;
    inOrderTraversalRec(root);
    return ans;
}

int main(){
    BinarySearchTree bst;
    vector<int> arr = {5, 3, 6, 2, 4, -1, -1, 1};
    int k = 3;
    bst.buildBST(arr);
    cout<<"Kth Smallest element in BST: "<<kthSmallest(bst.root, k)<<endl;
    return 0;
}