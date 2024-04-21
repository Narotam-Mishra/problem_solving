
// Implement Doubly Linked List

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList{
public:
    Node* head;

    DoublyLinkedList(){
        this->head = nullptr;
    }

    // method to add node at the beginning of the DLL
    void addAtHead(int data){
        if(head == nullptr){
            head = new Node(data);
        }else{
            Node* newNode = new Node(data);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
};