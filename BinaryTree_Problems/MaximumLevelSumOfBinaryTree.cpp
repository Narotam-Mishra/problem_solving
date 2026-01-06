
// Problem link - https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/?envType=daily-question&envId=2026-01-06

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(vector<optional<int>>& arr) {
    if(arr.empty() || !arr[0]) return nullptr;

    TreeNode* root = new TreeNode(arr[0].value());
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if(i < arr.size() && arr[i]) {
            curr->left = new TreeNode(arr[i].value());
            q.push(curr->left);
        }
        i++;

        if(i < arr.size() && arr[i]) {
            curr->right = new TreeNode(arr[i].value());
            q.push(curr->right);
        }
        i++;
    }
    return root;
}


int maxLevelSum(TreeNode* root) {
    // keep track of level sum and level
    int maxSum = INT_MIN;
    int resLevel = 0;
    
    // step 1 - perform BFS traversal
    queue<TreeNode*> qu;
    qu.push(root);

    // keep track of current level
    int currLevel = 1;
    while(!qu.empty()){
        int currSum = 0;
        int n = qu.size();

        // step 2 - traverse all elements of current level
        while(n--){
            TreeNode* curr = qu.front();
            qu.pop();

            // step 3 - calculate sum of each level
            currSum += curr->val;

            // step 4 - store left and right child if exist
            if(curr->left){
                qu.push(curr->left);
            }

            if(curr->right){
                qu.push(curr->right);
            }
        }

        // step 5 - update maximum sum and level
        if(currSum > maxSum){
            maxSum = currSum;
            resLevel = currLevel;
        }

        // move to next level
        currLevel++;
    }

    // step 6 - return final result, from `resLevel`
    return resLevel;
}


int main(){
    // vector<optional<int>> nums = {1,7,0,7,-8,nullopt,nullopt};

    vector<optional<int>> nums = {989,nullopt,10250,98693,-89388,nullopt,nullopt,nullopt,-32127};
    TreeNode* root = buildTree(nums);
    cout<<maxLevelSum(root);
    return 0;
}