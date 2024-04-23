
// Problem link - https://leetcode.com/problems/partition-list/

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

// utility method to create linked list
ListNode* createLinkedList(vector<int>& arr){
    if(arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for(int i=1; i<arr.size(); i++){
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

// utility method to print linked list
void printLinkedList(ListNode* head){
    ListNode* cur = head;
    while(cur != nullptr){
        cout<<cur->val<<" -> ";
        cur = cur->next;
    }
    cout<<"X"<<endl;
}

ListNode* partition(ListNode* head, int x) {
    // in order to two create partitions, we will use two list nodes
    ListNode* l1 = new ListNode(-1);
    ListNode* l2 = new ListNode(-1);

    // create two tail nodes to maintain tail of the node
    ListNode* t1 = l1;
    ListNode* t2 = l2;

    // iterate through the list 
    // pertform partiton of the list
    ListNode* cur = head;
    while (cur != nullptr){
        ListNode* temp = cur;
        cur = cur-> next;

        // isolate node (as we are creating partition)
        temp->next = nullptr;

        // as per partiton algo, all values less than 'x' should be on the left of 'x'
        if(temp->val < x){
            t1->next = temp;
            t1 = t1->next;
        }else{
            t2->next = temp;
            t2 = t2->next;
        }
    }

    // attach two partitioned list
    t1->next = l2->next;
    l2->next = nullptr;

    // before returing attached list
    // detach l1 because list l1 is not needed any more
    ListNode* res = l1->next;
    l1->next = nullptr;

    // return single list
    return res;
}

int main(){
    vector<int> arr = {1,4,3,2,5,2};
    int k = 3;

    ListNode* head = createLinkedList(arr);
    cout<<"Original Linked List:"<<endl;
    printLinkedList(head);
    ListNode* partiitonedHead = partition(head, k);
    cout << "Partitioned Linked List:" << endl;
    printLinkedList(partiitonedHead);
    return 0;
}
