
// Design your own Queue using Array

package Queue_Problems;

class Queue{
    private int[] queue;
    private int size;
    private int front;
    private int back;

    // constructor for initialization
    public Queue(int len){
        size = len;
        queue = new int[size];
        front = back = 0;
    }

    // Insert element into queue (back)
    public void enqueue(int element){
        // Before insertion, check if queue is full
        if(size == back){
            System.out.println("Queue is full!");
            return;
        }else{
            // Otherwise insert element from back of queue
            queue[back++] = element;
        }
    }

    // Delete element from queue (front) and return deleted element
    public int dequeue(){
        // Check if queue is empty before deletion
        if(front == back){
            System.out.println("Queue is full!");
            return -1;
        }else{
            int deletedElement = queue[front];
            // Shift elements towards the front of the queue
            for(int i=0; i<back-1; i++){
                queue[i] = queue[i+1];
            }
            // Reset the last element and decrement back
            queue[--back] = 0;
            return deletedElement;
        }
    }

    // Get front element of the queue
    public int getFront(){
        // Check if queue is empty before getting front element
        if (front == back) {
            System.out.println("Queue is empty!");
            return -1; // Or throw an exception
        }
        return queue[front];
    }

    // Get back element of the queue
    public int getBack(){
        // Check if queue is empty before getting back element
        if (front == back) {
            System.out.println("Queue is empty!");
            return -1; // Or throw an exception
        }
        return queue[back-1];
    }

    // Display elements of the queue
    public void displayData(){
        if (front == back) {
            System.out.println("Queue is empty!");
            return;
        }

        for(int i=front; i<back; i++){
            System.out.print(queue[i] + " ");
        }
        System.out.println();
    }

    // Check if queue is empty or not
    public boolean isEmpty(){
        return front == back;
    }
}

public class QueueUsingArray {
    public static void main(String[] args) {
        Queue q = new Queue(7);

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

        System.out.println("Is Queue empty: " + (q.isEmpty()));
        System.out.println("Front: " + q.getFront()); 
        System.out.println("Back: " + q.getBack());  

        System.out.print("Queue Elements: ");
        q.displayData();
        System.out.println("Is Queue empty: " + (q.isEmpty()));
    }
}
