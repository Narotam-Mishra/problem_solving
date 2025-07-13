
// Problem link - https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.Arrays;

public class MaximumProductOfTwoElementsInArray {
    public static int maxProduct(int[] nums) {
        int n = nums.length;
        // step 1 - sort the `nums` array to get maximum numbers easily
        Arrays.sort(nums);

        // step 2 - get first two maximum numbers from `nums`
        // maximum numbers will be give maximum product
        int maxNum1 = nums[n - 1] - 1;
        int maxNum2 = nums[n - 2] - 1;

        // step 3 - calculate (nums[i]-1)*(nums[j]-1) and return the maximum product
        return (maxNum1 * maxNum2);
    }

    public static void main(String[] args) {
        // int[] nums = {3,4,5,2};

        // int[] nums = {1,5,4,5};

        int[] nums = {3,7};
        System.out.println(maxProduct(nums));
    }
}