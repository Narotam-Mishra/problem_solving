
//Problem link -  https://leetcode.com/problems/maximum-subarray/

// Using kadane's Algorithm

package Array_problems;

public class MaximumSubArraySum {
    private static int maxSubArray(int[] nums) {
        int curSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.length; i++) {

            // find maximum current sum
            curSum = Math.max(nums[i], curSum + nums[i]);

            // update maximum sum
            maxSum = Math.max(maxSum, curSum);
        }
        return maxSum;
    }

    public static void main(String[] args) {
        int[] arr = {-2,1,-3,4,-1,2,1,-5,4};
        System.out.println(maxSubArray(arr));
    }
}