
// Problem link : https://leetcode.com/problems/check-if-array-is-good/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class CheckIfArrayIsGood {
    public static boolean isGood1(int[] nums) {
        // step 1 - find length of array and calculate `n` for 
        int len = nums.length;
        int n = len - 1;

        // step 2 - create frequency map to count occurrences of each number
        Map<Integer, Integer> map = new HashMap<>();
        for(int num : nums){
            // if a number is out of the expected range, return false
            if(num < 1 || num > n){
                return false;
            }
            // count occurrences
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        // step 3 - validate frequency conditions
        for(int i=1; i<n; i++){
            if(!map.containsKey(i) || map.get(i) != 1){
                return false;
            }
        }

        // step 4 - `n` should appear exactly twice
        return map.get(n) == 2;
    }

    public static boolean isGood(int[] nums) {
        // step 1 - find length of array and calculate `n` for 
        int n = nums.length - 1;

        // step 2 - find maximum in array 
        int max = -1;
        for(int num : nums){
            max = Math.max(num, max);
        }

        // check for edge case:
        if(max != n) return false;

        // step 3 - calculate frequency of each number of `nums`
        int[] frqMap = new int[max+1];
        for(int num : nums){
            frqMap[num]++;
        }

        // step 4 - validate frequency conditions
        for(int i=1; i<n; i++){
            if(frqMap[i] != 1){
                return false;
            }
        }

        // step 5 - `n` should appear exactly twice
        return frqMap[n] == 2;
    }

    public static void main(String[] args) {
        // int[] nums = {2, 1, 3};

        // int[] nums = {1, 3, 3, 2};

        // int[] nums = {1, 1};

        // int[] nums = {14, 2, 2};

        int[] nums = {3, 4, 4, 1, 2, 1};
        System.out.println(isGood(nums));
    }
}