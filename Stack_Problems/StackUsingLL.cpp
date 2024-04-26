
// Design Stack using Linked List

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    // Constructor to initialize the node with data
    Node(int val){
        this->data = val;
        this->next = nullptr;
    }
};

// LinkedList class representing the linked list
class MyLinkedList{
public:
    Node* head;

    MyLinkedList(){
        head = nullptr;
    }

    // Method to add a node at the head of the linked list
    void addAtHead(int val){
        Node* newNode = new Node(val);
        if(head != nullptr){
            newNode->next = head;
        }
        head = newNode;
    }

    // Method to delete a node from the head of the linked list
    void deleteAtHead(){
        if(head != nullptr){
            Node* nodeToBeDel = head;
            head = head->next;
            // free memory
            delete nodeToBeDel;
        }
    }
};

// Stack class implementation using LinkedList
class Stack{
private:
    MyLinkedList ll;

public:
    // Constructor to initialize the stack with an empty linked list
    Stack(){}

    // Method to push an element onto the stack
    void push(int element){
        ll.addAtHead(element);
    }

    // Method to pop an element from the stack
    void pop(){
        ll.deleteAtHead();
    }

    // Method to get the top element of the stack
    int top(){
        return ll.head != nullptr ? ll.head->data : -1;
    }

    // Method to check if the stack is empty
    bool isEmpty(){
        return ll.head == nullptr;
    }
};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(40);
    st.push(50);
    st.push(70);
    cout << st.top()<<endl;
    st.pop();
    cout <<st.top()<<endl;
    cout<<st.isEmpty()<<endl;
    return 0;
}