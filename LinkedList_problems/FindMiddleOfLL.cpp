
// Problem link -  https://leetcode.com/problems/middle-of-the-linked-list/

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

    void displayLinkedList(ListNode* head) {
    ListNode* temp = head;
    string res = "";
    while (temp != nullptr) {
        res += to_string(temp->data) + " -> ";
        temp = temp->next;
    }
    res += "X";
    cout << res << endl;
}
};

ListNode* middleNode(ListNode* head) {
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

int main(){
    LinkedList ll;
    vector<int> arr = {1, 2, 3, 4, 5};

    for (int i = 0; i<arr.size(); i++) {
        ll.addAtTail(arr[i]);
    }

    ListNode* mid = middleNode(ll.head);
    ll.displayLinkedList(mid);
    return 0;
}