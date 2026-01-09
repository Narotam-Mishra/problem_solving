
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

// map to store each node value and its depth
unordered_map<int, int>mp;

// keep track of maximum depth
int maxDepth = 0;

void findTreeDepth(TreeNode* root, int d){
    // base case:
    if(root == NULL) return;

    // update maxDepth
    maxDepth = max(maxDepth, d);

    // store depth in map
    mp[root->val] = d;

    // recursive case
    findTreeDepth(root->left, d+1);
    findTreeDepth(root->right, d+1);
}

TreeNode* findLCA(TreeNode* root) {
    // base case
    if (root == NULL || mp[root->val] == maxDepth) {
        return root;
    }

    // search in left subtree
    TreeNode* leftSubtree = findLCA(root->left);

    // search in right subtree
    TreeNode* rightSubtree = findLCA(root->right);

    // check if p and q found in different subtrees
    if (leftSubtree != NULL && rightSubtree != NULL) {
        // then root will be LCA
        return root;
    }

    // otherwise return the non-null subtree result
    return (leftSubtree != NULL) ? leftSubtree : rightSubtree;
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    // step 1 - find maximum depth and populate map
    findTreeDepth(root, 0);

    // step 2 - now find LCA of nodes having maximum depth
    return findLCA(root);
}

// utility function to print subtree in level-order [2,7,4]
void printSubtree(TreeNode* root) {
    if (!root) {
        cout << "[]";
        return;
    }

    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        res.push_back(curr->val);

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }

    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i + 1 < res.size()) cout << ",";
    }
    cout << "]";
}


int main(){
    // vector<optional<int>> nums = {3,5,1,6,2,0,8,nullopt,nullopt,7,4};

    // vector<optional<int>> nums = {1};

    vector<optional<int>> nums = {0,1,3,nullopt,2};
    TreeNode* root = buildTree(nums);
    TreeNode* res = subtreeWithAllDeepest(root);
    printSubtree(res);
    return 0;
}