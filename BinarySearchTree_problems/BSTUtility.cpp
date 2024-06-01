
// BST Utilities methods

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree(){
        this->root = nullptr;
    }

    // insert node into BST recursively
    TreeNode* insertNodeIntoBST(TreeNode* root, int val){
        if(root == nullptr){
            return new TreeNode(val);
        }
        if(root->val > val){
            root->left = insertNodeIntoBST(root->left, val);
        }else{
            root->right = insertNodeIntoBST(root->right, val);
        }
        return root;
    }

    // utility method to build BST
    void buildBST(vector<int>& arr){
        for(int value : arr){
            if(value != -1){
                this->root = insertNodeIntoBST(this->root, value);
            }
        }
    }

    // utility method to search into BST recursively
    TreeNode* serachIntoBSTRec(TreeNode* curr, int val) {
        // base case 1:
        if (curr == nullptr) return nullptr;

        // base case 2:
        if (val == curr->val) return curr;

        // recursive case:
        else if (val < curr->val) {
            return serachIntoBSTRec(curr->left, val);
        }
        return serachIntoBSTRec(curr->right, val);
    }

    // utility method to print BST Nodes
    vector<int> printBST(){
        // corner case:
        vector<int> resList;
        if(this->root == nullptr) return resList;

        // using queue to print BST
        queue<TreeNode*> q;
        q.push(this->root);

        // iterate queue until it is empty
        while (!q.empty()){
            TreeNode* treeNode = q.front();
            q.pop();
            if(treeNode != nullptr){
                resList.push_back(treeNode->val);
                q.push(treeNode->left);
                q.push(treeNode->right);
            }else{
                resList.push_back(-1);
            }
        }
        
        // remove trailing NULLs
        while(!resList.empty() && resList.back() == -1){
            resList.pop_back();
        }

        // return result list
        return resList;
    }

    // utility method to print 1-D Vector
    void printOneDVectorFormat(vector<int>& result) {
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

    void printTwoDVectorFormat(vector<vector<int>>& result) {
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
        cout << "]" << endl;
    }
};

int main(){
    BinarySearchTree bst;
    vector<int> arr = {4, 2, 7, 1, 3};
    bst.buildBST(arr);
    return 0;
}
