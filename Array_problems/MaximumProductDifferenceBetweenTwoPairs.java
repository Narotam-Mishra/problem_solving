
// Problem link - https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.Arrays;

public class MaximumProductDifferenceBetweenTwoPairs {
    public static int maxProductDifference1(int[] nums) {
        // get length of `nums` array
        int n = nums.length;

        // step 1 - sort `nums` array in ascending order
        Arrays.sort(nums);

        // step 2 - get first two minimum numbers from `nums`
        int minNum1 = nums[0];
        int minNum2 = nums[1];

        // step 3 - get first two maximum numbers from `nums`
        int maxNum1 = nums[n - 1];
        int maxNum2 = nums[n - 2];

        // step 4 - find and return maximum product difference `maxProdDiff`
        int maxProdDiff = (maxNum1 * maxNum2) - (minNum1 * minNum2);
        return maxProdDiff;
    }

    public static int maxProductDifference(int[] nums) {
        // find maximum and minimum numbers
        int maxNum1 = Integer.MIN_VALUE, maxNum2 = Integer.MIN_VALUE;
        int minNum1 = Integer.MAX_VALUE, minNum2 = Integer.MAX_VALUE;

        // step 1 - find the two largest and two smallest numbers in one pass
        for(int num : nums){
            // update largest numbers
            if(num > maxNum1){
                maxNum2 = maxNum1;
                maxNum1 = num;
            }else if(num > maxNum2){
                maxNum2 = num;
            }

            // update smallest numbers
            if(num < minNum1){
                minNum2 = minNum1;
                minNum1 = num;
            }else if(num < minNum2){
                minNum2 = num;
            }
        }

        // step 2: calculate and return the maximum product difference
        return (maxNum1 * maxNum2) - (minNum1 * minNum2);
    }

    public static void main(String[] args) {
        // int[] nums = {5,6,2,7,4};

        int[] nums = {4,2,5,9,7,4,8};
        System.out.println(maxProductDifference(nums));
    }
}