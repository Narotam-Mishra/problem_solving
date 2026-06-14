
// Problem link - https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=daily-question&envId=2026-06-14

#include <bits/stdc++.h>
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

void deleteLinkedList(ListNode* head) {
    while(head != nullptr) {
        ListNode* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

int pairSum1(ListNode* head) {
    // keep track of each LL's element
    vector<int> res;

    // step 1 - iterate on LL and store its element
    ListNode* curr = head;
    while(curr != NULL){
        res.push_back(curr->val);
        curr = curr->next;
    }

    // keep track of maximum twin sum
    int maxSum = 0;

    // step 2 - using two-pointers approach
    int n = res.size();
    int i = 0, j = n-1;
    while(i < j){
        maxSum = max(maxSum, res[i] + res[j]);
        i++;
        j--;
    }

    // step 3 - return maximum twin sum
    return maxSum;
}

int pairSum2(ListNode* head) {
    // using a stack to mirror the linked list values so we can pair
    stack<int> st;

    // step 1 - traverse the list and push every node's value onto the stack.
    ListNode* curr = head;
    while (curr != NULL) {
        st.push(curr->val);
        curr = curr->next;
    }

    // keep track of the maximum twin sum.
    int maxSum = 0;

    // step 2 - now iterate over the first half of the list again. For each node
    int n = st.size();
    curr = head;
    int cnt = 1;
    while (cnt <= n / 2) {
        int partnerVal = st.top();
        st.pop();
        maxSum = max(maxSum, curr->val + partnerVal);
        curr = curr->next;
        cnt++;
    }

    // step 3 - return the maximum twin sum found.
    return maxSum;
}

int pairSum(ListNode* head) {
    // step 1 - find mid of LL
    // using slow and fast pointer
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* mid = slow;

    // step 2 - reverse 2nd half of LL
    ListNode* prev = NULL;
    ListNode* nextNode = NULL;
    while(mid != NULL){
        nextNode = mid->next;
        mid->next = prev;
        prev = mid;
        mid = nextNode;
    }

    // step 3 - find maximum twin sum 
    // by iterating first and second half of LL
    int maxSum = 0;
    ListNode* curr = head;
    while(prev != NULL){
        maxSum = max(maxSum, curr->val + prev->val);
        curr = curr->next;
        prev = prev->next;
    }

    // step 4 - return maximum twin sum
    return maxSum;
}

int main(){
    vector<vector<int>> testCases = {
        {5, 4, 2, 1},
        {4, 2, 2, 3},
        {1, 100000}
    };

    for(int i = 0; i < testCases.size(); i++) {
        ListNode* head = createLinkedList(testCases[i]);

        cout << "Test case " << i + 1 << ": ";
        printLinkedList(head);
        cout << "Maximum twin sum: " << pairSum(head) << endl << endl;

        deleteLinkedList(head);
    }

    return 0;
}
