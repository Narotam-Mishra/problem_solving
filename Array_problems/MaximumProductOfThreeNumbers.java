
// Problem link - https://leetcode.com/problems/maximum-product-of-three-numbers/?envType=problem-list-v2&envId=array

/*
Two possible scenarios for maximum product:
1. Three largest positive numbers: nums[n-1] * nums[n-2] * nums[n-3]
2. Two smallest negative numbers * largest positive: nums[0] * nums[1] * nums[n-1]
(since negative * negative = positive, and we want the largest positive result)
*/

package Array_problems;

import java.util.Arrays;

public class MaximumProductOfThreeNumbers {
    public static int maximumProduct(int[] nums) {
        int n = nums.length;

        // step1 - sort `nums` array
        Arrays.sort(nums);

        // step 2 - calculate maximum product of three maximum positive numbers
        long prod1 = nums[n - 1] * nums[n - 2] * nums[n - 3];

        // step 3 - calculate maximum product of two smallest negative numbers and a
        // largest positive number
        long prod2 = nums[0] * nums[1] * nums[n - 1];

        // step 4 - return the maximum product
        return (int) Math.max(prod1, prod2);
    }

    public static void main(String[] args) {
        int[] nums = {1,2,3};

        // int[] nums = {1,2,3,4};
        
        // int[] nums = {-1,-2,-3};
        System.out.println(maximumProduct(nums));
    }
}
