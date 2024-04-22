
// Problem link - https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

package LinkedList_problems;

class ListNode{
    int val;
    ListNode next;
    ListNode(int x){
        val = x;
    }
}

class CustomLinkedList{
    public ListNode deleteDuplicates(ListNode head) {
        ListNode cur = head;
        while (cur != null && cur.next != null) {
            if(cur.val == cur.next.val){
                ListNode nodeToBeDel = cur.next;
                cur.next = nodeToBeDel.next;
                nodeToBeDel.next = null;
            }else{
                cur = cur.next;
            }
        }
        return head;
    }

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

    public void printLinkedList(ListNode head){
        ListNode cur = head;
        while (cur != null) {
            System.out.print(cur.val+" -> ");
            cur = cur.next;
        }
        System.out.println("X");
    }
}

public class RemoveDuplicatesFromSortedList {
    public static void main(String[] args) {
        int[][] llTc = {
            {1, 1, 2},
            {1, 1, 2, 3, 3},
            {1, 2, 3, 3, 4, 5},
            {1, 2, 3},
            {}
        };

        CustomLinkedList ll = new CustomLinkedList();
        for(int[] tc: llTc){
            ListNode head = ll.createLinkedList(tc);
            System.out.println("Original:");
            ll.printLinkedList(head);
            System.out.println("After deleting duplicates:");
            ListNode res = ll.deleteDuplicates(head);
            ll.printLinkedList(res);
            System.out.println("-----------------------");
        }
    }
}