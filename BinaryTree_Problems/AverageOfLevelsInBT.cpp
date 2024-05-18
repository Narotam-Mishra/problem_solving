
// Problem link - https://leetcode.com/problems/average-of-levels-in-binary-tree/

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

    // function to calculate average of level in BT
    vector<double> averageOfLevels(TreeNode *root){
        // to store tree's data in result 'res' array
        vector<double> res;
        //corner case: if root is null then return empty array
        if(root == nullptr) return res;

        queue<TreeNode *> qu;
        // first we insert root of the tree to the Queue
        qu.push(root);

        // traverse queue
        while(!qu.empty()){
            int size = qu.size();
            // To calculate each level average we used levelSum and levelCount
            double levelSum = 0;
            int levelCount = 0;

            // iterate level array
            for(int i=0; i<size; i++){
                // get front node from queue
                TreeNode *curr = qu.front();
                qu.pop();

                // Add current node's value to the level sum
                levelSum += curr->val;
                // Increment the level node count
                levelCount++;

                // recursively traverse left and right node of tree for each level
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
            // calculate average 
            double levelAvg = levelSum / levelCount;
            res.push_back(levelAvg);
        }
        return res;
    }
};

int main(){
    BinaryTree bt;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    bt.initializeTree(arr);

    vector<double> result = bt.averageOfLevels(bt.root);
    
    cout <<"Average of each Level in BT:"<< endl;
    // Print the result
    for (double avg : result) {
        cout << avg << " ";
    }
    
    return 0;
}
