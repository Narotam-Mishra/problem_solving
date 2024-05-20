
// Problem link - https://leetcode.com/problems/squares-of-a-sorted-array/description/

// Approch - 1 : Brute Force Approach

package Array_problems;

import java.util.Arrays;

public class SquareSortedArray {
    
    public int[] sortedSquares(int[] nums) {
        for(int i=0; i<nums.length; i++){
            nums[i] = nums[i] * nums[i];
        }
        Arrays.sort(nums);
        return nums;
    }
}
