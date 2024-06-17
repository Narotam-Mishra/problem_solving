
// Implement your own Priority Queue

package Heaps_PriorityQueue_problems;

import java.util.*;

class PriorityQueueUtils{

    private class Node{
        String value;
        int priority;

        Node(String value, int priority){
            this.value = value;
            this.priority = priority;
        } 
    }

    // using ArrayList to implement PriorityQueue
    private ArrayList<Node> heap;

    public PriorityQueueUtils(){
        heap = new ArrayList<>();
    }

    // helper methods to get parent and children indices
    private int getParentIndex(int idx){
        return (idx - 1) / 2;
    }

    private int getLeftChildIndex(int index) {
        return 2 * index + 1;
    }

    private int getRightChildIndex(int index) {
        return 2 * index + 2;
    }

    // utility bubbleUp() method to maintain priority queue property
    private void bubbleUp() {
        int index = heap.size() - 1;
        while (index > 0) {
            int parentIdx = getParentIndex(index);
            if (heap.get(index).priority >= heap.get(parentIdx).priority) {
                break;
            }
            // swapping
            swap(index, parentIdx);
            index = parentIdx;
        }
    }

    // utility bubbleDown() method to maintain priority queue property
    private void bubbleDown(){
        int index = 0;
        while(true){
            int lcIdx = getLeftChildIndex(index);
            int rcIdx = getRightChildIndex(index);
            int smallestIdx = index;

            if(lcIdx < heap.size() && heap.get(lcIdx).priority < heap.get(smallestIdx).priority){
                smallestIdx = lcIdx;
            }

            if(rcIdx < heap.size() && heap.get(rcIdx).priority < heap.get(smallestIdx).priority){
                smallestIdx = rcIdx;
            }

            if(smallestIdx == index) break;

            // swapping
            swap(index, smallestIdx);
            index = smallestIdx;
        }
    }

    // utility method to swap priority queue's elements
    private void swap(int i, int j){
        Node temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }

    // utility method to insert into priority queue
    public void enqueue(String value, int priority){
        heap.add(new Node(value, priority));
        bubbleUp();
    }

    // utility method to remove element from priority queue
    public String dequeue(){
        if(heap.isEmpty()){
            throw new NoSuchElementException("Priority queue is empty");
        }
        String rootValue = heap.get(0).value;
        Node lastElement = heap.remove(heap.size() - 1);

        if(!heap.isEmpty()){
            heap.set(0, lastElement);
            bubbleDown();
        }
        return rootValue;
    }

    //utility method check if the priority queue is empty
    public boolean isEmpty(){
        return heap.isEmpty();
    }

    //utility method to get peek at the element with the highest priority without removing it
    public String peek(){
        if(heap.isEmpty()){
            throw new NoSuchElementException("Priority queue is empty");
        }
        return heap.get(0).value;
    }
}

public class CustomPriorityQueue {
    public static void main(String[] args) {
        PriorityQueueUtils pq = new PriorityQueueUtils();

        // lower number with highest priority 
        // higher number with lowest priority
        pq.enqueue("task1", 1);
        pq.enqueue("task2", 2);
        pq.enqueue("task3", 0);
        pq.enqueue("task5", 4);
        pq.enqueue("task4", 3);
        
        System.out.println(pq.dequeue()); // task3
        System.out.println(pq.dequeue()); // task1
        System.out.println(pq.dequeue()); // task2
        System.out.println(pq.dequeue()); // task4
    }
}