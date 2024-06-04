
// Problem link - https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

package BinarySearchTree_problems;

class ListNode{
    int data;
    ListNode next;

    public ListNode(int data){
        this.data = data;
        this.next = null;
    }
}

class LinkedListUtil{
    ListNode head;
    ListNode tail;

    public LinkedListUtil(){
        this.head = null;
        this.tail = null;
    }

    void addAtTail(int data){
        ListNode newNode = new ListNode(data);
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
        ListNode newHead = this.head.next;
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
}

public class ConvertSortedLLToBST {
    private static ListNode findMidOfLinkedList(ListNode head){
        ListNode prev = null;
        ListNode slow = head;
        ListNode fast = head;

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

    private static TreeNode buildBSTRec(ListNode head){
        // edge case:
        if(head == null) return null;

        // Find the middle element of LL
        ListNode mid = findMidOfLinkedList(head);

        // middle element of LL should be the root of BST
        TreeNode bstNode = new TreeNode(mid.data);

        // Base case: when there is just one element in the linked list
        if(head == mid) return bstNode;

        // Recursive case: recursively build the left and right subtrees
        bstNode.left = buildBSTRec(head);
        bstNode.right = buildBSTRec(mid.next);

        // return bst node
        return bstNode;
    }

    public static TreeNode sortedListToBST(ListNode head) {
        return buildBSTRec(head);
    }

    public static void main(String[] args) {
        LinkedListUtil ll = new LinkedListUtil();
        int[] arr = {-10, -3, 0, 5, 9};

        for(int num : arr){
            ll.addAtTail(num);
        }

        TreeNode bstRoot = sortedListToBST(ll.head);
        BinarySearchTree bst = new BinarySearchTree();
        bst.root = bstRoot;
        System.out.println(bst.printBST());
    }
}