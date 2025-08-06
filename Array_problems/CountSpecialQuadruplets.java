
// Problem link - https://leetcode.com/problems/count-special-quadruplets/description/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class CountSpecialQuadruplets {
    public static int countQuadruplets(int[] nums) {
        // get length of `nums` array
        int n = nums.length;

        // step 1 - store quadruplets in `count`
        int count = 0;

        // step 2 - loop over index `c` from `n-2` to 2 (as we need `a < b < c < d`)
        for (int c = n - 2; c >= 2; c--) {
            // map to store frequency of of sum values from the left part (a, b)
            Map<Integer, Integer> map = new HashMap<>();

            // step 3 - now fix d=c+1 and beyound
            for (int d = c + 1; d < n; d++) {
                // step 4 - build frequency map for all positions d > c
                map.put(nums[d], map.getOrDefault(nums[d], 0) + 1);
            }

            // step 5 - iterate on for all valid pairs (a, b) where a < b < c
            for (int a = 0; a < c - 1; a++) {
                for (int b = a + 1; b < c; b++) {
                    // step 6 - find nums[a] + nums[b]
                    int targetSum = nums[a] + nums[b] + nums[c];

                    // step 7 - if this targetSum exists as nums[d] for some d > c
                    if (map.containsKey(targetSum)) {
                        // add the number of such pairs (c, d)
                        count += map.get(targetSum);
                    }
                }
            }
        }

        // step 8 - return count of `quadruplets`
        return count;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,3,6};

        // int[] nums = {3,3,6,4,5};

        int[] nums = {1,1,1,3,5};
        System.out.println(countQuadruplets(nums));
    }
}