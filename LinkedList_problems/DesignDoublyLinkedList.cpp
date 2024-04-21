
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

    // function to add node at the beginning of the DLL
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

    // function to add node at the end of the DLL
    void addAtTail(int data){
        if(head == nullptr){
            addAtHead(data);
            return;
        }else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            Node* newNode = new Node(data);
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // function to add node at the middle of the DLL
    void addAtMiddle(int data){
        if(head == nullptr){
            addAtHead(data);
            return;
        }
        Node* fast = head;
        Node* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        Node* newNode = new Node(data);
        Node* nextNode = slow->next;
        if(nextNode != nullptr){
            nextNode->prev = newNode;
        }
        newNode->next = nextNode;
        slow->next = newNode;
        newNode->prev = slow;
    }

    // function to remove node at head of DLL
    void removeAtHead(){
        if(head == nullptr) return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node* nextNode = head->next;
        nextNode->prev = nullptr;
        delete head;
        head = nextNode;
    }

    // function to remove node from tail of DLL
    void removeAtTail(){
        if(head == nullptr) return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // function to remove node from the middle of DLL
    void removeAtMiddle(){
        if(head == nullptr) return;
        Node* fast = head;
        Node* slow = head;
        Node* prev = nullptr;
        
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        if(slow->next != nullptr){
            slow->next->prev = prev;
        }
        delete slow;
    }

    void display(){
        Node* temp = head;
        cout<< "X <-> ";
        while(temp != nullptr){
            cout<< temp->data<<" <-> ";
            temp = temp->next;
        }
        cout<<"X"<<endl;
    }
};

int main(){
    DoublyLinkedList dll;
    dll.addAtHead(10);
    dll.addAtTail(20);
    dll.addAtHead(30);
    dll.addAtTail(40);
    dll.addAtMiddle(15);
    dll.addAtTail(50);
    dll.addAtTail(60);
    dll.addAtHead(71);
    dll.display();
    dll.removeAtHead();
    dll.display();
    dll.removeAtTail();
    dll.display();
    dll.removeAtMiddle();
    dll.display();
    return 0;
}