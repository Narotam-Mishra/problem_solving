
// Problem link - https://leetcode.com/problems/design-circular-queue/

package Queue_Problems;

class MyCircularQueue {
    private int[] queue;
    private int maxSize;
    private int front;
    private int rear;
    private int count;

    public MyCircularQueue(int k) {
        this.queue = new int[k];
        this.maxSize = k;
        this.front = 0;
        // Initialize rear to -1 as the queue is empty initially
        this.rear = -1;
        this.count = 0;
    }
    
    public boolean enQueue(int value) {
        // if queue is full then return false
        if(isFull()){
            return false;
        }
        // insert element in circular queue (from rear(back))
        rear = (rear + 1) % maxSize;
        queue[rear] = value;
        // increment count
        count++;
        return true;
    }
    
    public boolean deQueue() {
        // if queue is empty then return false
        if(isEmpty()){
            return false;
        }
        // delete element from circular queue (from front)
        front = (front + 1) % maxSize;
        // decrement count
        count--;
        return true;
    }
    
    public int Front() {
        // befor getting queue's front element check queue is empty or not
        if(isEmpty()) return -1;
        return queue[front];
    }
    
    public int Rear() {
        // befor getting queue's rear element check queue is empty or not
        if(isEmpty()) return -1;
        return queue[rear];
    }
    
    public boolean isEmpty() {
        return count == 0;
    }
    
    public boolean isFull() {
        return count == maxSize;
    }
}


public class DesignCircularQueue {
    public static void main(String[] args) {
        MyCircularQueue cq = new MyCircularQueue(3);
        System.out.println(cq.enQueue(1)); // Output: true
        System.out.println(cq.enQueue(2)); // Output: true
        System.out.println(cq.enQueue(3)); // Output: true
        System.out.println(cq.enQueue(4)); // Output: false (queue is full)
        System.out.println(cq.Rear()); // Output: 3
        System.out.println(cq.isFull()); // Output: true
        System.out.println(cq.deQueue()); // Output: true
        System.out.println(cq.enQueue(4)); // Output: true
        System.out.println(cq.Rear()); // Output: 4
    }
}