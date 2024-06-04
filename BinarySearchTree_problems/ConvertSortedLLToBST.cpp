
// Problem link - https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    ListNode* head;
    ListNode* tail;

    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void addAtTail(int data) {
        ListNode* newNode = new ListNode(data);
        if (this->head == nullptr) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    bool isEmpty() {
        return this->head == nullptr;
    }
};

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() {
        this->root = nullptr;
    }

    // insert node into BST recursively
    TreeNode* insertNodeIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (root->val > val) {
            root->left = insertNodeIntoBST(root->left, val);
        }
        else {
            root->right = insertNodeIntoBST(root->right, val);
        }
        return root;
    }

    // utility method to build BST
    void buildBST(vector<int>& arr) {
        for (int value : arr) {
            if (value != -1) {
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

    // utility method to delete node from BST recursively
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case: if the tree is empty
        if (root == nullptr) return nullptr;

        // recursively search for the node to be deleted
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // node to be deleted found
            // case 1: node has no children (leaf node)
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            }
            // case 2: node has only one child
            // case 2.1 : only right child exist
            if (root->left == nullptr) {
                return root->right;
            }
            else if (root->right == nullptr) {
                // case 2.2 : only left child exist
                return root->left;
            }

            // case 3: node has two children
            // find the inorder successor (smallest in the right subtree)
            TreeNode* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            // replace node's value with inorder successor's value
            root->val = temp->val;
            // delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }

    // utility method to print BST Nodes
    vector<int> printBST() {
        // corner case:
        vector<int> resList;
        if (this->root == nullptr) return resList;

        // using queue to print BST
        queue<TreeNode*> q;
        q.push(this->root);

        // iterate queue until it is empty
        while (!q.empty()) {
            TreeNode* treeNode = q.front();
            q.pop();
            if (treeNode != nullptr) {
                resList.push_back(treeNode->val);
                q.push(treeNode->left);
                q.push(treeNode->right);
            }
            else {
                resList.push_back(-1);
            }
        }

        // remove trailing NULLs
        while (!resList.empty() && resList.back() == -1) {
            resList.pop_back();
        }

        // return result list
        return resList;
    }

    // utility method to print 1-D Vector
    void printOneDVectorFormat(vector<int>& result) {
        cout << "[";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] << " ";
            // Only add a comma and space if not the last element
            if (i != result.size() - 1) {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
};

ListNode* findMidOfLinkedList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    // traverse LL and update fast and slow pointers
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // disconnect the left half of LL from the middle of LL
    if (prev != nullptr) {
        prev->next = nullptr;
    }

    // return slow pointer which now points at mid of LL
    return slow;
}

TreeNode* buildBSTRec(ListNode* head) {
    // edge case:
    if (head == nullptr) return nullptr;

    // Find the middle element of LL
    ListNode* mid = findMidOfLinkedList(head);

    // middle element of LL should be the root of BST
    TreeNode* bstNode = new TreeNode(mid->data);

    // Base case: when there is just one element in the linked list
    if (head == mid) return bstNode;

    // Recursive case: recursively build the left and right subtrees
    bstNode->left = buildBSTRec(head);
    bstNode->right = buildBSTRec(mid->next);

    // return bst node
    return bstNode;
}

TreeNode* sortedListToBST(ListNode* head) {
    return buildBSTRec(head);
}

int main(){
    LinkedList ll;
    vector<int> arr = {-10, -3, 0, 5, 9};

    for (int i = 0; i<arr.size(); i++) {
        ll.addAtTail(arr[i]);
    }

    TreeNode* bstRoot = sortedListToBST(ll.head);
    BinarySearchTree bst;
    bst.root = bstRoot;

    vector<int> res = bst.printBST();
    bst.printOneDVectorFormat(res);
    return 0;
}