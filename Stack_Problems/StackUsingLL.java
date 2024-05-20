
// Design Stack using Linked List

package Stack_Problems;

// define node of LL
class Node{
    int data;
    Node next;

    // constructor to initialize the node with data
    public Node(int data){
        this.data = data;
        this.next = null;
    }
}

class MyLinkedListUtils{
    Node head;

    // Method to add a node at the head of the linked list
    void addAtHead(int val){
        Node newNode = new Node(val);
        if(head != null){
            newNode.next = head;
        }
        head = newNode;
    }

    // Method to delete a node from the head of the linked list
    void deleteAthead(){
        if(head != null){
            Node nodeToBeDel = head;
            head = head.next;
            nodeToBeDel.next = null;
        }
    }
}

class CustomStack{
    private MyLinkedListUtils ll;

    // constructor to initialize the stack with an empty linked list
    public CustomStack(){
        ll = new MyLinkedListUtils();
    }

    // Method to push an element onto the stack
    void push(int element){
        ll.addAtHead(element);
    }

    // Method to pop an element from the stack
    void pop(){
        ll.deleteAthead();
    }

    // Method to get the top element of the stack
    public int top(){
        return ll.head != null ? ll.head.data : -1;
    }

    // Method to check if the stack is empty
    boolean isEmpty(){
        return ll.head == null;
    }
}

public class StackUsingLL {
    public static void main(String[] args) {
        CustomStack st = new CustomStack();
        st.push(10);
        st.push(20);
        st.push(40);
        st.push(50);
        st.push(70);
        System.out.println(st.top());
        st.pop();
        System.out.println(st.top());
        System.out.println(st.isEmpty());
    }
}