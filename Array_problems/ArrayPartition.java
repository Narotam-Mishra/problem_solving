
// Problem link - https://leetcode.com/problems/array-partition/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.Arrays;

public class ArrayPartition {
    public static int arrayPairSum(int[] nums) {
        // store maximum sum of minimums in `maxSum`
        int maxSum = 0;

        // step 1 - sort the array to group similar values together
        // this ensures we pair each number with its closest neighbor
        Arrays.sort(nums);

        // step 2 - iterate of array's number
        // we take elements at even indices (0, 2, 4, ...) because after sorting,
        // these will be the minimum values in each optimal pair
        for(int i=0; i<nums.length; i+=2){
            // step 3 - calculate the sum
            maxSum += nums[i];
        }

        // step 4 - return maximum sum of minimums in `maxSum`
        return maxSum;
    }

    public static void main(String[] args) {
        // int[] nums = {1,4,3,2};

        int[] nums = {6,2,6,5,1,2};
        System.out.println(arrayPairSum(nums));
    }
}