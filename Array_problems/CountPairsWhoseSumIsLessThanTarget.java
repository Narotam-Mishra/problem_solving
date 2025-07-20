
// Problem link - https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class CountPairsWhoseSumIsLessThanTarget {
    public static int countPairs(List<Integer> nums, int target) {
        // store count of pairs in `count`
        int count = 0;

        // step 1 - iterate on each pair of `nums` array
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // step 2 - check if `nums[i] + nums[j] < target`
                if (nums.get(i) + nums.get(j) < target) {
                    // increment the counter
                    count++;
                }
            }
        }

        // step 3 - return counter `count`
        return count;
    }

    public static void main(String[] args) {
        // List<Integer> nums = List.of(-1, 1, 2, 3, 1);
        // int target = 2;

        List<Integer> nums = List.of(-6,2,5,-2,-7,-1,3);
        int target = -2;
        System.out.println(countPairs(nums, target));
    }
}