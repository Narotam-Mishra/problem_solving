
// Design Generic Tree (n-Ary Tree)

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int value;
    vector<TreeNode*> children;

    TreeNode(int value) : value(value) {}
};

class GenericTree{
public:
    TreeNode* root;

    GenericTree() : root(nullptr){}

    void insertInTree(int value, int parentValue){
        TreeNode* newNode = new TreeNode(value);
        if(parentValue == 0){
            if(!root){
                root = newNode;
            }else{
                cout<<"Cannot insert root node more than once!"<<endl;
            }
        }else{
            TreeNode* parentNode = findNode(root, parentValue);
            if(parentNode){
                parentNode->children.push_back(newNode);
            }else{
                cout<<"Parent node not found."<<endl;
            }
        }
    }

    TreeNode* findNode(TreeNode* node, int value){
        if(!node) return nullptr;
        if(node->value == value) return node;
        for(TreeNode* child : node->children){
            TreeNode* foundNode = findNode(child, value);
            if(foundNode) return foundNode;
        }
        return nullptr;
    }

    bool searchInTree(int value){
        return searchNode(root, value);
    }

    bool searchNode(TreeNode* node, int value){
        if(!node) return false;
        if(node->value == value) return true;
        for(TreeNode* child : node->children){
            if(searchNode(child, value)) return true;
        }
        return false;
    }
};

int main(){
    GenericTree tree;
    tree.insertInTree(1, 0);
    tree.insertInTree(2, 1);
    tree.insertInTree(3, 1);
    tree.insertInTree(4, 2);
    tree.insertInTree(5, 2);
    tree.insertInTree(6, 3);
    tree.insertInTree(7, 3);
    
    cout<<boolalpha<<tree.searchInTree(5)<<endl;
    cout<<boolalpha<<tree.searchInTree(8)<<endl;
    return 0;
}