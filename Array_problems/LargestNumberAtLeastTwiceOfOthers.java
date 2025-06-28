
// Problem link - https://leetcode.com/problems/largest-number-at-least-twice-of-others/?envType=problem-list-v2&envId=array

package Array_problems;

public class LargestNumberAtLeastTwiceOfOthers {
    public static int dominantIndex(int[] nums) {
        // store maximum value and its index from `nums`
        int maxVal = -1, maxId = -1;

        // step 1 - iterate on `nums` find maximum number and its index
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxId = i;
            }
        }

        // step 2 - check given condition while iterating on each number of `nums`
        for (int i = 0; i < nums.length; i++) {
            if (i == maxId)
                continue;

            // step 3 - if the largest element in the array is not at least twice as much as
            // every other number
            // return -1 immdeiately
            if (maxVal < 2 * nums[i]) {
                return -1;
            }
        }

        // step 4 - otherwise return maximum value index `maxId`
        return maxId;
    }

    public static void main(String[] args) {
        // int[] nums = {3,6,1,0};

        int[] nums = {1,2,3,4};
        System.out.println(dominantIndex(nums));
    }
}
