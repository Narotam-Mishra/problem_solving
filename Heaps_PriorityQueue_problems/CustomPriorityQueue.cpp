
// Implement your own Priority Queue

#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    
    class Node{
    public:
        string value;
        int priority;

        Node(string value, int priority){
            this->value = value;
            this->priority = priority;
        }
    };

    // using vector to implement PriorityQueue
    vector<Node> heap;

    // helper methods to get parent and children indices
    int getParentIndex(int index) {
        return (index - 1) / 2;
    }

    int getLeftChildIndex(int index) {
        return 2 * index + 1;
    }

    int getRightChildIndex(int index) {
        return 2 * index + 2;
    }

    // utility bubbleUp() method to maintain priority queue property
    void bubbleUp() {
        int index = heap.size() - 1;
        while (index > 0) {
            int parentIdx = getParentIndex(index);
            if (heap[index].priority >= heap[parentIdx].priority) {
                break;
            }

            // swapping
            swap(heap[index], heap[parentIdx]);
            index = parentIdx;
        }
    }

    // utility bubbleDown() method to maintain priority queue property
    void bubbleDown() {
        int index = 0;
        while (true) {
            int lcIdx = getLeftChildIndex(index);
            int rchIdx = getRightChildIndex(index);
            int smallestIdx = index;

            if (lcIdx < heap.size() && heap[lcIdx].priority < heap[smallestIdx].priority) {
                smallestIdx = lcIdx;
            }
            if (rchIdx < heap.size() && heap[rchIdx].priority < heap[smallestIdx].priority) {
                smallestIdx = rchIdx;
            }
            if (smallestIdx == index) {
                break;
            }

            // swapping
            swap(heap[index], heap[smallestIdx]);
            index = smallestIdx;
        }
    }

public:
    // utility method to insert into priority queue
    void enqueue(string value, int priority){
        heap.emplace_back(value, priority);
        bubbleUp();
    }

    // utility method to remove element from priority queue
    string dequeue(){
        if(heap.empty()){
            throw out_of_range("Priority queue is empty");
        }

        string rootValue = heap[0].value;
        heap[0] = heap.back();
        heap.pop_back();

        if(!heap.empty()){
            bubbleDown();
        }

        return rootValue;
    }

    //utility method check if the priority queue is empty
    bool isEmpty(){
        return heap.empty();
    }

    //utility method to get peek at the element with the highest priority without removing it
    string peek() {
        if(heap.empty()){
            throw out_of_range("Priority queue is empty");
        }
        return heap[0].value;
    }
};

// using PriorityQueue class

int main(){
    PriorityQueue pq;
    pq.enqueue("task1", 1);
    pq.enqueue("task2", 2);
    pq.enqueue("task3", 0);
    pq.enqueue("task5", 4);
    pq.enqueue("task4", 3);

    cout<<pq.dequeue()<<endl; // task3
    cout<<pq.dequeue()<<endl; // task1
    cout<<pq.dequeue()<<endl; // task2
    cout<<pq.dequeue()<<endl; // task4
    return 0;
}