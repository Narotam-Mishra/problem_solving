package Hashing_and_HashMap_problems;

import java.util.*;

public class NRepeatedElementIn2NArray {
    public static int repeatedNTimes(int[] nums) {
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

    public static void main(String[] args) {
        // int[] nums = {1,2,3,3};

        // int[] nums = {2,1,2,5,3,2};

        int[] nums = {5,1,5,2,5,3,5,4};
        System.out.println(repeatedNTimes(nums));
    }
}