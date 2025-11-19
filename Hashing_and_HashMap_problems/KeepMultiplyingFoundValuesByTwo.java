
// Problem link - https://leetcode.com/problems/keep-multiplying-found-values-by-two/submissions/1833797668/?envType=daily-question&envId=2025-11-19

package Hashing_and_HashMap_problems;

import java.util.*;

public class KeepMultiplyingFoundValuesByTwo {
    public static  int findFinalValue(int[] nums, int original) {
        // step 1 - store all elements of `nums` in set for better lookup
        Set<Integer> numSet = new HashSet<>();
        for(int num : nums){
            numSet.add(num);
        }

        // step 2 - keep searching `original` till it exists in set
        while(numSet.contains(original)){
            // step 3 - double it each time when it is found
            original = 2 * original;
        }

        // step 4 - return `original` when it is not found
        return original;
    }

    public static void main(String[] args) {
        int[] nums = {5,3,6,1,12};
        int original = 3;
        System.out.println(findFinalValue(nums, original));
    }
}
