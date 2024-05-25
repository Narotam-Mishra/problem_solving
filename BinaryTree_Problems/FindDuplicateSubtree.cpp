
// Problem link - https://leetcode.com/problems/find-duplicate-subtrees/description/

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

    // utility method to convert binary tree to array
    vector<int> treeToArray(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (node) {
                result.push_back(node->val);
                queue.push(node->left);
                queue.push(node->right);
            } else {
                result.push_back(-1); // Use -1 to represent null
            }
        }
        while (result.back() == -1) {
            result.pop_back();
        }
        return result;
    }

    vector<vector<int>> convertTreesToArrays(const vector<TreeNode*>& trees) {
        vector<vector<int>> result;
        for (TreeNode* tree : trees) {
            result.push_back(treeToArray(tree));
        }
        return result;
    }

    void print2DVector(vector<vector<int>>& output) {
        for (const auto& subtree : output) {
            cout << "[";
            for (size_t i = 0; i < subtree.size(); ++i) {
                if (subtree[i] == -1) cout << "null";
                else cout << subtree[i];
                if (i < subtree.size() - 1) cout << ",";
            }
            cout << "] ";
        }
        cout << endl;
    }

    string serializeBT(TreeNode* node, unordered_map<string, int>& nodeMp, vector<TreeNode*>& res){
        // base case: if tree node has no child then return '#' to indicate null
        if(node == nullptr) return "#";

        // recursive case: recursively traverse left and right subtrees
        string lst = serializeBT(node->left, nodeMp, res);
        string rst = serializeBT(node->right, nodeMp, res);

        // arrange node's value
        string str = "" + to_string(node->val) + "," + lst + "," + rst;

        // maitain node's value entry in map 'nodeMap'
        nodeMp[str]++;

        // if there is a duplicate of node's val then store its root into result list 'res'
        if(nodeMp[str] == 2){
            res.push_back(node);
        }

        // return arrange node's value in string 'str'
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> map;
        vector<TreeNode*> result;
        serializeBT(root, map, result);
        return result;
    }
};

int main(){
    BinaryTree bt;
    vector<int> arr = {1,2,3,4,-1,2,4,-1,-1,4};
    bt.initializeTree(arr);
    vector<TreeNode*> duplicates = bt.findDuplicateSubtrees(bt.root);
    vector<vector<int>> res = bt.convertTreesToArrays(duplicates);
    bt.print2DVector(res);
    return 0;
}