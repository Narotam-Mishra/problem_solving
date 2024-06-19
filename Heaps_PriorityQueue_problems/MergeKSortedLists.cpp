
// Problem link - https://leetcode.com/problems/merge-k-sorted-lists/description/

#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(vector<int> arr) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : arr) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "null" << endl;
}

class MinHeapUtils {
public:
    vector<ListNode*> heap;
    function<bool(ListNode*, ListNode*)> cmp;

    MinHeapUtils(function<bool(ListNode*, ListNode*)> comparator) : cmp(comparator) {}

    // Up-heapify to maintain the heap property
    void upHeapify(int idx) {
        while (idx > 0) {
            int parentIdx = (idx - 1) / 2;
            if (!cmp(heap[parentIdx], heap[idx])) {
                swap(heap[parentIdx], heap[idx]);
                idx = parentIdx;
            } else {
                break;
            }
        }
    }

    // Insert node into the heap
    void insert(ListNode* data) {
        heap.push_back(data);
        upHeapify(heap.size() - 1);
    }

    // Down-heapify to maintain the heap property
    void downHeapify(int idx) {
        int size = heap.size();
        while (idx < size) {
            int leftChildIdx = 2 * idx + 1;
            int rightChildIdx = 2 * idx + 2;
            int smallestIdx = idx;

            if (leftChildIdx < size && !cmp(heap[smallestIdx], heap[leftChildIdx])) {
                smallestIdx = leftChildIdx;
            }

            if (rightChildIdx < size && !cmp(heap[smallestIdx], heap[rightChildIdx])) {
                smallestIdx = rightChildIdx;
            }

            if (smallestIdx != idx) {
                swap(heap[idx], heap[smallestIdx]);
                idx = smallestIdx;
            } else {
                break;
            }
        }
    }

    // Remove the top node from the heap
    void remove() {
        if (heap.empty()) return;
        swap(heap[0], heap.back());
        heap.pop_back();
        downHeapify(0);
    }

    // Get the top node of the heap
    ListNode* peek() {
        return heap.empty() ? nullptr : heap[0];
    }

    // Get the size of the heap
    int size() {
        return heap.size();
    }
};

class Comparator {
public:
    bool operator()(ListNode* n1, ListNode* n2){
        return n1->val > n2->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    // min-heap priority queue
    priority_queue<ListNode*, vector<ListNode*>, Comparator> pq;

    // insert the head of each list into the priority queue
    for(auto ll : lists){
        if(ll != nullptr){
            pq.push(ll);
        }
    }

    // create a dummy head for the resultant linked list 'res'
    ListNode* res = new ListNode(123);
    // pointer to build the resultant 'res' list
    ListNode* temp = res;

    // while there are elements in the priority queue
    while(!pq.empty()){
        // get the node with the smallest value
        ListNode* minNode = pq.top();
        pq.pop();

        // append the smallest node to the resultant list 'res'
        temp->next = minNode;
        temp = temp->next;

        // if the smallest node has a next node, 
        // push it into the priority queue
        if(minNode->next != nullptr){
            pq.push(minNode->next);
        }
    }

    // return the merged list, skipping the dummy head
    return res->next;
}

ListNode* mergeKLists1(vector<ListNode*>& lists) {
    // create a dummy head for the resultant linked list
    ListNode* res = new ListNode(123);

    // pointer to build the resultant 'res' list
    ListNode* temp = res;

    // custom min-heap with comparator to sort nodes by value
    auto cmp = [](ListNode* n1, ListNode* n2){
        return n1->val < n2->val;
    };

    // created min-heap of list
    MinHeapUtils hp(cmp);

    // insert all non-empty linked lists into the heap
    for(auto ll : lists){
        if(ll != nullptr){
            hp.insert(ll);
        }
    }

    // merge all nodes into the resultant list 'res'
    while (hp.size() > 0){
        // get the smallest node
        ListNode* root = hp.peek();

        // append the smallest node to the resultant list 'res'
        temp->next = root;
        temp = temp->next;

        // remove the smallest node from the heap
        hp.remove();

        // insert the next node from the extracted list into the heap
        ListNode* nextNode = root->next;

        // break the linked list connection
        root->next = nullptr;
        if(nextNode != nullptr) hp.insert(nextNode);
    }

    // return the merged list, skipping the dummy head
    return res->next;
}

int main(){
    vector<ListNode*> lists = {
        createLinkedList({1, 4, 5}),
        createLinkedList({1, 3, 4}),
        createLinkedList({2, 6})
    };

    ListNode* res = mergeKLists(lists);
    printLinkedList(res);
    return 0;
}