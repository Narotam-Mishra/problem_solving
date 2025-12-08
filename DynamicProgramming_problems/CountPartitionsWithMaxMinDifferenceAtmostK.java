
// Problem link - https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/

package DynamicProgramming_problems;

import java.util.*;

public class CountPartitionsWithMaxMinDifferenceAtmostK {
    static final int MOD = 1_000_000_007;

    public static int countPartitions(int[] nums, int k) {
        int n = nums.length;

        // create dp and prefixsum array
        int[] dp = new int[n+1];
        int[] pref = new int[n+1];

        dp[0] = 1;
        pref[0] = 1;

        Deque<Integer> minDeq = new ArrayDeque<>();
        Deque<Integer> maxDeq = new ArrayDeque<>();

        // step 1 - using sliding window approach
        int i=0;
        for(int j=0; j<n; j++){
            // maintain max Deque
            while(!maxDeq.isEmpty() && nums[j] > nums[maxDeq.peekLast()]){
                maxDeq.pollLast();
            }
            maxDeq.offerLast(j);

            // maintain min Deque
            while(!minDeq.isEmpty() && nums[j] < nums[minDeq.peekLast()]){
                minDeq.pollLast();
            }
            minDeq.offerLast(j);

            //step 2 - shrink window
            while (i <= j && nums[maxDeq.peekFirst()] - nums[minDeq.peekFirst()] > k) {
                i++;

                if (!maxDeq.isEmpty() && maxDeq.peekFirst() < i)
                    maxDeq.pollFirst();

                if (!minDeq.isEmpty() && minDeq.peekFirst() < i)
                    minDeq.pollFirst();
            }

            // step 3 - fill dp transition
            int left = pref[j];
            int right = (i > 0 ? pref[i - 1] : 0);
            dp[j + 1] = (left - right + MOD) % MOD;

            // step 4 - update prefix sum
            pref[j + 1] = (pref[j] + dp[j + 1]) % MOD;
        }

        // step 5 - return final result
        return dp[n];
    }

    public static void main(String[] args) {
        // int[] nums = {9,4,1,3,7};
        // int k = 4;

        int[] nums = {3,3,4};
        int k = 0;
        System.out.println(countPartitions(nums, k));
    }
}
