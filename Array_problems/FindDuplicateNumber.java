
// Problem link - https://leetcode.com/problems/find-the-duplicate-number/description/

package Array_problems;

import java.util.Arrays;

public class FindDuplicateNumber {
    public static int findDuplicate(int[] nums) {
        // sort array numbers
        Arrays.sort(nums);

        for(int i=1; i<nums.length; i++){
            if(nums[i] == nums[i-1]){
                return nums[i];
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 4, 2, 2};
        System.out.println(findDuplicate(arr));
    }
}
