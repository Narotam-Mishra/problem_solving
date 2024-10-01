
// Problem link :- https://leetcode.com/problems/set-mismatch/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

import java.util.*;

public class SetMismatch {
    public static int[] findErrorNums(int[] nums) {
        // sort the array to make it easier to spot the duplicate
        Arrays.sort(nums);

        // initialize with default values
        int missingNum = -1, duplicateNum = -1;
        int n = nums.length;

        // iterate through the sorted array to find the duplicate number
        for(int i=1; i<n; i++){
            if(nums[i-1] == nums[i]){
                // find duplicate
                duplicateNum = nums[i];
            }
        }

        // calculate the expected sum of numbers from 1 to n
        int expSum = (n * (n+1)) / 2;

        // calculate the actual sum of the array with the duplicate
        int actSum = 0;
        for(int num : nums){
            actSum += num;
        }

        // Missing number = expected sum - (actual sum - duplicate number)
        missingNum = expSum - (actSum - duplicateNum);
        return new int[]{duplicateNum, missingNum};
    }

    public static void main(String[] args) {
        // int[] nums = {1, 2, 2, 4};

        int[] nums = {2, 2};
        int[] res = findErrorNums(nums);
        System.out.println(Arrays.toString(res));
    }
}
