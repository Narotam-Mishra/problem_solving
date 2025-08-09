
// Problem link - https://leetcode.com/problems/find-target-indices-after-sorting-array/description/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class FindTargetIndicesAfterSortingArray {
    public static List<Integer> targetIndices(int[] nums, int target) {
        // store result in `res` array
        List<Integer> res = new ArrayList<Integer>();

        // step 1 - sort that array
        Arrays.sort(nums);

        // step 2 - iterate on each element of array
        for(int i=0; i<nums.length; i++){
            // step 3 - check if current element of array is equal to target
            if(nums[i] == target){
                // store indices in `res`
                res.add(i);
            }
        }

        // step 4 - return `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,5,2,3};
        // int target = 2;

        // int[] nums = {1,2,5,2,3};
        // int target = 3;

        int[] nums = {1,2,5,2,3};
        int target = 5;
        List<Integer> res = targetIndices(nums, target);
        System.out.println(res);
    }
}