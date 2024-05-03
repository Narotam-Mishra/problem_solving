
// Design Deque using Linked List

package Queue_Problems;

class Node{
    int element;
    Node next;

    public Node(int element){
        this.element = element;
        this.next = null;
    }
}

class CustomDeque{
    Node front;
    Node rear;
    int size;

    public CustomDeque(){
        front = null;
        rear = null;
        size = 0;
    }

    // add element to the front of deque
    void addAtFront(int element){
        Node newNode = new Node(element);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        }else{
            newNode.next = front;
            front = newNode;
        }
        size++;
    }

    // adds element to the end of the deque
    void addAtBack(int element){
        Node newNode = new Node(element);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        }else{
            rear.next = newNode;
            rear = newNode;
        }
        size++;
    }

    int removeAtFrontSide(){
        if(isEmpty()) return -1;
        Node nodeToBeDel = front;
        front = front.next;
        if(front == null){
            // If the deque becomes empty after removal
            rear = null;
        }
        size--;
        return nodeToBeDel.element;
    }

    int removeAtBackSide(){
        if(isEmpty()) return -1;
        Node cur = front;
        Node prev = cur;
        while (cur.next != null) {
            prev = cur;
            cur = cur.next;
        }

        Node nodeToBeDel = cur;
        if(prev != null){
            // Update the next pointer of the second-to-last node
            prev.next = null;
            // update rear pointer reference
            rear = prev;
        }else{
            front = null;
            rear = null;
        }
        size--;
        return nodeToBeDel.element;
    }

    int getFront(){
        return front!= null ? front.element : -1;
    }

    int getBack(){
        return rear!= null ? rear.element : -1;
    }

    boolean isEmpty(){
        return size == 0;
    }

    void printDequeUtils(){
        Node cur = front;
        StringBuilder res = new StringBuilder();
        while (cur != null) {
            res.append(cur.element).append(" ");
            cur = cur.next;
        }
        System.out.println(res.toString());
    }
}

public class DequeUsingLL {
    public static void main(String[] args) {
        CustomDeque dq = new CustomDeque();

        dq.addAtFront(1);
        dq.addAtFront(2);
        dq.addAtBack(3);
        dq.addAtBack(4);
        dq.addAtBack(5);
        dq.addAtBack(6);
        dq.addAtFront(7);
        dq.printDequeUtils(); // Output: 7 2 1 3 4 5 6
        System.out.println(dq.removeAtFrontSide()); // Output: 7
        System.out.println(dq.removeAtBackSide()); // Output: 6
        dq.printDequeUtils(); // Output: 2 1 3 4 5
    }
}