
// Problem link - https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/?envType=daily-question&envId=2026-01-09

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// utility function to build binary tree
TreeNode* buildTree(vector<optional<int>>& arr) {
    if (arr.empty() || !arr[0]) return nullptr;

    TreeNode* root = new TreeNode(arr[0].value());
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < arr.size() && arr[i]) {
            curr->left = new TreeNode(arr[i].value());
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i]) {
            curr->right = new TreeNode(arr[i].value());
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    
}

int main(){
    vector<optional<int>> nums = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    TreeNode* root = buildTree(nums);
    TreeNode* res = subtreeWithAllDeepest(root);
    return 0;
}