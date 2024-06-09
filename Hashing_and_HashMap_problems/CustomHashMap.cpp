
// Implement your own HashMap using Hashing function

/*

Implementation Approach :-
1). Create structure that should contain array of Linked List
2). use Load factor (lambda), at any point of time if load factor > 0.5 then we rehash

*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string k, int v){
        this->key = k;
        this->value = v;
        this->next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;

    // constructor to intialize the LL's node
    MyLinkedList(){
        head = nullptr;
    }

    // utility method to add LL's node at head
    void addAthead(string key, int value){
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }

    // utility method to delete LL's node from head of LL
    void deleteAtHead(){
        if(head == nullptr) return;
        Node* nodeToDel = head;
        head = head->next;
        delete nodeToDel;
    }
};

class HashMap{

};