
// Problem link - https://leetcode.com/problems/jump-game-ix/

package Array_problems;

import java.util.Arrays;

public class JumpGameXI {
    public int[] maxValue(int[] nums) {
        int n = nums.length;

        // res[i] stores the maximum value reachable from index i.
        int[] res = new int[n];

        // maxLeft[i] = maximum value in nums[0...i].
        // minRight[i] = minimum value in nums[i...n-1].
        int[] maxLeft = new int[n];
        int[] minRight = new int[n];

        // initialize boundary values for prefix maximum and suffix minimum.
        maxLeft[0] = nums[0];
        minRight[n - 1] = nums[n - 1];

        // step 1 - build prefix maximum.
        for (int i = 1; i < n; i++) {
            maxLeft[i] = Math.max(nums[i], maxLeft[i - 1]);
        }

        // step 2 - build suffix minimum.
        for (int i = n - 2; i >= 0; i--) {
            minRight[i] = Math.min(nums[i], minRight[i + 1]);
        }

        // step 3 - traverse from right to left and form connected reachable groups.
        // the last index can always reach the maximum value seen on its left side.
        res[n - 1] = maxLeft[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            // case 1 - if every value on the left side is <= every value on the right side,
            // index i cannot connect to the next reachable group. Its answer is
            // only the maximum value within nums[0...i].
            if (maxLeft[i] <= minRight[i + 1]) {
                res[i] = maxLeft[i];
            } else {
                // case 2 - otherwise, both parts are connected through valid jumps, so
                // index i gets the same answer as the group starting at i + 1.
                res[i] = res[i + 1];
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[] nums = { 2, 1, 3 };
        JumpGameXI obj = new JumpGameXI();
        int[] res = obj.maxValue(nums);
        System.out.println(Arrays.toString(res));
    }
}
