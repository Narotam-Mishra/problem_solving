
// Problem link - https://leetcode.com/problems/n-repeated-element-in-size-2n-array/?envType=daily-question&envId=2026-01-02

package Hashing_and_HashMap_problems;

import java.util.*;

public class NRepeatedElementIn2NArray {
    public static int repeatedNTimes1(int[] nums) {
        // step 1: create a HashMap to store the frequency of each number
        Map<Integer, Integer> map = new HashMap<>();

        // step 2: iterate through the array and track frequencies
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
            // if a number appears more than once, return it
            if (map.get(num) > 1) {
                return num;
            }
        }
        // this case should never occur
        return -1; 
    }

    public static int repeatedNTimes(int[] nums) {
        // find size of nums
        int n = nums.length;

        // step 1 - start from index 2 because we want to compare
        // nums[i] with nums[i-1] and nums[i-2]
        for (int i = 2; i < n; i++) {
            // case 1 - same element appears consecutively
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }

            // case 2 - same element appears with one gap
            if (nums[i] == nums[i - 2]) {
                return nums[i];
            }
        }

        // step 2 : Edge case - If not found in the loop, the repeated element
        // must be at the end
        return nums[n-1];
    }

    public static void main(String[] args) {
        int[] nums = {1,2,3,3};

        // int[] nums = {2,1,2,5,3,2};

        // int[] nums = {5,1,5,2,5,3,5,4};
        System.out.println(repeatedNTimes(nums));
    }
}