
// Problem link : https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class CountNumberOfPairsWithAbsoluteDifferenceK {
    public static int countKDifference(int[] nums, int k) {
        // step 1 - hash map to store the frequency of each number
        Map<Integer, Integer> map = new HashMap<>();
        int count = 0;

        // step 2 - iterate through each number in the array
        for(int num : nums){
            // 2.1 - check if there exists a number such that num - k = otherNum
            if(map.containsKey(num - k)){
                count += map.get(num - k);
            }

            // 2.2 - check if there exists a number such that num + k = otherNum
            if(map.containsKey(num + k)){
                count += map.get(num + k);
            }

            // step 3 - updated the frequency map with the current number
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        // step 4 - return the total count of valid pairs
        return count;
    }

    public static void main(String[] args) {
        // int[] nums = {1, 2, 2, 1};
        // int k = 1;

        // int[] nums = {1, 3};
        // int k = 3;

        int[] nums = {3,2,1,5,4};
        int k = 2;
        System.out.println(countKDifference(nums, k));
    }
}