
// Problem link - https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

// utility function to create linked list
ListNode* createLinkedList(vector<int>& arr){
    if(arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;

    for(int i=1; i<arr.size(); i++){
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    cur->next = nullptr;
    return head;
}

// utility function to print linked list
void printLinkedList(ListNode* head){
    ListNode* cur = head;
    while(cur != nullptr){
        cout<< cur->val<<" -> ";
        cur = cur->next;
    }
    cout<<"X"<<endl;
}

// Function to swap kth node from beginning and end in a linked list
ListNode* swapNodes(ListNode* head, int k){
    int i = 0;
    ListNode* fast = head;
    while(i < k-1 && fast != nullptr){
        fast = fast->next;
        i++;
    }
    ListNode* fNode = fast;

    // Edge case: if k is out of bounds
    if(fast == nullptr){
        // remove head
        ListNode* newHead = head->next;
        head->next = nullptr;
        delete head;
        return newHead;
    }
    ListNode* slow = head;
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* sNode = slow;

    // logic to swap node values
    int temp = fNode->val;
    fNode->val = sNode->val;
    sNode->val = temp;

    // return head
    return head;
}

// Function to run the swapNodes function
void runSwapNodes(vector<int>& arr, int k){
    // create linked list
    ListNode* head = createLinkedList(arr);

    // Print original linked list
    cout << "Original linked list:" << endl;
    printLinkedList(head);

    // Run swapNodes function
    head = swapNodes(head, k);

    // Print modified linked list
    cout << "After swapping nodes:" << endl;
    printLinkedList(head);
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    runSwapNodes(arr, k);
    return 0;
}