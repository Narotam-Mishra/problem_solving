
// Problem link - https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=daily-question&envId=2026-06-15

#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

ListNode* createLinkedList(vector<int>& values) {
    if(values.empty()) {
        return nullptr;
    }

    ListNode* head = new ListNode(values[0]);
    ListNode* tail = head;

    for(int i = 1; i < values.size(); i++) {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
    }

    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* curr = head;

    while(curr != nullptr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }

    cout << "X" << endl;
}

void deleteLinkedList(ListNode* head){
    ListNode* curr = head;
    while(curr != NULL){
        ListNode* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
}

ListNode* deleteMiddle(ListNode* head) {
    // edge case
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    // step 1 - find mid of LL
    ListNode* slow = head;
    ListNode* fast = head;

    // keep track of previous node just before mid node
    ListNode* prev = NULL;

    // step 2 - iterate of LL
    while(fast != NULL && fast->next != NULL){
        // update slow, fast and prev pointer
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // step 3 - break connection from mid
    prev->next = slow->next;

    // step 4 - delete mid
    delete slow;

    // step 5 - return head
    return head;
}

int main(){
    vector<vector<int>> testCases = {
        {1,3,4,7,1,2,6},
        {1, 2, 3, 4},
        {2,1}
    };

    for(int i = 0; i < testCases.size(); i++) {
        ListNode* head = createLinkedList(testCases[i]);

        cout << "Test case " << i + 1 << ": ";
        printLinkedList(head);
        deleteMiddle(head);
        printLinkedList(head);
        deleteLinkedList(head);
    }
    return 0;
}