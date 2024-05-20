
// Problem link - https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

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

ListNode* deleteDuplicates(ListNode* head){
    ListNode* cur = head;
    while(cur != nullptr && cur->next != nullptr){
        if(cur->val == cur->next->val){
            ListNode* nodeToBeDel = cur->next;
            cur->next = nodeToBeDel->next;
            delete nodeToBeDel;
        }else{
            cur = cur->next;
        }
    }
    return head;
}

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

void printLinkedList(ListNode* head){
    ListNode* cur = head;
    while(cur != nullptr){
        cout<<cur->val<<" -> ";
        cur = cur->next;
    }
    cout<<"X"<<endl;
}

int main(){
    vector<vector<int>> ll = {
        {1, 1, 2},
        {1, 1, 2, 3, 3},
        {1, 2, 3, 3, 4, 4, 5, 6, 7},
        {1, 1, 3, 5},
        {1, 2, 3},
        {}
    };

    for (auto& lltc : ll) {
        ListNode* head = createLinkedList(lltc);
        cout << "Original:" << endl;
        printLinkedList(head);
        cout << "After deleting duplicates:" << endl;
        ListNode* result = deleteDuplicates(head);
        printLinkedList(result);
        cout << "-----------------------" << endl;
    }
}