
// Problem link - https://leetcode.com/problems/design-circular-queue/

#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
    vector<int> queue;
    int maxSize;
    int front;
    int rear;
    int count;

public:
    MyCircularQueue(int k) {
        queue.resize(k);
        maxSize = k;
        front = 0;
        // Initialize rear to -1 as the queue is empty initially
        rear = -1;
        count = 0;
    }
    
    bool enQueue(int value) {
        // if queue is full then return false
        if(isFull()) return false;
        // insert element in circular queue (from rear(back))
        rear = (rear + 1) % maxSize;
        queue[rear] = value;
        // increment count
        count++;
        return true;
    }
    
    bool deQueue() {
        // if queue is empty then return false
        if(isEmpty()) return false;
        // delete element from circular queue (from front)
        front = (front + 1) % maxSize;
        // decrement count
        count--;
        return true;
    }
    
    int Front() {
        // befor getting queue's front element check queue is empty or not
        if(isEmpty()) return -1;
        return queue[front];
    }
    
    int Rear() {
        // befor getting queue's rear element check queue is empty or not
        if(isEmpty()) return -1;
        return queue[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == maxSize;
    }
};

int main(){
    MyCircularQueue circularQueue(3); // Initialize a circular queue with size 3
    cout << boolalpha; // Print boolean values as "true" or "false"

    cout << circularQueue.enQueue(1) << endl; // Output: true
    cout << circularQueue.enQueue(2) << endl; // Output: true
    cout << circularQueue.enQueue(3) << endl; // Output: true
    cout << circularQueue.enQueue(4) << endl; // Output: false (queue is full)
    cout << circularQueue.Rear() << endl; // Output: 3
    cout << circularQueue.isFull() << endl; // Output: true
    cout << circularQueue.deQueue() << endl; // Output: true
    cout << circularQueue.enQueue(4) << endl; // Output: true
    cout << circularQueue.Rear() << endl; // Output: 4

    return 0;
}
