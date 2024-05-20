
// Problem link - https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

// Approach - using DP memoization technique

package DynamicProgramming_problems;

import java.util.Arrays;

public class NumberOfLIS {
    public static int findNumberOfLIS(int[] nums) {
        int size = nums.length;

        // If array is empty or has only one element, return its length
        if(size <= 1) return size;

        // Length of longest increasing subsequence ending at index i
        int[] dp = new int[size];
        Arrays.fill(dp, 1);

        // Count of longest increasing subsequences ending at index i
        int[] count = new int[size];
        Arrays.fill(count, 1);

        // there will be atleast 1 increasing subsequence for each array elements
        int maxLength = 1;

        // using DP technique to calculate LIS lengths in dp and LIS counts in count array
        for(int i=1; i<size; i++){
            for(int prev=0; prev<i; prev++){
                // If nums[i] is greater than nums[prev], we have a potential increasing subsequence
                if(nums[i] > nums[prev]){
                    // and adding current nums[i] makes a longer subsequence, update lengths and counts
                    if(1 + dp[prev] > dp[i]){
                        dp[i] = 1 + dp[prev];
                        // inherit count from previous count
                        count[i] = count[prev];
                    }else if(1 + dp[prev] == dp[i]){
                        // If adding nums[i] maintains the same length, add to existing count
                        count[i] += count[prev];
                    }
                }
            }
            // update LIS max length maxLength
            maxLength = Math.max(maxLength, dp[i]);
        }

        int res = 0;
        // find all indices where LIS's length is equal to maxLength and sum their counts
        for(int i=0; i<size; i++){
            if(dp[i] == maxLength){
                res += count[i];
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {1,3,5,4,7};

        // int[] nums = {2,2,2,2,2};
        System.out.println(findNumberOfLIS(nums));
    }
}
