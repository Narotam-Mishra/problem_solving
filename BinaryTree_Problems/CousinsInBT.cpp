
// Problem link - https://leetcode.com/problems/cousins-in-binary-tree/description/

/*
===> Two nodes of a binary tree are cousins if they have the same depth with different parents.
===> In other words, we can say that two nodes of a binary tree are cousins if they are on same level(depth) and they have different parent.
*/

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
        if(index < arr.size()){
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

    bool isCousins(TreeNode* root, int x, int y) {
        if(root == nullptr) return false;

        // using queue
        queue<TreeNode*> q;
        // push current node into queue
        q.push(root);

        // intially both nodes are at level are -1
        int l1 = -1, l2 = -1;
        // to maintain parent node for x and y
        TreeNode *parentX = nullptr, *parentY = nullptr;
        // calculate level (depth)
        int depth = 0;

        // traverse queue till it is empty
        while (!q.empty()){
            int size = q.size();

            while(size > 0){
                TreeNode* curr = q.front();
                q.pop();

                // if left subtree of current node exist
                if(curr->left != nullptr){
                    q.push(curr->left);
                    if(curr->left->val == x){
                        l1 = depth + 1;
                        parentX = curr;
                    }
                    if(curr->left->val == y){
                        l2 = depth + 1;
                        parentY = curr;
                    }
                }

                // if right subtree of current node exist
                if(curr->right != nullptr){
                    q.push(curr->right);
                    if(curr->right->val == x){
                        l1 = depth + 1;
                        parentX = curr;
                    }
                    if(curr->right->val == y){
                        l2 = depth + 1;
                        parentY = curr;
                    }
                }
                size--;
            }
            // after each level incrent the depth
            depth++;

            if(l1 != -1 && l2 != -1){
                // it means we get level (depth) for both nodes elements x & y
                // level may be equal or unequal
                break;
            }
        }
        return (l1 == l2) && (parentX != parentY);
    }
};

int main(){
    BinaryTree bt;
    vector<int> arr = {1,2,3,-1,4,-1,5};
    int x = 5, y = 4;
    bt.initializeTree(arr);
    cout << "Are both nodes cousin:";
    if(bt.isCousins(bt.root, x, y)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}