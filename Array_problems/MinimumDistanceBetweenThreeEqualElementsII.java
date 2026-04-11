
// Problem link - https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/?envType=daily-question&envId=2026-04-11

package Array_problems;

import java.util.*;

public class MinimumDistanceBetweenThreeEqualElementsII {
    public int minimumDistance(int[] nums) {
        int n = nums.length;

        // number -> list of indices
        Map<Integer, List<Integer>> numMap = new HashMap<>();

        int res = Integer.MAX_VALUE;

        // step 1 - iterate through array
        for (int k = 0; k < n; k++) {
            int num = nums[k];

            // initialize list if not present
            numMap.putIfAbsent(num, new ArrayList<>());
            numMap.get(num).add(k);

            // step 2 - check if at least 3 occurrences exist
            List<Integer> list = numMap.get(num);
            if (list.size() >= 3) {
                int len = list.size();

                // i = third last occurrence
                int i = list.get(len - 3);

                // step 3 - update result
                res = Math.min(res, 2 * (k - i));
            }
        }

        // step 4 - return final result, `res`
        return res == Integer.MAX_VALUE ? -1 : res;
    }

    public static void main(String[] args) {
        MinimumDistanceBetweenThreeEqualElementsII obj = new MinimumDistanceBetweenThreeEqualElementsII();
        // int[] nums = {1,2,1,1,3};

        // int[] nums = {1,1,2,3,2,1,2};

        int[] nums = {1};
        System.out.println(obj.minimumDistance(nums));
    }
}
