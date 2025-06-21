
// Problem link - https://leetcode.com/problems/summary-ranges/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class SummaryRanges {
    public static List<String> summaryRanges(int[] nums) {
        // store result in `res` array
        List<String> res = new ArrayList<>();
        int n = nums.length;

        // edge case:
        if (n == 0)
            return res;

        // step 1 - start current range
        int start = nums[0];

        // step 2 - iterate through the array
        for (int i = 1; i < n; i++) {
            // step 3 - if current number is not consecutive
            if (nums[i] != nums[i - 1] + 1) {
                // step 4 - end the current range and add to result
                if (start == nums[i - 1]) {
                    // add single number
                    res.add(String.valueOf(start));
                } else {
                    // add range
                    res.add(start + "->" + nums[i - 1]);
                }

                // step 5 - start new range from current number
                start = nums[i];
            }
        }

        // step 6 - handle last range after loop
        if (start == nums[n - 1]) {
            // add single number
            res.add(String.valueOf(start));
        } else {
            // add range
            res.add(start + "->" + nums[n - 1]);
        }

        // step 7 - return result `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {0,1,2,4,5,7};

        int[] nums = {0,2,3,4,6,8,9};
        List<String> res = summaryRanges(nums);
        System.out.println(res);
    }
}