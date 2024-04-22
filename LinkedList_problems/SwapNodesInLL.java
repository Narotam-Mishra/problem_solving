
// Problem link - https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

package LinkedList_problems;

class ListNode{
    int val;
    ListNode next;

    ListNode(int x){
        val = x;
    }
}

class LinkedListUtils{
    // method to create a linked list
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

    // utility method to print linked list
    public void printLinkedList(ListNode head){
        StringBuilder res = new StringBuilder();
        ListNode cur = head;

        while(cur != null){
            res.append(cur.val).append(" -> ");
            cur = cur.next;
        }
        res.append("X");
        System.out.println(res.toString());
    }

    public ListNode swapNodes(ListNode head, int k){
        int i = 0;
        ListNode fast = head;
        while (i < k-1 && fast != null) {
            fast = fast.next;
            i++;
        }

        ListNode fNode = fast;

        // edge case: if k is out of bounds
        if(fast == null){
            // remove head
            ListNode newHead = head.next;
            head.next = null;
            return newHead;
        }

        ListNode slow = head;
        while(fast.next != null){
            // Iterate till the fast doesn't reach the tail node
            slow = slow.next;
            fast = fast.next;
        }

        ListNode sNode = slow;

        // logic to swap
        int temp = fNode.val;
        fNode.val = sNode.val;
        sNode.val = temp;

        // return head after swapping
        return head;
    }

    public void runSwapNodesUtils(int[] arr, int k){
        // create linked list
        ListNode head = createLinkedList(arr);

        // Print original linked list
        System.out.println("Original linked list:");
        printLinkedList(head);

        // Run swapNodes function
        head = swapNodes(head, k);

        // Print modified linked list
        System.out.println("After swapping nodes:");
        printLinkedList(head);
    }
}

public class SwapNodesInLL {
    public static void main(String[] args) {
        LinkedListUtils ll = new LinkedListUtils();
        int[] arr = {1, 2, 3, 4, 5};
        int k = 2;
        ll.runSwapNodesUtils(arr, k);
    }
}
