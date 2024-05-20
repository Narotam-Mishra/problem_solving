
// Problem link - https://leetcode.com/problems/design-linked-list/

#include<bits/stdc++.h>
using namespace std;

class MyLinkedList {

    class ListNode {
    public:
        int data;
        ListNode* next;

        ListNode(int data) {
            this->data = data;
            next = nullptr;
        }
    };

private:
    ListNode* head;

public:
    MyLinkedList() {
        // constructor to initialize an empty linked list
        head = nullptr;
    }

    // Get the value at the specified index
    int get(int index) {
        int i = 0;
        ListNode* cur = head;
        while (i < index && cur != nullptr) {
            i++;
            cur = cur->next;
        }
        if (cur == nullptr) return -1;
        return cur->data;
    }

    void addAtHead(int val) {
        // if head is null, then add node at head
        if (head == nullptr) {
            head = new ListNode(val);
        }
        else {
            ListNode* newNode = new ListNode(val);
            newNode->next = head;
            head = newNode;
        }
    }

    void addAtTail(int val) {
        if (head == nullptr) {
            head = new ListNode(val);
        }
        else {
            ListNode* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            ListNode* newNode = new ListNode(val);
            cur->next = newNode;
        }
    }

    void addAtIndex(int index, int val) {
        // check corner case:
        if (index < 0) return;
        else if (index == 0) {
            addAtHead(val);
            return;
        }
        int i = 0;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (i < index && cur != nullptr) {
            i++;
            prev = cur;
            cur = cur->next;
        }
        // check corner case:
        if (i != index) return;
        ListNode* newNode = new ListNode(val);
        prev->next = newNode;
        newNode->next = cur;
    }

    void deleteAtHead() {
        if (head == nullptr) return;
        ListNode* nextNode = head->next;
        delete head;
        head = nextNode;
    }

    void deleteAtIndex(int index) {
        if (head == nullptr) return;
        else if (index == 0) {
            deleteAtHead();
            return;
        }
        else {
            int i = 0;
            ListNode* prev = nullptr;
            ListNode* nodeToBeDel = head;
            while (i < index && nodeToBeDel != nullptr) {
                prev = nodeToBeDel;
                nodeToBeDel = nodeToBeDel->next;
                i++;
            }
            // corner case
            if (i != index || nodeToBeDel == nullptr) return;
            ListNode* newNext = nodeToBeDel->next;
            delete nodeToBeDel;
            prev->next = newNext;

        }
    }

    // Destructor to release memory
    ~MyLinkedList() {
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
};

int main() {
    MyLinkedList obj;
    obj.addAtHead(1);
    obj.addAtTail(3);
    obj.addAtIndex(1, 2);
    cout << obj.get(1) << endl;
    obj.deleteAtIndex(1);
    cout << obj.get(1) << endl;

    // obj.addAtIndex(0,10);
    // obj.addAtIndex(0,20);
    // obj.addAtIndex(1,30);
    // cout<<obj.get(0)<<endl;
    return 0;
}