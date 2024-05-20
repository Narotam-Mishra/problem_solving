
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

// Function to calculate the length of the linked list
int getLinkedListLength(ListNode* head){
    int len = 0;
    ListNode* cur = head;
    while(cur != nullptr){
        len++;
        cur = cur->next;
    }
    return len;
}

// remove nth node from end of linked list
// Approach - 1 (using two pass)
ListNode* removeNthFromEnd1(ListNode* head, int n){
    int len = getLinkedListLength(head);
    int nthNodeIdx = len - n;

    // if the node to be delete is the head
    if(nthNodeIdx == 0){
        // remove head
        ListNode* newHead = head->next;
        head->next = nullptr;
        return newHead;
    }else{
        int i = 0;
        ListNode* prev = nullptr;
        ListNode* nodeToBeDel = head;
        while(i < nthNodeIdx && nodeToBeDel != nullptr){
            prev = nodeToBeDel;
            nodeToBeDel = nodeToBeDel->next;
            i++;
        }

         // If nth node doesn't exist
        if (i != nthNodeIdx) {
            return head;
        }

        // update node reference to remove
        prev->next = nodeToBeDel->next;
        return head;
    }
}

// Approach - 2 (using single pass)
ListNode* removeNthFromEnd(ListNode* head, int n){
    int i = 0;
    ListNode* fast = head;
    while(i < n && fast != nullptr){
        i++;
        fast = fast->next;
    }

    // Edge case: head needs to be removed
    if(fast == nullptr){
        // remove head
        ListNode* newHead = head->next;
        head->next = nullptr;
        return newHead;
    }

    ListNode* slow = head;
    while(fast->next != nullptr){
        // Iterate till the fast doesn't reach the tail node
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* nodeToBeDel = slow->next;
    slow->next = nodeToBeDel->next;
    nodeToBeDel->next = nullptr;
    return head;
}

// utility function to print the linked list
void printLinkedList(ListNode* head){
    ListNode* cur = head;
    while(cur != nullptr){
        cout<< cur->val<<" -> ";
        cur = cur->next;
    }
    cout<<"X"<<endl;
}


int main(){
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original:" << endl;
    printLinkedList(head);

    head = removeNthFromEnd(head, 2);
    cout << "After removing 2nd node from the end:" << endl;
    printLinkedList(head);
    return 0;
}