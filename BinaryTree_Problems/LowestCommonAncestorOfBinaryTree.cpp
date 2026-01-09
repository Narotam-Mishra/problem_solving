
// Problem link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

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

TreeNode* findNode(TreeNode* root, int value) {
    if (root == nullptr) return nullptr;
    if (root->val == value) return root;

    TreeNode* left = findNode(root->left, value);
    if (left != nullptr) return left;

    return findNode(root->right, value);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // base case: reached end of tree
    if(root == NULL) return NULL;

    // step 1: if current node is p or q, return it 
    if(root == p || root == q){
        return root;
    }

    // step 2 - search in left subtree
    TreeNode* leftSubtree = lowestCommonAncestor(root->left, p, q);

    // step 3 - search in right subtree
    TreeNode* rightSubtree = lowestCommonAncestor(root->right, p, q);

    // step 4 - check if p and q found in different subtrees
    if(leftSubtree != NULL && rightSubtree != NULL){
        // then root will be LCA
        return root;
    }

    // step 5 - otherwise return the non-null subtree result
    return (leftSubtree != NULL) ? leftSubtree : rightSubtree;
}

int main(){
    // vector<optional<int>> nums = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    // TreeNode* root = buildTree(nums);
    // TreeNode* p = findNode(root, 5);
    // TreeNode* q = findNode(root, 4);

    // vector<optional<int>> nums = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};
    // TreeNode* root = buildTree(nums);
    // TreeNode* p = findNode(root, 5);
    // TreeNode* q = findNode(root, 1);

    vector<optional<int>> nums = {1,2};
    TreeNode* root = buildTree(nums);
    TreeNode* p = findNode(root, 1);
    TreeNode* q = findNode(root, 2);

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    // output result
    if (lca != nullptr) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    return 0;
}