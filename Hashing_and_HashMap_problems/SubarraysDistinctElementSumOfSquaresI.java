
// Problem link - https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class SubarraysDistinctElementSumOfSquaresI {
    public static int sumCounts1(List<Integer> nums) {
        // store total sum of distinct subarray count
        int totalSum = 0;

        // step 1 - iterate over all possible starting points of subarrays
        for(int i = 0; i < nums.size(); i++) {
            // stor unique elements in current subarray
            Set<Integer> numSet = new HashSet<>();

            // step 2 - iterate over all possible ending points of subarrays starting at i
            for(int j = i; j < nums.size(); j++) {
                // add current subarray element to set
                numSet.add(nums.get(j));
                
                // step 3 - calculate the distinct count and its square
                int distinctCount = numSet.size();
                totalSum += (distinctCount * distinctCount);
            }
        }

        // step 4 - return the total sum
        return totalSum;
    }

    public static int sumCounts(List<Integer> nums) {
        // store total sum of distinct subarray count
        int totalSum = 0;

        // step 1 - iterate over all possible starting points of subarrays
        for (int i = 0; i < nums.size(); i++) {
            // stor unique elements in frequency array map
            int[] freqMap = new int[101];

            // track distinct element count
            int distinctCount = 0;

            // step 2 - iterate over all possible ending points of subarrays starting at i
            for (int j = i; j < nums.size(); j++) {
                // if element is not present in subarray
                if (freqMap[nums.get(j)] == 0) {
                    distinctCount++;
                }

                // increment frequency of current element
                freqMap[nums.get(j)]++;

                // step 3 - calculate the distinct count and its square
                totalSum += (distinctCount * distinctCount);
            }
        }

        // step 4 - return the total sum
        return totalSum;
    }

    public static void main(String[] args) {
        List<Integer> nums = new ArrayList<>(Arrays.asList(1, 2, 1));

        // List<Integer> nums = new ArrayList<>(Arrays.asList(1, 1));
        System.out.println(sumCounts(nums));
    }
}