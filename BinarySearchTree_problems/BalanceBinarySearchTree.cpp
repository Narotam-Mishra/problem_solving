
// Problem link - https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2026-02-09

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // utility function to build a tree from an array (for testing purposes)
    static TreeNode* buildBST(const vector<int>& arr) {
        if (arr.empty()) return nullptr;
        TreeNode* root = new TreeNode(arr[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (i < arr.size()) {
            TreeNode* current = q.front();
            q.pop();
            if (arr[i] != -1) {
                current->left = new TreeNode(arr[i]);
                q.push(current->left);
            }
            i++;
            if (i < arr.size() && arr[i] != -1) {
                current->right = new TreeNode(arr[i]);
                q.push(current->right);
            }
            i++;
        }
        return root;
    }

    // utility function to convert tree to array
    static vector<int> treeToArray(TreeNode* root) {
        if (!root) return {};
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                result.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            else {
                result.push_back(-1);
            }
        }
        while (result.back() == -1) {
            result.pop_back();
        }
        return result;
    }
};

void performInOrder(TreeNode* root, vector<int>& arr){
    // base case
    if(!root) return;

    // recursive case
    performInOrder(root->left, arr);
    arr.push_back(root->val);
    performInOrder(root->right, arr);
}

TreeNode* solve(int s, int e, vector<int>& arr){
    // base case:
    if(s > e){
        return nullptr;
    }

    // find mid
    int mid = s + (e - s)/2;

    // recursive case: recursively build tree
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = solve(s, mid-1, arr);
    root->right = solve(mid+1, e, arr);

    // return root
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> arr;
    
    // step 1 - perform in order traversal of BST 
    performInOrder(root, arr);

    // step 2 - recursively build balanced BST and return
    int s = 0;
    int e = arr.size() - 1;
    return solve(s, e, arr);
}

int main(){
    // vector<int> nums = {1,-1,2,-1,3,-1,4,-1,-1};

    vector<int> nums = {2,1,3};
    TreeNode* root = TreeNode::buildBST(nums);
    root = balanceBST(root);
    vector<int> output = TreeNode::treeToArray(root);
    for (int val : output) {
        cout << val << " ";
    }
    return 0;
}