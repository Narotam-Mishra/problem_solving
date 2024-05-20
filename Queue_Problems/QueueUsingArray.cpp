
// Design your own Queue using Array

#include<bits/stdc++.h>
using namespace std;

class Queue{
private:
    int *queue;
    int size;
    int front;
    int back;

public:
    // constructor to initialize queue
    Queue(int len){
        size = len;
        queue = new int[size];
        front = back = 0;
    }

    // Insert element into queue (back)
    void enqueue(int element){
        // Before insertion, check if queue is full
        if(back == size){
            cout << "Queue is full!" << endl;
            return;
        }else{
            // Otherwise insert element from back of queue
            queue[back++] = element;
        }
    }

    // Delete element from queue (front) and return deleted element
    int dequeue(){
        // Check if queue is empty before deletion
        if(front == back){
            cout << "Queue is full!" << endl;
            return -1;
        }else{
            int deleteElement = queue[front];
            // Shift elements towards the front of the queue
            for(int i=0; i<back-1; i++){
                queue[i] = queue[i+1];
            }
            // Reset the last element and decrement back
            queue[--back] = 0;
            return deleteElement;
        }
    }

    // Get front element of the queue
    int getFront(){
        if(front == back){
            cout << "Queue is full!" << endl;
            return -1;
        }
        return queue[front];
    }

    // Get back element of the queue
    int getBack(){
        if(front == back){
            cout << "Queue is full!" << endl;
            return -1;
        }
        return queue[back - 1];
    }

    bool isEmpty(){
        return front == back;
    }

    // Display elements of the queue
    void displayData(){
        if(front == back){
            cout<<"Queue is full!"<<endl;
            return;
        }
        for(int i=front; i<back; i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue q(7);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << "Is Queue empty: " << (q.isEmpty() ? "true" : "false")<<endl;
    cout << "Front: " << q.getFront()<<endl; 
    cout << "Back: " << q.getBack()<<endl; 

    cout << "Queue Elements: ";
    q.displayData();
    cout << "Is Queue empty: "<<(q.isEmpty() ? "true" : "false")<<endl;
    return 0;
}