
// Problem link - https://leetcode.com/problems/maximum-width-of-binary-tree/

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

class PairNode{
public:
    TreeNode* treeNode;
    unsigned long long index;
    PairNode(TreeNode* treeNode, unsigned long long index){
        this->treeNode = treeNode;
        this->index = index;
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

    // function to find maximum width of BT
    int widthOfBinaryTree(TreeNode* root) {
        // edge case: if root is null then return 0
        if(root == nullptr) return 0;

        // 'maxWidth' to store maximum width of BT
        unsigned long long maxWidth = 0;
        // create queue to store tree node and perform level order traversal
        queue<PairNode*> q;
        // Store the node and its index
        q.push(new PairNode(root, 0));

        // traverse queue until it is empty
        while(!q.empty()){
            int size = q.size();
            // get the index of the first node in this level
            unsigned long long leftIdx = q.front()->index;
            // initialize rightIdx to leftIdx
            unsigned long long rightIdx = leftIdx;

            // iterate through each node of a level
            for(int i=0; i<size; i++){
                PairNode* curr = q.front();
                q.pop();
                rightIdx = curr->index;

                // push left and right child of tree (if exist) into queue
                if(curr->treeNode->left != nullptr){
                    q.push(new PairNode(curr->treeNode->left, 2 * curr->index + 1));
                }

                if(curr->treeNode->right != nullptr){
                    q.push(new PairNode(curr->treeNode->right, 2 * curr->index + 2));
                }
            }
            // calculate max width for each level
            maxWidth = max(maxWidth, rightIdx - leftIdx + 1);
        }
        // return maximum width
        return maxWidth;
    }
};

int main(){
    BinaryTree bt;
    // vector<int> arr = {1, 3, 2, 5, 3, -1, 9};
    vector<int> arr = {1, 3, 2, 5, -1, -1, 9, 6, -1, 7};
    bt.initializeTree(arr);
    cout <<"Maximum Width of Binary Tree: "<<bt.widthOfBinaryTree(bt.root)<<endl;
    return 0;
}