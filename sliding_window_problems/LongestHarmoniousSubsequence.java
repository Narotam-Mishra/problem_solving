
// Problem link - https://leetcode.com/problems/longest-harmonious-subsequence/description/?envType=problem-list-v2&envId=sliding-window

package sliding_window_problems;

import java.util.*;

public class LongestHarmoniousSubsequence {
    public static int findLHS(int[] nums) {
        // step 1 - count frquencies
        Map<Integer, Integer> count = new HashMap<>();
        for(int num : nums){
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        // step 2 - iterate on each number of `nums`
        int maxLength = 0;
        for(int num : nums){
            // step 3 - check if adjacent pairs exist
            if(count.containsKey(num + 1)){
                // step 4 - calculate length of harmonious subsequence
                int currLen = count.get(num) + count.get(num + 1);

                // step 5 - update maximum length
                maxLength = Math.max(maxLength, currLen);
            }
        }

        // step 6 - return maximun subsequence length `maxLength`
        return maxLength;
    }

    public static void main(String[] args) {
        // int[] nums = {1,3,2,2,5,2,3,7};

        // int[] nums = {1,2,3,4};

        int[] nums = {1,1,1,1};
        System.out.println(findLHS(nums));
    }
}