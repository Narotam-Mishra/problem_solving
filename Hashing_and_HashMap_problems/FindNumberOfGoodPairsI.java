
// Problem link : https://leetcode.com/problems/find-the-number-of-good-pairs-i/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class FindNumberOfGoodPairsI {
    public static int numberOfPairs1(int[] nums1, int[] nums2, int k) {
        // step 1 - create a hash map to store frequencies of nums2[j] * k
        Map<Integer, Integer> divisorMap = new HashMap<>();
        for (int num : nums2) {
            int divisor = num * k;
            divisorMap.put(divisor, divisorMap.getOrDefault(divisor, 0) + 1);
        }

        // step 2 - iterate through nums1 and count good pairs
        int goodPairsCount = 0;
        for (int num : nums1) {
            for (Map.Entry<Integer, Integer> entry : divisorMap.entrySet()) {
                int divisor = entry.getKey();
                int count = entry.getValue();
                if (num % divisor == 0) {
                    goodPairsCount += count;
                }
            }
        }

        // step 3 - return all good pairs count
        return goodPairsCount;
    }

    public static int numberOfPairs(int[] nums1, int[] nums2, int k) {
        // step 1 - intialize variable to count good pairs
        int goodPairsCount = 0;

        // step 2 - loop through both arrays
        for (int i = 0; i < nums1.length; i++) {
            for (int j = 0; j < nums2.length; j++) {
                // step 3 - check if the number is divisible by the product of the number in the
                // second array and k
                if (nums1[i] % (nums2[j] * k) == 0) {
                    goodPairsCount++;
                }
            }
        }

        // step 4 - return the count of good pairs
        return goodPairsCount;
    }

    public static void main(String[] args) {
        // int[] nums1 = {1,3,4};
        // int[] nums2 = {1,3,4};
        // int k = 1;

        int[] nums1 = { 1, 2, 4, 12 };
        int[] nums2 = { 2, 4 };
        int k = 3;
        System.out.println(numberOfPairs(nums1, nums2, k));
    }
}