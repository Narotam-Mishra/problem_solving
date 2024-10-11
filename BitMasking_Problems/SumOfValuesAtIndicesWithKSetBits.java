
// Problem link : https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

package BitMasking_Problems;

import java.util.*;

public class SumOfValuesAtIndicesWithKSetBits {
    private static int countSetBits(int num){
        // initialize a counter to store the number of set bits.
        int setBits = 0;
        
        // loop until 'num' becomes 0.
        while(num > 0){
            // add the least significant bit (LSB) of 'num' to 'setBits'.
            // the bitwise AND operation (num & 1) checks if the LSB is 1.
            setBits += num & 1;
            
            // right shift 'num' by 1 to move to the next bit.
            num = num >> 1;
        }
        // return the total number of set bits.
        return setBits;
    }

    public static int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        // initialize the sum 's' to 0.
        int s = 0;

        // iterate through each index 'i' in the array 'nums'.
        for(int i=0; i<nums.size(); i++){
            // using the helper function to count the number of set bits in index 'i'.
            int setBits = countSetBits(i);
            
            // if the number of set bits in 'i' is exactly 'k', add 'nums[i]' to the sum.
            if(setBits == k){
                s += nums.get(i);
            }
        }
        // return the total sum after checking all indices.
        return s;
    }
    public static void main(String[] args) {
        // List<Integer> nums = Arrays.asList(5, 10, 1, 5, 2);
        // int k = 1;

        List<Integer> nums = Arrays.asList(4, 3, 2, 1);
        int k = 2;
        System.out.println(sumIndicesWithKSetBits(nums, k));
    }    
}