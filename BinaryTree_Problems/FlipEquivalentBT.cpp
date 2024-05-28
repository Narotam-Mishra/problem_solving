
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
    bt1.initializeTree(arr1);

    BinaryTree bt2;
    vector<int> arr2 = {1,3,2,-1,6,4,5,-1,-1,-1,-1,8,7};
    bt2.initializeTree(arr2);
    cout <<"Is Binary Tree Flip Equivalent : "<<flipEquiv(bt1.root, bt2.root)<<endl;
    return 0;
}