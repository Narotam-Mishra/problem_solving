
// Design your own Deque using DLL

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }

    // Method to add a node at the head of the doubly linked list
    void addAtHead(int data){
        if(isEmpty()){
            Node* newNode = new Node(data);
            this->head = newNode;
            this->tail = newNode;
        }else{
            Node* newNode = new Node(data);
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode;
        }
    }

    // Method to add a node at the tail of the doubly linked list
    void addAtTail(int data){
        if(isEmpty()){
            addAtHead(data);
        }else{
            Node* newNode = new Node(data);
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
    }

    // Method to remove a node from the head of the doubly linked list
    void removeAtHead(){
        if(!isEmpty()){
            if(this->head->next == nullptr){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                Node* newHead = this->head->next;
                this->head->next = nullptr;
                newHead->prev = nullptr;
                this->head = newHead;
            }
        }
    }

    // Method to remove a node from the tail of the doubly linked list
    void removeAtTail(){
        if(!isEmpty()){
            if(this->head->next == nullptr){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                Node* newTail = this->tail->prev;
                newTail->next = nullptr;
                this->tail->prev = nullptr;
                this->tail = newTail;
            }
        }
    }

    // Method to check if the doubly linked list is empty
    bool isEmpty(){
        return this->head == nullptr;
    }

    // Utility method to display the doubly linked list data
    void displayDLL(){
        Node* temp = this->head;
        cout<< "From head to tail: ";
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
        cout<<"From tail to head: ";
        temp = this->tail;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

class Deque{
public:
    DoublyLinkedList dll;

    Deque(){
        this->dll = DoublyLinkedList();
    }

    // Method to add an element at the front of the deque
    void addAtFront(int data){
        this->dll.addAtHead(data);
    }

    // Method to add an element at the back of the deque
    void addAtBack(int data) {
        this->dll.addAtTail(data);
    }

    // Method to remove an element from the front of the deque
    void removeAtFront() {
        this->dll.removeAtHead();
    }

    // Method to remove an element from the back of the deque
    void removeAtBack() {
        this->dll.removeAtTail();
    }

    // Method to get the front element of the deque
    int getFront() {
        return this->dll.head != nullptr ? this->dll.head->data : -1;
    }

     // Method to get the back element of the deque
    int getBack() {
        return this->dll.tail != nullptr ? this->dll.tail->data : -1;
    }

    void printDeque(){
        Node* temp = this->dll.head;
        string res = "Deque: ";
        while (temp != nullptr){
            res += to_string(temp->data) + " ";
            temp = temp->next;
        }
        cout<<res<<endl;
    }
};

int main(){
    Deque dq;
    dq.addAtFront(11);
    dq.addAtFront(13);
    dq.addAtFront(19);
    dq.addAtFront(21);
    dq.addAtBack(91);
    dq.addAtBack(87);
    dq.addAtBack(77);
    dq.printDeque();

    cout<<"Front Element: "<<dq.getFront()<<endl;
    cout<<"Rear Element:"<<dq.getBack()<<endl;

    dq.removeAtFront();
    dq.removeAtBack();

    dq.printDeque();

    cout<<"Front Element: "<<dq.getFront()<<endl;
    cout<<"Rear Element: "<<dq.getBack()<<endl;
    return 0;
}