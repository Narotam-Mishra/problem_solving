
// Problem link - https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

public class SmallestMissingIntegerGreaterThanSequentialPrefixSum {
    // utility method to check for the smallest missing value
    private static boolean containsValue(int[] nums, int target){
        for(int num : nums){
            if(num == target){
                return true;
            }
        }
        return false;
    }

    public static int missingInteger(int[] nums) {
        // step 1 - initialize the sum of the longest sequential prefix
        int prefixSum = nums[0];

        // intialize the expected next value in the sequential prefix
        int expectedSum = nums[0] + 1;

        // step 2 - traverse through the array to find the longest sequential prefix
        for(int i=1; i<nums.length; i++) {
            // if the current number is the expected sequential number
            if(nums[i] == expectedSum) {
                // add to the prefix sum
                prefixSum += nums[i];

                // move to the next expected sequential number
                expectedSum++;
            } else {
                // otherwise break if sequence is broken
                break;
            }
        }

        // step 3 - find the smallest missing number >= prefixSum
        int x = prefixSum;

        // check for the smallest missing value
        while(containsValue(nums, x)) {
            // keep checking until we find a missing number
            x++;
        }

        // step 4 - return the smallest missing number
        return x;
    }

    public static void main(String[] args) {
        // int[] nums = {1, 2, 3, 2, 5};

        int[] nums = {3,4,5,1,12,14,13};
        System.out.println(missingInteger(nums));
    }
}