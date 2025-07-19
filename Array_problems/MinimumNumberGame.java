
// Problem link - https://leetcode.com/problems/minimum-number-game/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.Arrays;

public class MinimumNumberGame {
    public static int[] numberGame(int[] nums) {
        int n = nums.length;
        // store result in `res`
        int[] res = new int[n];

        // step 1 - sort the array to get minimum number easily
        Arrays.sort(nums);

        // step 2 - iterate on `nums` array
        for (int i = 0; i < n; i += 2) {
            // step 3 - get minimum element for Alicer and Bob
            int minAlice = nums[i];
            int minBob = nums[i + 1];

            // step 4 - store minimum element as per given condition
            res[i] = minBob;
            res[i + 1] = minAlice;
        }

        // step 5 - return result `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {5,4,2,3};

        int[] nums = {2,5};
        int[] res = numberGame(nums);
        System.out.println(Arrays.toString(res));
    }
}