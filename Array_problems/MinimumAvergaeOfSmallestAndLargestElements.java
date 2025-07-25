
// Problem link - https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.Arrays;

public class MinimumAvergaeOfSmallestAndLargestElements {
    public static double minimumAverage(int[] nums) {
        // find length of `nums` array
        int n = nums.length;

        // store minimum average in `minAvg`
        double minAvg = Double.MAX_VALUE;

        // step 1 - sort `nums` for easy iteration using two pointers
        Arrays.sort(nums);

        // step 2 - rpeat operation n/2 times
        int s = 0, e = n - 1;
        while (s < e) {
            // step 3 - calculate current average `currAvg`
            double currAvg = (double)(nums[s] + nums[e]) / 2;

            // step 4 - update minimum average `minAvg`
            minAvg = Math.min(currAvg, minAvg);

            // move start `s` and end `e` pointer
            s++;
            e--;
        }

        // step 5 - return minimum running average
        return minAvg;
    }

    public static void main(String[] args) {
        // int[] nums = {7,8,3,4,15,13,4,1};

        int[] nums = {1,9,8,3,10,5};

        // int[] nums = {1,2,3,7,8,9};
        System.out.println(minimumAverage(nums));
    }
}