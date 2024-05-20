
// Problem link - https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int val){
        this->val = val;
        left = right = nullptr;
    }
};

class BinaryTree{
public:
    TreeNode *root;

    // constructor to initialize the root
    BinaryTree(){
        root = nullptr;
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

    // Function to perform level order traversal of the binary tree
    vector<vector<int>> levelOrderBottom(TreeNode *root){
        // to store tree's data in result 'res' array
        vector<vector<int>> res;
        //corner case: if root is null then return empty array
        if(root == nullptr) return res;

        queue<TreeNode *> qu;
        // first we insert root of the tree to the Queue
        qu.push(root);

        // traverse queue
        while(!qu.empty()){
            int size = qu.size();
            // to store each level data we used levelArr
            vector<int> levelArr;
            // iterate level array
            for(int i=0; i<size; i++){
                // get front node from queue
                TreeNode *curr = qu.front();
                qu.pop();
                // store first node's data (val) into level array 'levelArr' 
                levelArr.push_back(curr->val);
                // recursively traverse left and right node of tree for each level
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
            res.push_back(levelArr);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    BinaryTree bt;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    bt.initializeTree(arr);

    cout << "Reading binary tree data in level order traversal in reverse order:" << endl;
    vector<vector<int>> result = bt.levelOrderBottom(bt.root);

    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]"<<endl;

    return 0;
}