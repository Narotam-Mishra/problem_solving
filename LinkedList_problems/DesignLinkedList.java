
// Problem link - https://leetcode.com/problems/design-linked-list/

package LinkedList_problems;

public class DesignLinkedList {
    static class ListNode{
        int data;
        ListNode next;

        ListNode(int data){
            this.data = data;
        }
    }

    public static class MyLinkedList {
        static ListNode head;

        // constructor to initialize an empty linked list
        public MyLinkedList(){
            head = null;
        }

        // Get the value at the specified index
        public static int get(int index){
            int i = 0;
            ListNode cur = head;
            while(i < index && cur != null){
                i++;
                cur = cur.next;
            }
            if(cur == null) return -1;
            return cur.data;
        }

        // Add a new node with the given value at the beginning of the list
        public static void addAtHead(int val){
            // if head is null, then add node at head
            if(head == null){
                head = new ListNode(val);
            }else{
                ListNode newNode = new ListNode(val);
                newNode.next = head;
                head = newNode;
            }
        }

        // Add a new node with the given value at the end of the list
        public static void addAtTail(int val){
            if(head == null){
                head = new ListNode(val);
            }else{
                ListNode cur = head;
                while(cur.next != null){
                    cur = cur.next;
                }
                ListNode newNode = new ListNode(val);
                cur.next = newNode;
            }
        }

        // Add a new node with the given value at the specified index
        public static void addAtIndex(int index, int val){
            // check corner case:
            if(head == null && index != 0) return;
            else if(head == null){
                head = new ListNode(val);
                return;
            }
            if(index == 0){
                addAtHead(val);
                return;
            }
            int i = 0;
            ListNode prev = null;
            ListNode cur = head;
            while (i < index && cur != null) {
                i++;
                prev = cur;
                cur = cur.next;
            }
            // check for corner case:
            if(i != index) return;
            ListNode newNode = new ListNode(val);
            prev.next = newNode;
            newNode.next = cur;
        }

        // Delete node at the beginning of the list
        public void deleteAtHead(){
            if(head == null) return;
            ListNode nextNode = head.next;
            head.next = nextNode;
            head = nextNode;
        }

        // Delete the node at the specified index
        public void deleteAtIndex(int index){
            if(head == null) return;
            else if(index == 0){
                deleteAtHead();
                return;
            }else{
                int i = 0;
                ListNode prev = null;
                ListNode nodeToBeDel = head;
                while(i < index && nodeToBeDel != null){
                    prev = nodeToBeDel;
                    nodeToBeDel = nodeToBeDel.next;
                    i++;
                }
                if(i != index || nodeToBeDel == null) return;
                ListNode newNext = nodeToBeDel.next;
                prev.next = newNext;
                nodeToBeDel.next = null;
            }
        }
    }

    public static void main(String[] args) {
        MyLinkedList obj = new MyLinkedList();
        MyLinkedList.addAtHead(1);
        MyLinkedList.addAtTail(3);
        MyLinkedList.addAtIndex(1, 2);
        System.out.println(MyLinkedList.get(1));
        obj.deleteAtIndex(1);
        System.out.println(MyLinkedList.get(1));
    }
}