
// Problem link - https://leetcode.com/problems/make-array-elements-equal-to-zero/?envType=daily-question&envId=2025-10-28

package Array_problems;

import java.util.*;

public class MakeArrayElementsEqualToZero {
    // helper method simulate starting at index `start` with initial direction `dir`
    private static boolean simulate(int[] nums, int start, int dir){
        int n = nums.length;

        // make a copy of original array
        int[] arr = Arrays.copyOf(nums, n);

        int curr = start;

        // iterate till pointer is within the array
        while(curr >= 0 && curr < n){
            // check if current cell is `0`, 
            if(arr[curr] == 0){
                // then just step in current direction
                curr += dir;
            }else{
                // otherwise decrement it, reverse direction, 
                // then take a step in new direction
                arr[curr]--;
                dir = -dir; 
                curr += dir;
            }
        }

        // at end check if every element became 0
        for(int num : arr){
            if(num != 0) return false;
        }
        return true;
    }

    public static int countValidSelections(int[] nums) {
        // find size of input array `nums`
        int n = nums.length;

        // store number of possible valid selections
        int count = 0;

        // step 1 - iterate on each number of nums
        for(int i=0; i<n; i++){
            // step 2 - skip non-zero values
            if(nums[i] != 0) continue;

            // step 3 - simulate process in both directions
            if(simulate(nums, i, +1)) count++;
            if(simulate(nums, i, -1)) count++;
        }

        // step 4 - return number of possible valid selections
        return count;
    }

    public static void main(String[] args) {
        int[] nums = {1,0,2,0,3};

        // int[] nums = {2,3,4,0,4,1,0};
        System.out.println(countValidSelections(nums));
    }
}
