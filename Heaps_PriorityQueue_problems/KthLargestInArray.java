
// Problem link - https://leetcode.com/problems/kth-largest-element-in-an-array/description/

package Heaps_PriorityQueue_problems;

public class KthLargestInArray {
    public static int findKthLargest(int[] nums, int k) {
        // Max Heap
        GenericHeap<Integer> hp = new GenericHeap<>((a, b) -> a - b);

        // insert numbers into max-heap
        for(int num : nums){
            hp.insert(num);
        }

        int kthMax = -1;
        // iterate till k
        while (k > 0) {
            // extract max element from max-Heap top
            kthMax = hp.peek();
            hp.remove();
            k--;
        }
        return kthMax;
    }

    public static void main(String[] args) {
        int[] arr = {3, 2, 1, 5, 6, 4};
        int k = 2;
        System.out.println(findKthLargest(arr, k));
    }
}
