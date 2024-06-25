
//Problem link - https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // utility function to build a tree from an array (for testing purposes)
    static TreeNode* buildTree(const vector<int>& arr) {
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

void traverseBST(TreeNode* node, int& sum) {
    if (!node) return;

    // Traverse the right subtree
    traverseBST(node->right, sum);

    // Update the sum and the node's value
    sum += node->val;
    node->val = sum;

    // Traverse the left subtree
    traverseBST(node->left, sum);
}

TreeNode* bstToGst(TreeNode* root) {
    int sum = 0;
    traverseBST(root, sum);
    return root;
}

int main(){
    vector<int> input = {4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8};
    TreeNode* root = TreeNode::buildTree(input);
    root = bstToGst(root);
    vector<int> output = TreeNode::treeToArray(root);
    for (int val : output) {
        cout << val << " ";
    }
    return 0;
}