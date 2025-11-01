
// Problem link - https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2025-11-01

#include<bits/stdc++.h>
using namespace std;

// define LinkedList Node
class ListNode{
public:
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// helper function to create LinkedList from vector
ListNode* createList(vector<int>& arr){
    if(arr.empty()) return nullptr;

    ListNode * head = new ListNode(arr[0]);
    ListNode* curr = head;

    for(int i=1; i<arr.size(); i++){
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// helper function to print linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while(curr != nullptr) {
        cout << curr->val;
        if(curr->next != nullptr) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

// helper function to delete entire list
void deleteList(ListNode* head) {
    while(head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> s(nums.begin(), nums.end());

    // step 1 - handle head deletion
    while(head != NULL && s.find(head->val) != s.end()){
        ListNode* temp = head;
        head = head->next;
    }

    if(head == NULL) return NULL;

    // step 2 - handle deletion of intermediate Node 
    ListNode* curr = head;
    while(curr != NULL && curr->next != NULL){
        if(s.find(curr->next->val) != s.end()){
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
        }else{
            curr = curr->next;
        }
    }

    return head;
}

int main(){
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {1, 2, 3};
    vector<int> listValues1 = {1, 2, 3, 4, 5};

    // cout << "Test Case 2:" << endl;
    // vector<int> nums1 = {1};
    // vector<int> listValues1 = {1, 2, 1, 2, 1, 2};

    // cout << "Test Case 3:" << endl;
    // vector<int> nums1 = {5};
    // vector<int> listValues1 = {1, 2, 3, 4};
    ListNode* head2 = createList(listValues1);
    cout << "Original list: ";
    printList(head2);
    head2 = modifiedList(nums1, head2);
    cout << "Modified list: ";
    printList(head2);
    deleteList(head2);

    return 0;
}