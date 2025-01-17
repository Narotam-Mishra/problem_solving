
// Problem link : https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class LargestPositiveIntegerThatExistsWithItsNegative {
    public static int findMaxK(int[] nums) {
        // step 1 - create a Set to store all numbers for quick lookup
        Set<Integer> numSet = new HashSet<>();
        for(int num : nums){
            numSet.add(num);
        }

        // step 2 - initialize a variable to keep track of the largest k
        int largestK = -1;

        // step 3 - iterate through the array
        for(int num : numSet){
            // check if both num and its negative counterpart -num exist
            if(numSet.contains(-num)){
                // update largestK if num is positive and larger than current largestK
                largestK = Math.max(largestK, Math.abs(num));
            }
        }

        // step 4 - return the largest k, or -1 if no such k was found
        return largestK;
    }

    public static void main(String[] args) {
        // int[] nums = {-1, 2, -3, 3};

        // int[] nums = {-1,10,6,7,-7,1};

        int[] nums = {-10,8,6,7,-2,-3};
        System.out.println(findMaxK(nums));
    }
}
