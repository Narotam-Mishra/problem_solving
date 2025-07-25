
// Problem link - https://leetcode.com/problems/minimum-positive-sum-subarray/?envType=problem-list-v2&envId=sliding-window

package sliding_window_problems;

import java.util.*;

public class MinimumPositiveSumSubarray {
    public static int minimumSumSubarray(List<Integer> nums, int l, int r) {
        // store minimum positive sum in `minPositiveSum`
        int n = nums.size();
        int minPositiveSum = Integer.MAX_VALUE;

        // step 1 - iterate through all possible subarray lengths from l to r
        for(int len=l; len<=r; len++){
            // step 2 - calculate sum of first window of this length
            int windowSum = 0;
            for(int i=0; i<len; i++){
                windowSum += nums.get(i);
            }

            // check if first window has positive sum
            if(windowSum > 0 && windowSum < minPositiveSum){
                minPositiveSum = windowSum;
            }

            // step 3 - slide window across the array
            for(int start=1; start<=n-len; start++){
                // remove left most element of previous window
                windowSum -= nums.get(start - 1);

                // add the rightmost element of current window
                windowSum += nums.get(start+len-1);

                // check if first window has positive sum
                if(windowSum > 0 && windowSum < minPositiveSum){
                    minPositiveSum = windowSum;
                }
            }
        }

        // step 4 - return -1 if no positive sum found, otherwise return the minimum positive sum
        return minPositiveSum == Integer.MAX_VALUE ? -1 : minPositiveSum;
    }

    public static void main(String[] args) {
        // List<Integer> nums = Arrays.asList(3, -2, 1, 4);
        // int l = 2, r = 3;

        // List<Integer> nums = Arrays.asList(-2, 2, -3, 1);
        // int l = 2, r = 3;

        List<Integer> nums = Arrays.asList(1, 2, 3, 4);
        int l = 2, r = 4;
        System.out.println(minimumSumSubarray(nums, l, r));
    }
}