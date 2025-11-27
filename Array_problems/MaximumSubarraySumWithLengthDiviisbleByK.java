
// Problem link - https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/?envType=daily-question&envId=2025-11-27

package Array_problems;

import java.util.*;

public class MaximumSubarraySumWithLengthDiviisbleByK {
    public static long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;
        final long INF = Long.MAX_VALUE;

        // find minimum prefix sum for each remainder class
        long[] minPref = new long[k];
        Arrays.fill(minPref, INF);

        // track running prefix sum
        long prefSum = 0;
        long res = Long.MIN_VALUE;

        // prefix sum at index 0 is o
        minPref[0] = 0;

        // step 1 - iterate from 1 to n position to compute prefix sum
        for (int j = 1; j <= n; j++) {
            // find running prefix sum
            prefSum += nums[j - 1];
            int rem = j % k;

            // step 2 - check if we've seen a position with same remainder
            // before
            if (minPref[rem] != INF) {
                // subarray sum = current_prefix -
                // smallest_previous_prefix_with_same_remainder
                res = Math.max(res, prefSum - minPref[rem]);
            }

            // step 3 - update smallest prefix seen so far
            minPref[rem] = Math.min(minPref[rem], prefSum);
        }

        // step 4 - return final result, res
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2};
        // int k = 1;

        // int[] nums = {-1,-2,-3,-4,-5};
        // int k = 4;

        int[] nums = {-5,1,2,-3,4};
        int k = 2;
        System.out.println(maxSubarraySum(nums, k));
    }
}
