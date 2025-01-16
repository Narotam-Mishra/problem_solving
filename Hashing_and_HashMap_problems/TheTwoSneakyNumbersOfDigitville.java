
// Problem link : https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class TheTwoSneakyNumbersOfDigitville {
    public static int[] getSneakyNumbers(int[] nums) {
        // step 1 - initialize result array to store sneaky numbers
        int[] res = new int[2];
        Set<Integer> seen = new HashSet<>();
        int index = 0;

        // step 2 - iterate through the list of numbers
        for(int num : nums){
            // step 3 - check for duplicate
            if(seen.contains(num)){
                // step 4 - store sneaky numbers
                res[index++] = num;
                if(index == 2){
                    break;
                }
            }else{
                seen.add(num);
            }
        }

        // step 5 - return result
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {0,3,2,1,3,2};

        // int[] nums = {0,1,1,0};

        int[] nums = {7,1,5,4,3,4,6,0,9,5,8,2};
        int[] res = getSneakyNumbers(nums);
        System.out.println(Arrays.toString(res));
    }
}
