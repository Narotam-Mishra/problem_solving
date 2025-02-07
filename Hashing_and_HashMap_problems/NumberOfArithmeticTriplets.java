
// Problem link : https://leetcode.com/problems/number-of-arithmetic-triplets/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;abstract

public class NumberOfArithmeticTriplets {
    public static int arithmeticTriplets(int[] nums, int diff) {
        // step 1 - store nums array in set for quick lookup
        Set<Integer> seen = new HashSet<>();
        int count = 0;
        for(int num : nums){
            seen.add(num);
        }

        // step 2 - iterate through nums and check for arithmetic triplets
        for(int num : nums){
            if(seen.contains(num + diff) && seen.contains(num + (2*diff))){
                // found valid triplet, increment count
                count++;
            }
        }

        // step 3 - return required count
        return count;
    }

    public static void main(String[] args) {
        int[] nums = {0,1,4,6,7,10};
        int diff = 3;

        // int[] nums = {4,5,6,7,8,9};
        // int diff = 2;
        System.out.println(arithmeticTriplets(nums, diff));
    }
}