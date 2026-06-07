
// Problem link - https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2026-06-07

#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    // step 1 - store every value with its TreeNode pointer.
    unordered_map<int, TreeNode*> mp;

    // keep track all child nodes.
    unordered_set<int> childSet;

    // step 2 - read each description and connect parent to child.
    for (auto& des : descriptions) {
        int parent = des[0];
        int child = des[1];
        int isLeft = des[2];

        // create parent node if it is not already present.
        if (mp.find(parent) == mp.end()) {
            mp[parent] = new TreeNode(parent);
        }

        // create child node if it is not already present.
        if (mp.find(child) == mp.end()) {
            mp[child] = new TreeNode(child);
        }

        // attach child to the correct side of parent.
        if (isLeft) {
            mp[parent]->left = mp[child];
        }
        else {
            mp[parent]->right = mp[child];
        }

        childSet.insert(child);
    }

    // step 3 - find the root.
    // any parent that is not present in childSet must be the root.
    for (auto& des : descriptions) {
        int parent = des[0];

        if (childSet.find(parent) == childSet.end()) {
            // step 4 - return root of the tree
            return mp[parent];
        }
    }

    return NULL;
}

vector<int> getLevelOrderVector(TreeNode* root){
    vector<int> result;

    if(root == NULL){
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    // step 4 - traverse tree level by level and store values in a vector.
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        result.push_back(curr->val);

        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }
    }

    return result;
}

void printVector(vector<int>& arr){
    cout << "[";

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i];

        if(i != arr.size() - 1){
            cout << ",";
        }
    }

    cout << "]";
}

void deleteTree(TreeNode* root){
    if(root == NULL){
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(){
    vector<vector<int>> descriptions = {
        {20, 15, 1},
        {20, 17, 0},
        {50, 20, 1},
        {50, 80, 0},
        {80, 19, 1}
    };

    TreeNode* root = createBinaryTree(descriptions);
    vector<int> result = getLevelOrderVector(root);

    cout << "Output: ";
    printVector(result);

    deleteTree(root);

    return 0;
}
