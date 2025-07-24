
// Problem link - https://leetcode.com/problems/special-array-i/?envType=problem-list-v2&envId=array

package Array_problems;

public class SpecialArrayI {
    public static boolean isArraySpecial(int[] nums) {
        int n = nums.length;
        // check edge case
        if (n == 1)
            return true;

        // step 1 - iterate on each adjacent pairs
        for (int i = 1; i < n; i++) {
            // step 2 - if adjacent pair is not odd and even then return false immediately
            if (((nums[i - 1] & 1) == 1) && ((nums[i] & 1) == 1) || ((nums[i - 1] & 1) == 0) && ((nums[i] & 1) == 0)) {
                return false;
            }
        }

        // step 3 - otherwise return true
        return true;
    }

    public static void main(String[] args) {
        // int[] nums = {1};

        // int[] nums = {2,1,4};

        // int[] nums = {4,3,1,6};

        int[] nums = {2,10};
        System.out.println(isArraySpecial(nums));
    }
}
