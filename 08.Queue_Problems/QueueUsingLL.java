
// Design your own Queue using Linked List

package Queue_Problems;

// Node class
class Node{
    int data;
    Node next;

    Node(int d){
        data = d;
        next = null;
    }
}

// LinkedList class
class LinkedList{
    Node head;
    Node tail;

    public LinkedList(){
        head = null;
        tail = null;
    }

    // Method to add a node at the tail of the LinkedList
    void addAtTail(int data){
        Node newNode = new Node(data);
        // ll is empty
        if(head == null){
            head = tail = newNode;
            return;
        }
        // we are attaching the new node after the prev tail 
        tail.next = newNode;
        // update the tail property
        tail = newNode;
    }

    // Method to remove the head node of the LinkedList
    void removeAtHead(){
        // ll is empty
        if(head == null) return;

        // If LinkedList is not empty
        // Store the new head of the LinkedList
        Node newHead = head.next;

        // disconnect the old head from the LinkedList
        head.next = null;
        
        // allocate the brand new head
        head = newHead;

        // if head becomes null after removal of the node, means ll is empty
        if(head == null){
            // make tail also null
            tail = null;
        } 
    }

    // Method to get the data from the head node of the LinkedList
    int getHeadData(){
        if(head == null) return -1;
        return head.data;
    }

    // Method to get the data from the tail node of the LinkedList
    int getTailData(){
        if(tail == null) return -1;
        return tail.data;
    }

    // Method to check if the LinkedList is empty or not
    boolean isEmpty(){
        return head == null;
    }
}

// Queue class
class CustomQueue{
    LinkedList ll;

    // constructor to initialize the ll
    public CustomQueue(){
        ll = new LinkedList();
    }

    // Method to insert element into queue
    void enqueue(int element){
        ll.addAtTail(element);
    }

    // Method to delete element from queue
    void dequeue(){
        if(ll.isEmpty()) return;
        ll.removeAtHead();
    }

    // Method to check if queue is empty
    boolean isEmpty(){
        return ll.isEmpty();
    }

    // Method to get front element of queue
    int getFront(){
        return ll.getHeadData();
    }

    // Method to get back/rear element of queue
    int getBack(){
        return ll.getTailData();
    }

    // utility method to print queue elements
    void printQueue(){
        Node cur = ll.head;
        while (cur != null) {
            System.out.print(cur.data+" ");
            cur = cur.next;
        }
        System.out.println();
    }
}

public class QueueUsingLL {
    public static void main(String[] args) {
        CustomQueue q = new CustomQueue();

        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);
        q.enqueue(60);
        q.enqueue(70);

        System.out.print("Queue elements: ");
        q.printQueue();
        System.out.println("Front element of queue: " + q.getFront());
        System.out.println("Back element of queue: " + q.getBack());

        q.dequeue();
        q.dequeue();
        q.enqueue(80);

        System.out.println("Queue After insertion/deletion:");
        System.out.println("Front element of queue: " + q.getFront());
        System.out.println("Back element of queue: " + q.getBack());
        System.out.print("Queue elements: ");
        q.printQueue();
    }
}
