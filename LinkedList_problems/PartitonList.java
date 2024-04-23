
// Problem link - https://leetcode.com/problems/partition-list/

package LinkedList_problems;

class ListNode{
    int val;
    ListNode next;

    ListNode(int val){
        this.val = val;
        next = null;
    }
}

class LinkedListHelper{
    
    // utility method to create linked list
    public ListNode createLinkedList(int[] arr){
        if(arr.length == 0) return null;
        ListNode head = new ListNode(arr[0]);
        ListNode cur = head;
        for(int i=1; i<arr.length; i++){
            cur.next = new ListNode(arr[i]);
            cur = cur.next;
        }
        return head;
    }

    // utlity method to print linked list
    public void printLinkedList(ListNode head){
        ListNode cur = head;
        StringBuilder res = new StringBuilder();

        // iterate through linked list and print
        while(cur != null){
            res.append(cur.val).append(" -> ");
            cur = cur.next;
        }
        res.append("X");
        System.out.println(res.toString());
    }

    // partition the linked list
    public ListNode partition(ListNode head, int x) {
        // in order to two create partitions, we will use two list nodes
        ListNode l1 = new ListNode(-1);
        ListNode l2 = new ListNode(-1);

        // create two tail nodes to maintain tail of the node
        ListNode t1 = l1;
        ListNode t2 = l2;

        // iterate through the list 
        // pertform partiton of the list
        ListNode cur = head;
        while (cur != null) {
            ListNode temp = cur;
            cur = cur.next;

            // isolate the node
            temp.next = null;

            // as per partiton algo, all values less than 'x' should be on the left of 'x'
            if(temp.val < x){
                t1.next = temp;
                t1 = t1.next;
            }else{
                t2.next = temp;
                t2 = t2.next;
            }
        }

        // attach two partitioned list
        t1.next = l2.next;
        l2.next = null;

        // before returing attached list
        // detach l1 because list l1 is not needed any more
        ListNode res = l1.next;
        l1.next = null;

        // return the single list
        return res;
    }
}

public class PartitonList {
    public static void main(String[] args) {
        int[] arr = {1,4,3,2,5,2};
        int k = 3;

        LinkedListHelper ll = new LinkedListHelper();
        ListNode head = ll.createLinkedList(arr);
        System.out.println("Orignal Linked List:");
        ll.printLinkedList(head);
        ListNode partionedHead = ll.partition(head, k);
        System.out.println("Partitioned Linked List:");
        ll.printLinkedList(partionedHead);
    }
}