
// Design your own Deque using DLL

package Queue_Problems;

class Node {
    int data;
    Node next;
    Node prev;

    public Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedListrunner {
    Node head;
    Node tail;

    public DoublyLinkedListrunner() {
        this.head = null;
        this.tail = null;
    }

    // Method to add a node at the head of the doubly linked list
    public void addAtHead(int data) {
        if (isEmpty()) {
            Node newNode = new Node(data);
            this.head = newNode;
            this.tail = newNode;
        } else {
            Node newNode = new Node(data);
            newNode.next = this.head;
            this.head.prev = newNode;
            this.head = newNode;
        }
    }

    // Method to add a node at the tail of the doubly linked list
    public void addAtTail(int data) {
        if (isEmpty()) {
            addAtHead(data);
        } else {
            Node newNode = new Node(data);
            this.tail.next = newNode;
            newNode.prev = this.tail;
            this.tail = newNode;
        }
    }

    // Method to remove a node from the head of the doubly linked list
    public void removeAtHead() {
        if (!isEmpty()) {
            if (this.head.next == null) {
                this.head = null;
                this.tail = null;
            } else {
                Node newHead = this.head.next;
                this.head.next = null;
                newHead.prev = null;
                this.head = newHead;
            }
        }
    }

    // Method to remove a node from the tail of the doubly linked list
    public void removeAtTail() {
        if (!isEmpty()) {
            if (this.head.next == null) {
                this.head = null;
                this.tail = null;
            } else {
                Node newTail = this.tail.prev;
                newTail.next = null;
                this.tail.prev = null;
                this.tail = newTail;
            }
        }
    }

    // Method to check if the doubly linked list is empty
    public boolean isEmpty() {
        return this.head == null;
    }

    // Utility method to display the doubly linked list data
    public void displayDLLUtils() {
        Node temp = this.head;
        System.out.print("From head to tail: ");
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
        System.out.print("From tail to head: ");
        temp = this.tail;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.prev;
        }
        System.out.println();
    }
}

class DequeRunner {
    DoublyLinkedListrunner dll;

    public DequeRunner() {
        this.dll = new DoublyLinkedListrunner();
    }

    // Method to add an element at the front of the deque
    public void addAtFront(int data) {
        this.dll.addAtHead(data);
    }

    // Method to add an element at the back of the deque
    public void addAtBack(int data) {
        this.dll.addAtTail(data);
    }

    // Method to remove an element from the front of the deque
    public void removeAtFront() {
        this.dll.removeAtHead();
    }

    // Method to remove an element from the back of the deque
    public void removeAtBack() {
        this.dll.removeAtTail();
    }

    // Method to get the front element of the deque
    public int getFront() {
        return this.dll.head != null ? this.dll.head.data : -1;
    }

    // Method to get the back element of the deque
    public int getBack() {
        return this.dll.tail != null ? this.dll.tail.data : -1;
    }

    // Method to print the deque
    public void printDeque(){
        Node temp = this.dll.head;
        StringBuilder res = new StringBuilder();
        while (temp != null) {
            res.append(temp.data).append(" ");
            temp = temp.next;
        }
        System.out.println(res);
    }
}

public class DesignDequeUsingDLL {
    public static void main(String[] args) {
        DequeRunner dq = new DequeRunner();
        dq.addAtFront(11);
        dq.addAtFront(13);
        dq.addAtFront(19);
        dq.addAtFront(21);
        dq.addAtBack(91);
        dq.addAtBack(87);
        dq.addAtBack(77);
        dq.printDeque();

        System.out.println("Front Element: " + dq.getFront());
        System.out.println("Rear Element: " + dq.getBack());

        dq.removeAtFront();
        dq.removeAtBack();

        dq.printDeque();

        System.out.println("Front Element: " + dq.getFront());
        System.out.println("Rear Element: " + dq.getBack());
    }
}