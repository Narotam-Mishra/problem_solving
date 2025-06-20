
// Problem link - https://leetcode.com/problems/permutations/description/?envType=problem-list-v2&envId=array

package Backtracking_problems;

import java.util.*;

public class Permutations {
    // utility method to swap
    private static void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private static void backtrack(int[] nums, int startIndex, List<List<Integer>> res){
        // base case : if all elements have been placed
        if(startIndex == nums.length){
            // step 1 - convert array to list and add to result
            List<Integer> permutations = new ArrayList<>();
            for(int num : nums){
                permutations.add(num);
            }
            res.add(permutations);
            return;
        }

        // step 2 - try each remaining element at the current position
        for(int i=startIndex; i<nums.length; i++){
            // step 3 - swap current element to the position we're filling
            swap(nums, startIndex, i);

            // step 4 - recurively permute remaining elements
            backtrack(nums, startIndex+1, res);

            // step 5 - swap back to restore original state
            swap(nums, startIndex, i);
        }
    }

    public static List<List<Integer>> permute(int[] nums) {
        // store result in `res` array
        List<List<Integer>> res = new ArrayList<>();

        // step 6 - intiate recursive call
        backtrack(nums, 0, res);

        // step 7 - return result `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,3};

        // int[] nums = {0,1};

        int[] nums = {1};
        List<List<Integer>> res = permute(nums);
        System.out.println(res);
    }
}