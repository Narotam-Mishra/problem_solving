
// Implement Doubly Linked List

package LinkedList_problems;

class Node{
    int data;
    Node next, prev;

    public Node(int data){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList {
    Node head;

    // Method to add node at the beginning of DLL
    void addAtHead(int data){
        if(head == null){
            head = new Node(data);
        }else{
            Node newNode = new Node(data);
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
    }

    // method to add node at the end of DLL
    void addAtTail(int data){
        if(head == null){
            addAtHead(data);
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        Node newNode = new Node(data);
        temp.next = newNode;
        newNode.prev = temp;
    }

    // method to add node at the middle of DLL
    void addAtMiddle(int data){
        if(head == null){
            addAtHead(data);
            return;
        }
        Node fast = head;
        Node slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        Node newNode = new Node(data);
        Node nextNode = slow.next;
        if(nextNode != null){
            nextNode.prev = newNode;
        }
        newNode.next = nextNode;
        slow.next = newNode;
        newNode.prev = slow;
    }

    // method to remove node from the head of DLL
    void removeAtHead(){
        if(head == null) return;
        if(head.next == null){
            head = null;
            return;
        }
        Node nextNode = head.next;
        nextNode.prev = null;
        head.next = null;
        head = nextNode;
    }

    // method to remove node from the tail of DLL
    void removeAtTail(){
        if(head == null) return;
        if(head.next == null){
            head = null;
            return;
        }
        Node temp = head;
        while (temp.next.next != null) {
            temp = temp.next;
        }
        temp.next.prev = null;
        temp.next = null;
    }

    // method to remove node from the middle of DLL
    void removeAtMiddle(){
        if(head == null) return;
        Node fast = head;
        Node slow = head;
        Node prev = null;
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            prev= slow;
            slow = slow.next;
        }
        prev.next = slow.next;
        if(slow.next != null){
            slow.next.prev = prev;
        }
    }

    // method to display the elements of DLL
    void display(){
        Node temp = head;
        StringBuilder str = new StringBuilder("X <-> ");
        while (temp != null) {
            str.append(temp.data).append(" <-> ");
            temp = temp.next;
        }
        str.append("X");
        System.out.println(str);
    }
}

public class DesignDoublyLinkedList {
    public static void main(String[] args) {
        DoublyLinkedList dll = new DoublyLinkedList();
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
    }
}




