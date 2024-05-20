
// Problem link - https://leetcode.com/problems/binary-tree-level-order-traversal/

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

    // Function to insert data into the binary tree
    void insertData(int val){
        TreeNode *newNode = new TreeNode(val);
        if(root == nullptr){
            root = newNode;
        }else{
            insertNode(root, newNode);
        }
    }

    // Function to recursively insert a node into the binary tree
    void insertNode(TreeNode *node, TreeNode *newNode){
        if(node->left == nullptr){
            node->left = newNode;
        }else if(node->right == nullptr){
            node->right = newNode;
        }else{
            insertNode(node->left, newNode);
        }
    }

    // Function to perform level order traversal of the binary tree
    vector<vector<int>> levelOrder(TreeNode *root){
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
        return res;
    }
};

int main(){
    BinaryTree bt;
    bt.insertData(1);
    bt.insertData(2);
    bt.insertData(3);
    bt.insertData(4);
    bt.insertData(5);
    bt.insertData(6);
    bt.insertData(7);

    cout << "Reading binary tree data in level order traversal:" << endl;
    vector<vector<int>> result = bt.levelOrder(bt.root);

    for(const auto &level : result){
        for(int val : level){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}