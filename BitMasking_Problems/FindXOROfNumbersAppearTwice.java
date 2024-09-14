
// Problem link - https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/description/?envType=problem-list-v2&envId=bit-manipulation\

package BitMasking_Problems;

import java.util.Arrays;

public class FindXOROfNumbersAppearTwice {
    public static int duplicateNumbersXOR(int[] nums) {
        // sort the array in non-decreasing order
        Arrays.sort(nums);

        // initialize the XOR result as 0
        int xorRes = 0;

        // traverse through the sorted array and check for duplicates
        for (int i = 1; i < nums.length; i++) {
            // if the current number is the same as the previous one, XOR it with the result
            if (nums[i] == nums[i - 1]) {
                xorRes ^= nums[i];
                // skip the next element as it's already considered a duplicate
                i++;
            }
        }
        return xorRes;
    }

    public static void main(String[] args) {
        // int[] nums = {1, 2, 1, 3};

        int[] nums = {1, 2, 3};
        System.out.println(duplicateNumbersXOR(nums));
    }
}