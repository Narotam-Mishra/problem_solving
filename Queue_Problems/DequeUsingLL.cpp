
// Design Deque using Linked List

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int element;
    Node* next;

    Node(int element) : element(element), next(nullptr) {}
};

class Deque {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Deque() : front(nullptr), rear(nullptr), size(0) {}

    // add element to the front of deque
    void addAtFront(int element) {
        Node* newNode = new Node(element);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        }else{
            newNode->next = front;
            front = newNode;
        }
        size++;
    }

    // adds element to the end of the deque
    void addAtBack(int element){
        Node* newNode = new Node(element);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        }else{
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int removeAtFront(){
        if(isEmpty()) return -1;
        Node* nodeToBeDel = front;
        front = front->next;
        if(front == nullptr){
            // If the deque becomes empty after removal
            rear = nullptr;
        }
        int delElement = nodeToBeDel->element;
        delete nodeToBeDel;
        size--;
        return delElement;
    }

    int removeAtBack(){
        if(isEmpty()) return -1;
        Node* cur = front;
        Node* prev = nullptr;
        while(cur->next != nullptr){
            prev = cur;
            cur = cur->next;
        }
        Node* nodeToBeDel = cur;
        if(prev != nullptr){
            // Update the next pointer of the second-to-last node
            prev->next = nullptr;
            // update rear pointer
            rear = prev;
        }else{
            front = nullptr;
            rear = nullptr;
        }
        int delElement = nodeToBeDel->element;
        delete nodeToBeDel;
        size--;
        return delElement;
    }

    int getFront(){
        return front != nullptr ? front->element : -1;
    }

    int getBack(){
        return rear != nullptr ? rear->element : -1;
    }

    bool isEmpty(){
        return size == 0;
    }

    void printDeque(){
        Node* cur = front;
        while(cur != nullptr){
            cout<<cur->element<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
};

int main(){
    Deque dq;

    dq.addAtFront(1);
    dq.addAtFront(2);
    dq.addAtBack(3);
    dq.addAtBack(4);
    dq.addAtBack(5);
    dq.addAtBack(6);
    dq.addAtFront(7);
    dq.printDeque(); // Output: 7 2 1 3 4 5 6
    cout<<dq.removeAtFront()<<endl; // Output: 7
    cout<<dq.removeAtBack()<<endl; // Output: 6
    dq.printDeque(); // Output: 2 1 3 4 5
    return 0;
}