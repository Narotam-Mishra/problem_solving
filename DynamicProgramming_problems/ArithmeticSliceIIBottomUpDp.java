
// Problem link - https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

// Approach - using Bottom Up DP

package DynamicProgramming_problems;

import java.util.*;

public class ArithmeticSliceIIBottomUpDp {
    public static long[] arr;
    public static Map<Long, Long>[] dp;

    @SuppressWarnings("unchecked")
    private static int findNumOfArithmeticSlicesIIBottomUpDP(){
        int size = arr.length;

        // Initialize an array of maps to store key value configurations for dynamic programming
        dp = new HashMap[size];
        for(int it=0; it<size; it++){
            dp[it] = new HashMap<>();
        }

        int ans = 0;
        for(int i=1; i<size; i++){
            for(int j=0; j<i; j++){
                // calculate common difference diff
                long diff = arr[i] - arr[j];
                // Check whether the map of index 'j' has difference 'diff' as the key
                if(dp[j].containsKey(diff)){
                    // Increment the answer by the number of arithmetic slices found
                    ans += dp[j].get(diff);
                    if(dp[i].containsKey(diff)){
                        // Update the count of slices for index 'i' and difference 'diff'
                        dp[i].put(diff, 1 + dp[i].get(diff)+dp[j].get(diff));
                    }else{
                        // Initialize the count of slices for index 'i' and difference 'diff'
                        dp[i].put(diff, 1 + dp[j].get(diff));
                    }
                }else{
                    if(dp[i].containsKey(diff)){
                        // Update the count of slices for index 'i' and difference 'diff'
                        dp[i].put(diff, 1 + dp[i].get(diff));
                    }else{
                        // Initialize the count of slices for index 'i' and difference 'diff'
                        dp[i].put(diff, (long) 1);
                    }
                }
            }
        }
        // return ans
        return ans;
    }
    public static int numberOfArithmeticSlices(int[] nums) {
        arr = new long[nums.length];
        for(int i=0; i<nums.length; i++){
            arr[i] = (long)nums[i];
        }
        return findNumOfArithmeticSlicesIIBottomUpDP();
    }

    public static void main(String[] args) {
        int[] nums = {2,4,6,8,10};
        // int[] nums = {7,7,7,7,7};
        System.out.println(numberOfArithmeticSlices(nums));
    }
}