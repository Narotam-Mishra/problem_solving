
// Problem link - https://leetcode.com/problems/rotate-list/description/?envType=daily-question&envId=2026-05-05

#include<bits/stdc++.h>
using namespace std;

class ListNode {
public: 
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    // handle edge cases
    if(!head || !head->next || k == 0) return head;

    // step 1 - traverse list and find its length
    int n = 1;
    ListNode* tail = head;
    while(tail -> next){
        tail = tail -> next;
        n++;
    }

    // step 2 - normalise k and compute the cut index
    k = k % n;

    // if k == 0 then no need to rotate
    if(k == 0) return head;

    // we need the node at index (n-k-1) that will be new tail
    // node right after index (n-k) becomes new head
    int stepsToNewTail = n - k - 1;
    ListNode* newTail = head;
    for(int i=0; i<stepsToNewTail; i++){
        newTail = newTail->next;
    }

    // step 3 - relink the cut node
    // node after new tail is new head
    ListNode* newHead = newTail->next;

    // form a circular list: old tail connect back to old head
    tail->next = head;

    // cut the cirxular list
    newTail->next = nullptr;

    // step 4 - return new head
    return newHead;
}

ListNode* buildList(const vector<int>& values) {
    ListNode dummy;
    ListNode* tail = &dummy;

    for(int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " ";
        head = head->next;
    }
    cout << '\n';
}

void deleteList(ListNode* head) {
    while(head) {
        ListNode* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

int main(){
    vector<int> values = {1,2,3,4,5};
    int k = 2;
    
    ListNode* head = buildList(values);
    ListNode* rotatedHead = rotateRight(head, k);

    printList(rotatedHead);
    deleteList(rotatedHead);

    return 0;
}
