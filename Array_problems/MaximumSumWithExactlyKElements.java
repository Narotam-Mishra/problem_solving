
// Problem link - https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/?envType=problem-list-v2&envId=array

package Array_problems;

public class MaximumSumWithExactlyKElements {
    public static int maximizeSum(int[] nums, int k) {
        // store maximum score in `maxScore`
        int maxScore = 0;

        // step 1 - find maximum value in `nums` for maximum score
        int maxNum = -1;
        for (int num : nums) {
            if (num > maxNum) {
                maxNum = num;
            }
        }

        // step 2 - perform operation k-times
        while (k > 0) {
            // increase score
            maxScore += maxNum;

            // add a new element with a value of `maxNum` + 1
            maxNum++;
            k--;
        }

        // step 3 - return maximum score `maxScore`
        return maxScore;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,3,4,5};
        // int k = 3;

        int[] nums = {5,5,5};
        int k = 2;
        System.out.println(maximizeSum(nums, k));
    }
}