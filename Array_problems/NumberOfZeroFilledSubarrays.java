
// PProblem link - https://leetcode.com/problems/number-of-zero-filled-subarrays/description/?envType=daily-question&envId=2025-08-19

package Array_problems;

public class NumberOfZeroFilledSubarrays {
    public static long zeroFilledSubarray(int[] nums) {
        // store total count and consecutive zeros count
        long totalCount = 0;
        int consecutiveZeros = 0;

        // step 1 - traverse through array
        for (int i = 0; i < nums.length; i++) {
            // step 2 - count zero
            if (nums[i] == 0) {
                // each new zero extends all previous subarrays by 1
                consecutiveZeros++;
                totalCount += consecutiveZeros;
            } else {
                // step 3 - reset when we hit a non-zero
                consecutiveZeros = 0;
            }
        }

        // step 4 - return total count `totalCount`
        return totalCount;
    }
    
    public static void main(String[] args) {
        // int[] nums = {1,3,0,0,2,0,0,4};

        int[] nums = {0,0,0,2,0,0};
        System.out.println(zeroFilledSubarray(nums));
    }
}