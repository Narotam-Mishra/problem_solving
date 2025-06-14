
// Problem link - https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/submissions/1663646395/?envType=problem-list-v2&envId=sliding-window

package sliding_window_problems;

import java.util.Arrays;

public class MinimumDifferenceBetweenHighestAndLowestOfKScores {
    public static int minimumDifference(int[] nums, int k) {
        // store minimum possible difference in `minDiff`
        int minDiff = Integer.MAX_VALUE;

        // step 1 - edge case : if k is 1, difference is always 0
        if (k == 1)
            return 0;

        // step 2 - sort the array so that close values are next to each other
        Arrays.sort(nums);

        // step 3 - iterate on array elements in window of size-k
        for (int i = 0; i <= nums.length - k; i++) {
            // take the current window of size k over the sorted array
            int windowMin = nums[i];
            int windowMax = nums[i + k - 1];

            // step 4 - find difference and update minimum difference
            int diff = windowMax - windowMin;
            minDiff = Math.min(minDiff, diff);
        }

        // step 5 - return the smallest difference found
        return minDiff;
    }

    public static void main(String[] args) {
        // int[] nums = {90};
        // int k = 1;

        int[] nums = {9,4,1,7};
        int k = 2;
        System.out.println(minimumDifference(nums, k));
    }
}