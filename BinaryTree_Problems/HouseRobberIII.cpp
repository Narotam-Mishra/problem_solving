
// Problem link - https://leetcode.com/problems/house-robber-iii/description/

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
        if(index < arr.size() && arr[index] != -1){
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

unordered_map<TreeNode*, int> mpTrue;
unordered_map<TreeNode*, int> mpFalse;

int maxMoneyRobbed(TreeNode* root, bool isParentRobbed){
    // base case: if root doesn't exist then return 0
    if(root == nullptr) return 0;

    // if answer is already computed then return computed answer
    if(isParentRobbed && mpTrue.find(root) != mpTrue.end()){
        return mpTrue[root];
    }

    if (!isParentRobbed && mpFalse.find(root) != mpFalse.end()) {
        return mpFalse[root];
    }

    // recursive case: recursively find maximum robber amount for left and right subtree
    // two cases: either parent node is robbed or not robbed

    // case1: if parent is not robbed
    if(!isParentRobbed){
        int leave = maxMoneyRobbed(root->left, false) + maxMoneyRobbed(root->right, false);
        int take = root->val + maxMoneyRobbed(root->left, true) + maxMoneyRobbed(root->right, true);

        // calculate maximum robbed amount in 'ans'
        int ans = max(leave, take);
        // store answer 'ans' into map
        mpFalse[root] = ans;
        return ans;
    }else{
        // otherwise parent is robbed
        int leave = maxMoneyRobbed(root->left, false) + maxMoneyRobbed(root->right, false);
        int ans = leave;
        // store answer 'ans' into map
        mpTrue[root] = ans;
        return ans;
    }
}

int rob(TreeNode* root) {
    mpTrue.clear();
    mpFalse.clear();
    return maxMoneyRobbed(root, false);
}

int main(){
    BinaryTree bt;
    // vector<int> arr = {3, 2, 3, -1, 3, -1, 1};
    
    vector<int> arr = {3, 4, 5, 1, 3, -1, 1};
    bt.initializeTree(arr);
    cout<<"Maximum Amount of money the thief can rob : "<<rob(bt.root)<<endl;
    return 0;
}