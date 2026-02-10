
// Problem link - https://leetcode.com/problems/longest-balanced-subarray-i/?envType=daily-question&envId=2026-02-10

package Array_problems;

import java.util.*;

public class LongestBalancedSubarrayI {
    public static int longestBalanced(int[] nums) {
        // find length of `nums`
        int n = nums.length;

        // keep track of longest balanced subarray
        int maxLen = 0;

        // step 1 - iterate on each num of `nums`
        for(int i=0; i<n; i++){
            Set<Integer> evenNums = new HashSet<>();
            Set<Integer> oddNums = new HashSet<>();

            // step 2 - iterate on each subarray
            for(int j=i; j<n; j++){
                // step 3 - store even and odd numbers
                if(nums[j] % 2 == 0){
                    evenNums.add(nums[j]);
                }else{
                    oddNums.add(nums[j]);
                }

                // step 4 - check if the size size of odd and even numbers are
                // same or not
                if(evenNums.size() == oddNums.size()){
                    maxLen = Math.max(maxLen, j-i+1);
                }
            }
        }

        // step 5 - return longest balanced subarray length
        return maxLen;
    }

    public static void main(String[] args) {
        // int[] nums = {2,5,4,3};

        // int[] nums = {3,2,2,5,4};

        int[] nums = {1,2,3,2};
        System.out.println(longestBalanced(nums));
    }
}
