
// Problem link - https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/?envType=daily-question&envId=2026-01-07

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

long sum = 0, maxP;

// utility function to find total sum of binary tree
long findTreeSum(TreeNode* root){
    // base case
    if(root == NULL){
        return 0;
    }

    // recursive case
    int leftSubtreeSum = findTreeSum(root->left);
    int rightSubtreeSum = findTreeSum(root->right);
    int totalSum = root->val + leftSubtreeSum + rightSubtreeSum;
    
    return totalSum;
}

// utility function to find subtree sum
int findSubtreeSum(TreeNode* root){
    // base case:
    if(root == NULL) return 0;

    // recursive case
    int leftSum = findSubtreeSum(root->left);
    int rightSum = findSubtreeSum(root->right);
    int subtreeSum = root->val + leftSum + rightSum;

    // find remaining subtree sum
    int remSubtreeSum = sum - subtreeSum;

    // update maximum product
    maxP = max(maxP, (long)subtreeSum * remSubtreeSum);

    // return subtree sum
    return subtreeSum;
}

int maxProduct(TreeNode* root) {
    const int mod = 1e9 + 7;

    // base case:
    if(root == NULL){
        return 0;
    }
    // step 1 - find total sum of tree
    maxP = 0;
    sum = findTreeSum(root);
    
    // step 2 - find two subtrees sum and update maximum product
    findSubtreeSum(root);

    // step 3 - return maximum product
    return maxP % mod;
}

int main(){
    // vector<optional<int>> nums = {1,2,3,4,5,6};

    vector<optional<int>> nums = {1,nullopt,2,3,4,nullopt,nullopt,5,6};
    TreeNode* root = buildTree(nums);
    cout<<maxProduct(root);
    return 0;
}