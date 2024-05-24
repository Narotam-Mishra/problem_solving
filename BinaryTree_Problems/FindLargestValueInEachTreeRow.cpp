
// Problem link - https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

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

    void printOneDVector(vector<int>& result) {
        cout << "[";
        for (size_t i = 0; i < result.size(); ++i) {
            cout<<result[i]<<" ";
            // Only add a comma and space if not the last element
            if (i != result.size() - 1) { 
                cout << ",";
            }
        }
        cout << "]" << endl;
    }

    // find largest value for each level
    vector<int> largestValues(TreeNode* root) {
        // Corner case: if root is null, return an empty vector
        vector<int> res;
        if(root == nullptr) return res;

        // Initialize the queue for level-order traversal
        queue<TreeNode*> q;
        // first we insert root of the tree to the Queue
        q.push(root);

        // Traverse the tree level by level
        while (!q.empty()){
            // get number of nodes at the current level
            int levelSize = q.size();
            // Initialize max value for this level
            int maxVal = INT_MIN;

            // Process all nodes at the current level
            for(int i=0; i<levelSize; i++){
                // get current tree Node from queue
                TreeNode* curr = q.front();
                q.pop();

                // Update the maximum value for the current level
                maxVal = max(maxVal, curr->val);

                // Enqueue left and right children if they exist
                if(curr->left != nullptr) q.push(curr->left);
                if(curr->right != nullptr) q.push(curr->right);
            }

            // After processing of each level, add the max value to the result 'res'
            res.push_back(maxVal);
        }

        // return result 'res'
        return res;
    }
};

int main(){
    BinaryTree bt;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    bt.initializeTree(arr);
    vector<int> res = bt.largestValues(bt.root);
    cout << "Largest Value for each tree row/level: ";
    bt.printOneDVector(res);
    return 0;
}