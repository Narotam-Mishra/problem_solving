
// Problem link - https://leetcode.com/problems/sliding-window-maximum/description/

package Queue_Problems;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class SlidingWindowMaximum {
    public static int[] maxSlidingWindow(int[] nums, int k) {
        if(nums == null && k <= 0) return new int[0];
        int[] res = new int[nums.length - k + 1];
        Deque<Integer> dq = new ArrayDeque<>();

        // prepare window for n elements
        for(int i=0; i<nums.length; i++){
            // remove elements from the deque that are smaller than the current element
            while (!dq.isEmpty() && nums[i] >= nums[dq.peekLast()]) {
                dq.pollLast();
            }

            // remove indices outside the window k
            while (!dq.isEmpty() && dq.peek() < i-k+1) {
                dq.poll();
            }

            // Add the current index to the deque
            dq.offer(i);

            // add required maximum window element fromt deque into result array res
            if(i >= k-1){
                res[i-k+1] = nums[dq.peek()];
            }
        }
        return res;
    }
    public static void main(String[] args) {
        int[] nums = {1,3,-1,-3,5,3,6,7};
        int k = 3;

        // int[] nums = {1,-1};
        // int k = 1;
        int[] ans = maxSlidingWindow(nums, k);
        System.out.println(Arrays.toString(ans));
    }
}
