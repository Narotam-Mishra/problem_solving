
// Problem link - https://leetcode.com/problems/minimum-removals-to-balance-array/description/?envType=daily-question&envId=2026-02-06

package sliding_window_problems;

import java.util.*;

public class MinimumRemovalsToBalanceArray {
    public static int minRemoval(int[] nums, int k) {
        int n = nums.length;

        // step 1 - sort nums array
        Arrays.sort(nums);

        // keep track of maximum and minimum in nums
        int i=0, j=0;
        int maxNum = nums[0], minNum = nums[0];

        // keep track of maximum balanced subarray
        // initially there will be atleast 1 balance subarray
        int len = 1;

        // step 2 - move throught he window
        while(j < n){
            maxNum = nums[j];
            minNum = nums[i];

            // step 3 - check balance subarray condition
            while(i < j && maxNum > (long)k * minNum){
                i++;
                minNum = nums[i];
            }

            // step 4 - updated balanced subarry length
            len = Math.max(len, j-i+1);

            // move to next window
            j++;
        }

        // step 5 - return minimum number of elements to remove
        return n - len;
    }

    public static void main(String[] args) {
        // int[] nums = {2,1,5};
        // int k = 2;

        // int[] nums = {1,6,2,9};
        // int k = 3;

        int[] nums = {4,6};
        int k = 2;
        System.out.println(minRemoval(nums, k));
    }
}
