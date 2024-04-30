
// Design your own Queue using Linked List

#include<bits/stdc++.h>
using namespace std;

// Node class
class Node{
public:
    int data;
    Node *next;

    Node(int d){
        data = d;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList{
public:
    Node *head;
    Node *tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    // Method to add a node at the tail of the LinkedList
    void addAtTail(int data){
        Node* newNode = new Node(data);
        // if Linkedlist is empty
        if(!head){
            head = tail = newNode;
            return;
        }

        // attach the newNode after the previous tail
        tail->next = newNode;

        // update the tail property
        tail = newNode;
    }

    // Method to remove the head node of the LinkedList
    void removeAtHead(){
        // If LinkedList is empty
        if(!head) return;

        // Store the new head of the LinkedList
        Node* newHead = head->next;

        // disconnect the old head from the LinkedList
        head->next = nullptr;

        //allocate the new head
        head = newHead;

        // If head becomes null after removal of the node, the LinkedList is empty
        if(!head) tail = nullptr;
    }

    // Method to get the data from the head node of the LinkedList
    int getHeadData(){
        if(!head) return -1;
        return head->data;
    }

    // Method to get the data from the tail node of the LinkedList
    int getTailData(){
        if(!tail) return -1;
        return tail->data;
    }

    // Method to check if the LinkedList is empty or not
    bool isEmpty(){
        return !head;
    }
};

// Queue class
class Queue{
    LinkedList ll;

public:
    // Constructor to initialize the LinkedList
    Queue() {}

    // Method to insert element into queue
    void enqueue(int element){
        ll.addAtTail(element);
    }

    // Method to delete element from queue
    void dequeue(){
        if(ll.isEmpty()) return;
        ll.removeAtHead();
    }

    // Method to check if queue is empty
    bool isEmpty(){
        return ll.isEmpty();
    }

    // Method to get front element of queue
    int getFront(){
        return ll.getHeadData();
    }

    // Method to get back/rear element of queue
    int getBack(){
        return ll.getTailData();
    }

    // Utility method to print queue elements
    void printQueue(){
        Node* cur = ll.head;
        while(cur){
            cout<<cur->data<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
};

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    cout << "Queue elements: ";
    q.printQueue();
    cout << "Front element of queue: " << q.getFront() << endl;
    cout << "Back element of queue: " << q.getBack() << endl;

    q.dequeue();
    q.dequeue();
    q.enqueue(80);

    cout << "Queue After insertion/deletion:" << endl;
    cout << "Front element of queue: " << q.getFront() << endl;
    cout << "Back element of queue: " << q.getBack() << endl;
    cout << "Queue elements: ";
    q.printQueue();
    return 0;
}