
// Problem link -  https://leetcode.com/problems/middle-of-the-linked-list/

package LinkedList_problems;

class ListNodeUtil{
    int data;
    ListNodeUtil next;

    public ListNodeUtil(int data){
        this.data = data;
        this.next = null;
    }
}

class LinkedListUtil{
    ListNodeUtil head;
    ListNodeUtil tail;

    public LinkedListUtil(){
        this.head = null;
        this.tail = null;
    }

    void addAtTail(int data){
        ListNodeUtil newNode = new ListNodeUtil(data);
        if(this.head == null){
            this.head = newNode;
            this.tail = newNode;
        }else{
            this.tail.next = newNode;
            this.tail = newNode;
        }
    }

    void removeAtHead(){
        if(this.head == null) return;
        ListNodeUtil newHead = this.head.next;
        this.head.next = null;
        this.head = newHead;
        if(this.head == null){
            this.tail = null;
        }
    }

    boolean isEmpty() {
        return this.head == null;
    }

    int getHeadData() {
        return this.head != null ? this.head.data : Integer.MIN_VALUE;
    }

    int getTailData() {
        return this.tail != null ? this.tail.data : Integer.MIN_VALUE;
    }

    void displayLinkedList(ListNodeUtil temp) {
        StringBuilder res = new StringBuilder();
        while (temp != null) {
            res.append(temp.data).append(" -> ");
            temp = temp.next;
        }
        res.append("X");
        System.out.println(res.toString());
    }
}

public class FindMiddleOfLL {
    public static ListNodeUtil middleNode(ListNodeUtil head) {
        ListNodeUtil prev = null;
        ListNodeUtil slow = head;
        ListNodeUtil fast = head;

        // traverse LL and update fast and slow pointers
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        // disconnect the left half of LL from the middle of LL
        if(prev != null){
            prev.next = null;
        }

        // return slow pointer which now points at mid of LL
        return slow;
    }

    public static void main(String[] args) {
        LinkedListUtil ll = new LinkedListUtil();
        int[] arr = {1, 2, 3, 4, 5};

        for (int num : arr) {
            ll.addAtTail(num);
        }

        ListNodeUtil middleNode = middleNode(ll.head);
        // System.out.println("Middle Node Data: " + (middleNode != null ? middleNode.data : "null"));
        
        // Display the entire linked list
        ll.displayLinkedList(middleNode);
    }
}
