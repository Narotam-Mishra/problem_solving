
// Problem link - https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
};

int ans;
int findMaxPathSumRec(TreeNode* root){
    // base case:
    if(root == nullptr) return 0;

    // recursive case: recusively find left and right subtree sum
    int lst = max(0, findMaxPathSumRec(root->left));
    int rst = max(0, findMaxPathSumRec(root->right));

    // calculate maximum sum
    int maxSumPath = root->val + lst + rst;

    // update max path sum in 'ans'
    ans = max(ans, maxSumPath);

    // return maximum path sum
    return root->val + max(lst, rst);
}
int maxPathSum(TreeNode* root) {
    ans = INT_MIN;
    findMaxPathSumRec(root);
    return ans;
}

int main(){
    BinaryTree bt;
    vector<int> arr = {-10, 9, 20, -1, -1, 15, 7};
    bt.initializeTree(arr);
    cout<<"Maximum Path Sum: "<<maxPathSum(bt.root)<<endl;
    return 0;
}