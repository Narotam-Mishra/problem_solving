
// Problem link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

package LinkedList_problems;

class ListNode{
    int val;
    ListNode next;
    ListNode(int x){
        val = x;
        next = null;
    }
}

class LinkedListUtility{
    // method to calculate the length of the linked list
    public int getLinkedListLength(ListNode head){
        int len = 0;
        ListNode cur = head;
        while (cur != null) {
            len++;
            cur = cur.next;
        }
        return len;
    }

    // Approach - 1(using two pass)
    public ListNode removeNthFromEnd1(ListNode head, int n){
        int len = getLinkedListLength(head);
        int nthNodeIdx = len - n;

        // if the node to be delete is the head
        if(nthNodeIdx == 0){
            // remove head
            ListNode newHead = head.next;
            head.next = null;
            return newHead;
        }

        int i=0;
        ListNode prev = null;
        ListNode nodeToBeDel = head;
        while(i < nthNodeIdx && nodeToBeDel.next != null){
            prev = nodeToBeDel;
            nodeToBeDel = nodeToBeDel.next;
            i++;
        }

        // if nth node doesn't exist
        if(i != nthNodeIdx){
            return head;
        }

        // update node refernce to remove
        prev.next = nodeToBeDel.next;
        return head;
    }

    public ListNode removeNthFromEnd(ListNode head, int n){
        int i = 0;
        ListNode fast = head;
        while(i < n && fast != null){
            i++;
            fast = fast.next;
        }

        // Edge case: head needs to be removed
        if(fast == null){
            // remove head
            ListNode newHead = head.next;
            head.next = null;
            return newHead;
        }

        ListNode slow = head;
        while(fast.next != null){
            // Iterate till the fast doesn't reach the tail node
            fast = fast.next;
            slow = slow.next;
        }

        ListNode nodeToBeDel = slow.next;
        slow.next = nodeToBeDel.next;
        nodeToBeDel.next = null;
        return head;
    }

    // utility method to print linked list
    public void printLinkedList(ListNode head){
        ListNode cur = head;
        while(cur != null){
            System.out.print(cur.val + " -> ");
            cur = cur.next;
        }
        System.out.println("X");
    }
}

public class RemoveNthNodeFromLast {
    public static void main(String[] args) {
        // Create a sample linked list
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        System.out.println("Original Linked List:");
        LinkedListUtility ll = new LinkedListUtility();
        ll.printLinkedList(head);

        ll.removeNthFromEnd(head, 2);
        System.out.println("After removing 2nd node from the end:");
        ll.printLinkedList(head);
    }
}
