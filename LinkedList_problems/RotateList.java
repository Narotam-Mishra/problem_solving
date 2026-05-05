
// Problem link - https://leetcode.com/problems/rotate-list/description/?envType=daily-question&envId=2026-05-05

package LinkedList_problems;

public class RotateList {
    public ListNode rotateRight(ListNode head, int k) {
        // handle edge cases
        if(head == null || head.next == null || k == 0) return head;

        // step 1 - traverse list and find its length
        int n = 1;
        ListNode tail = head;
        while(tail.next != null){
            tail = tail.next;
            n++;
        }

        // step 2 - normalise k and compute the cut index
        k = k % n;

        // if k == 0 then no need to rotate
        if(k == 0) return head;

        // we need the node at index (n-k-1) that will be new tail
        // node right after index (n-k) becomes new head
        int stepsToNewTail = n - k - 1;
        ListNode newTail = head;
        for(int i=0; i<stepsToNewTail; i++){
            newTail = newTail.next;
        }

        // step 3 - relink the cut node
        // node after new tail is new head
        ListNode newHead = newTail.next;

        // form a circular list: old tail connect back to old head
        tail.next = head;

        // cut the cirxular list
        newTail.next = null;

        // step 4 - return new head
        return newHead;
    }
}
