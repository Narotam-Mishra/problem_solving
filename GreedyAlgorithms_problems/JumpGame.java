
// Problem link - https://leetcode.com/problems/jump-game/description/

package GreedyAlgorithms_problems;

public class JumpGame {
    public static boolean canJump(int[] nums) {
        // step 1 - track the farthest index that we can reach
        int maxReach = 0;

        for (int i = 0; i < nums.length; i++) {
            // step 2 - if we are struck before reaching this index, return false
            // immediately
            if (i > maxReach)
                return false;

            // step 3 - updated the farthest index reachable
            maxReach = Math.max(maxReach, i + nums[i]);
        }

        // step 4 - if we made it through the loop, we can reach the end
        return true;
    }

    public static void main(String[] args) {
        // int[] nums = {2, 3, 1, 1, 4};

        int[] nums = {3, 2, 1, 0, 4};
        System.out.println(canJump(nums));
    }
}