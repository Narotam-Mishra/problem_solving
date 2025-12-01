
// Problem link - https://leetcode.com/problems/make-sum-divisible-by-p/?envType=daily-question&envId=2025-11-30

package Hashing_and_HashMap_problems;

import java.util.*;

public class MakeSumDivisibleByP {
    public static int minSubarray(int[] nums, int p) {
        // step 1 - find sum of array elements
        long sum = 0;
        for (int num : nums) {
            sum = (sum + num) % p;
        }

        int target = (int)(sum % p);

        // if total sum is already divisible
        if (target == 0) return 0;

        // step 2 - map to store previous prefix sums
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);

        long curr = 0;
        int n = nums.length;
        int res = n;

        // step 3 - find matching remainVal
        for (int j = 0; j < n; j++) {
            curr = (curr + nums[j]) % p;
            int remainVal = (int)((curr - target + p) % p);

            if (map.containsKey(remainVal)) {
                res = Math.min(res, j - map.get(remainVal));
            }

            map.put((int)curr, j);
        }

        return res == n ? -1 : res;
    }

    public static void main(String[] args) {
        // int[] nums = {3,1,4,2};
        // int p = 6;

        // int[] nums = {6,3,5,2};
        // int p = 9;

        int[] nums = {1,2,3};
        int p = 3;
        System.out.println(minSubarray(nums, p));
    }
}
