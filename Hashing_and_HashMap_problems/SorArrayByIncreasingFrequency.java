
// Problem link : https://leetcode.com/problems/sort-array-by-increasing-frequency/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class SorArrayByIncreasingFrequency {
    public static int[] frequencySort(int[] nums) {
        // step 1 - count the frequency of each element
        Map<Integer, Integer> frqMap = new HashMap<>(); 
        for(int num : nums){
            frqMap.put(num, frqMap.getOrDefault(num, 0)+1);
        }

        // step 2 - convert int array to Integer array
        Integer[] numsInteger = Arrays.stream(nums).boxed().toArray(Integer[]::new);

        // step 3 - sort the array with a custom comparator
        // case 1 - first sort by frequency (ascending)
        // case 2 - if frequencies are the same, sort by value (descending)
        Arrays.sort(numsInteger, (a, b) -> {
            // get frequency of element 'a'
            int frqA = frqMap.get(a);

            // get frequency of element 'b'
            int frqB = frqMap.get(b);
            
            // step 3.1 - if frequencies are equal, sort by value (descending)
            if (frqA == frqB) {
                return b - a;
            }

            // step 3.2 - otherwise, sort by frequency (ascending)
            return frqA - frqB;
        });

        // step 4 - convert Integer array back to int array
        for (int i = 0; i < nums.length; i++) {
            nums[i] = numsInteger[i];
        }

        // step 5 - return the sorted array
        return nums;
    }

    public static void main(String[] args) {
        // int[] nums = {1,1,2,2,2,3};

        int[] nums = {2,3,1,3,2};
        int[] res = frequencySort(nums);
        System.out.println(Arrays.toString(res));
    }
}