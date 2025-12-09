
// Problem link - https://leetcode.com/problems/count-special-triplets/?envType=daily-question&envId=2025-12-09

package NumberTheory_Problems;

import java.util.*;

public class CountSpecialTriplets {
    private static final int mod = 1_000_000_007;

    public static int specialTriplets(int[] nums) {
        // leftMap and rightMap to store frequency of values 
        // to the left and right of current `j`
        Map<Integer, Integer> leftMap = new HashMap<>();
        Map<Integer, Integer> rightMap = new HashMap<>();

        // step 1 - initialize rightMap with counts of the whole array
        for(int num : nums){
            rightMap.put(num, rightMap.getOrDefault(num, 0) + 1);
        }

        // step 2 - iterate each element as middle index j
        long res = 0L;
        for(int num : nums){
            // step 3 - move current num out of rightMap
            rightMap.put(num, rightMap.getOrDefault(num, 0) - 1);

            // step 4 - find target value that must appear on both sides: 2 * nums[j]
            int target = num * 2;

            // step 5 - count occurrences of target on left and right
            int left = leftMap.getOrDefault(target, 0);
            int right = rightMap.getOrDefault(target, 0);

            // step 6 - triplets contributed by this j = left * right
            res = (res + (long) left * right) % mod;

            // step 7 - update leftMap
            leftMap.put(num, leftMap.getOrDefault(num, 0) + 1);
        }

        // step 8 - return final result, `res`
        return (int)res;
    }

    public static void main(String[] args) {
        // int[] nums = {6,3,6};

        int[] nums = {8,4,2,8,4};
        System.out.println(specialTriplets(nums));
    }
}
