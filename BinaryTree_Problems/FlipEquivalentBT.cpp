
// Problem link - https://leetcode.com/problems/flip-equivalent-binary-trees/

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
};

bool isFlipEquivalentBTRec(TreeNode* root1, TreeNode* root2) {
    // base case1: if both roots are null, then return true
    if (root1 == nullptr && root2 == nullptr) return true;

    // base case2: if either of the root is null then return false
    else if (root1 == nullptr || root2 == nullptr) return false;

    // base case3: if root's val are not equal then return false
    else if (root1->val != root2->val) return false;
    
    // recursive case: recursively check for left and right subtree
    else {
        return ((isFlipEquivalentBTRec(root1->left, root2->left) &&
            isFlipEquivalentBTRec(root1->right, root2->right)) ||
            (isFlipEquivalentBTRec(root1->left, root2->right) &&
                isFlipEquivalentBTRec(root1->right, root2->left)));
    }
}

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    return isFlipEquivalentBTRec(root1, root2);
}

int main(){
    BinaryTree bt1;
    vector<int> arr1 = {1,2,3,4,5,6,-1,-1,-1,7,8};
    bt1.buildTreeNodeUtil(arr1);

    BinaryTree bt2;
    vector<int> arr2 = {1,3,2,-1,6,4,5,-1,-1,-1,-1,8,7};
    bt2.buildTreeNodeUtil(arr2);
    if(flipEquiv(bt1.root, bt2.root)){
        cout <<"Is Binary Tree Flip Equivalent : "<<"true"<<endl;
    }else{
        cout <<"Is Binary Tree Flip Equivalent : "<<"false"<<endl;
    }
    return 0;
}