
// Problem link - https://leetcode.com/problems/merge-k-sorted-lists/description/

package Heaps_PriorityQueue_problems;

import java.util.*;

class ListNode {
    int val;
    ListNode next;

    public ListNode(int val){
        this.val = val;
    }
}

// custom min-heap 

class MinHeapUtils {
    private List<ListNode> arr = new ArrayList<>();
    private Comparator<ListNode> cmp;

    MinHeapUtils(Comparator<ListNode> cmp) {
        this.cmp = cmp;
    }

    private void upHeapify(int idx) {
        while (idx > 0) {
            int pi = (idx - 1) / 2;
            if (cmp.compare(arr.get(pi), arr.get(idx)) > 0) {
                Collections.swap(arr, pi, idx);
                idx = pi;
            } else {
                break;
            }
        }
    }

    void insert(ListNode data) {
        arr.add(data);
        upHeapify(arr.size() - 1);
    }

    private void downHeapify(int idx) {
        while (idx < arr.size()) {
            int lcIdx = 2 * idx + 1;
            int rcIdx = 2 * idx + 2;
            int minElementIdx = idx;

            if (lcIdx < arr.size() && cmp.compare(arr.get(minElementIdx), arr.get(lcIdx)) > 0) {
                minElementIdx = lcIdx;
            }

            if (rcIdx < arr.size() && cmp.compare(arr.get(minElementIdx), arr.get(rcIdx)) > 0) {
                minElementIdx = rcIdx;
            }

            if (idx == minElementIdx) {
                break;
            } else {
                Collections.swap(arr, idx, minElementIdx);
                idx = minElementIdx;
            }
        }
    }

    void remove() {
        if (arr.isEmpty())
            return;
        Collections.swap(arr, 0, arr.size() - 1);
        arr.remove(arr.size() - 1);
        downHeapify(0);
    }

    ListNode peek() {
        return arr.isEmpty() ? null : arr.get(0);
    }

    int size() {
        return arr.size();
    }
}

public class MergeKSortedLists {

    public static ListNode mergeKLists(ListNode[] lists) {
        // custom comparator for the priority queue
        Comparator<ListNode> cmp = Comparator.comparingInt(n -> n.val);

        // min-heap priority queue
        PriorityQueue<ListNode> pq = new PriorityQueue<>(cmp);

        // insert the head of each list into the priority queue
        for(ListNode list : lists){
            if(list != null){
                pq.add(list);
            }
        }

        // created resultant 'res' linked list
        ListNode res = new ListNode(123);
        // temp points to the resultant 'res' list
        ListNode temp = res;

        // while there are elements in the priority queue
        while(!pq.isEmpty()){
            // get the node with the smallest value
            ListNode minNode = pq.poll();

            // attach current node to the next of resultant 'res' node
            temp.next = minNode;
            temp = temp.next;

            // if the smallest node has a next node, 
            // push it into the priority queue
            if(minNode.next != null){
                pq.add(minNode.next);
            }
        }

        // return the merged list, skipping the dummy head
        return res.next;
    }

    public static ListNode mergeKLists1(ListNode[] lists) {
        // created resultant 'res' linked list
        ListNode res = new ListNode(123);

        // temp points to the resultant 'res' list
        ListNode temp = res;

        // created min-heap of list
        MinHeapUtils hp = new MinHeapUtils((n1, n2) -> n1.val - n2.val);

        // iterate on k-lists
        for(ListNode list : lists){
            if(list != null){
                // will insert only non-empty ll
                // insert each node into heap
                hp.insert(list);
            }
        }

        while(hp.size() > 0){
            // get top node from heap
            ListNode root = hp.peek();

            // attach current node to the next of resultant 'res' node
            temp.next = root;
            temp = temp.next;

            // after storing top node, remove it from heap
            hp.remove();

            // move to next node
            ListNode nextNode = root.next;
            // break the connection
            root.next = null;

            // insert next node into heap
            if(nextNode != null) hp.insert(nextNode);
        }

        // at the end return resultant 'res' list
        return res.next;
    }

    // Helper method to create a linked list from an array
  public static ListNode createLinkedList(int[] arr) {
    ListNode dummy = new ListNode(0);
    ListNode current = dummy;
    for (int val : arr) {
      current.next = new ListNode(val);
      current = current.next;
    }
    return dummy.next;
  }

  // Helper method to print a linked list
  public static void printLinkedList(ListNode node) {
    while (node != null) {
      System.out.print(node.val + " -> ");
      node = node.next;
    }
    System.out.println("null");
  }

    public static void main(String[] args) {
        ListNode[] lists = new ListNode[]{
            createLinkedList(new int[]{1, 4, 5}),
            createLinkedList(new int[]{1, 3, 4}),
            createLinkedList(new int[]{2, 6})
        };

        ListNode result = mergeKLists(lists);
        printLinkedList(result);
    }
}