
// Design your own Queue using Linked List

#include<iostream>
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
};

// Queue class
class Queue{

};

int main(){
    return 0;
}