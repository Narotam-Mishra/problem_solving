
// Problem link : https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

package BitMasking_Problems;

import java.util.*;

public class DivideArrayIntoEqualPairs {
    public static boolean divideArray(int[] nums) {
        // create a hashmap to store the frequency of each number
        Map<Integer, Integer> hm = new HashMap<>();

        // count the occurrences of each number in the array
        for(int num : nums){
            hm.put(num, hm.getOrDefault(num, 0) + 1);
        }

        // to make pairs, check if each number's frequency is even
        for(int count : hm.values()){
            // if any number appears an odd number of times, we cannot divide into pairs
            if((count & 1) == 1){
                // if any count is odd, return false
                return false;
            }
        }
        // all numbers have even counts
        return true;
    }

    public static void main(String[] args) {
        // int[] nums = {3, 2, 3, 2, 2, 2};

        int[] nums = {1, 2, 3, 4};
        System.out.println(divideArray(nums));
    }
}