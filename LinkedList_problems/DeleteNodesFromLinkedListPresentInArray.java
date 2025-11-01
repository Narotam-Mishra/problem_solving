
// Problem link - https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2025-11-01

package LinkedList_problems;

import java.util.*;

public class DeleteNodesFromLinkedListPresentInArray {
    static class ListNode{
        int val;
        ListNode next;

        ListNode() {}

        ListNode(int val){
            this.val = val;
        }

        ListNode(int val, ListNode next){
            this.val = val;
            this.next = next;
        }

        public static ListNode createList(int[] arr) {
            if (arr.length == 0)
                return null;

            ListNode head = new ListNode(arr[0]);
            ListNode curr = head;

            for (int i = 1; i < arr.length; i++) {
                curr.next = new ListNode(arr[i]);
                curr = curr.next;
            }

            return head;
        }

        // helper method to print linked list
        public static void printList(ListNode head) {
            ListNode curr = head;
            while (curr != null) {
                System.out.print(curr.val);
                if (curr.next != null)
                    System.out.print(" -> ");
                curr = curr.next;
            }
            System.out.println();
        }

        public static ListNode modifiedList(int[] nums, ListNode head) {
            Set<Integer> set = new HashSet<>();
            for(int num : nums){
                set.add(num);
            }

            // step 1 - handle head deletion
            while(head != null && set.contains(head.val)){
                head = head.next;
            }

            // step 2 - handle deletion of intermediate nodes
            if(head == null) return null;

            ListNode curr = head;
            while(curr != null && curr.next != null){
                if(set.contains(curr.next.val)){
                    curr.next = curr.next.next;
                }else{
                    curr = curr.next;
                }
            }
            return head;
        }
    }

    public static void main(String[] args) {
        System.out.println("Test Case 1:");
        // int[] nums1 = {1, 2, 3};
        // int[] listValues1 = {1, 2, 3, 4, 5};

        // int[] nums1 = {1};
        // int[] listValues1 = {1, 2, 1, 2, 1, 2};

        int[] nums1 = {5};
        int[] listValues1 = {1, 2, 3, 4};
        ListNode head1 = ListNode.createList(listValues1);
        System.out.print("Original list: ");
        ListNode.printList(head1);
        head1 = ListNode.modifiedList(nums1, head1);
        System.out.print("Modified list: ");
        ListNode.printList(head1);
    }
}
