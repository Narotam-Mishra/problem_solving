package Array_problems;

import java.util.Arrays;

public class SortArrayByParity {
    private static void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public static int[] sortArrayByParity(int[] nums) {
        // using two-pointer approach
        int s = 0, e = nums.length - 1;

        // step 1 - iterate through array using two-pointers
        while (s < e) {
            // step 2 - if left element is odd and right element is even, swap them
            if (nums[s] % 2 == 1 && nums[e] % 2 == 0) {
                // perform swap
                swap(nums, s, e);
                s++;
                e--;
            }
            // step 3 - if left element is even, move left pointer
            else if (nums[s] % 2 == 0) {
                s++;
            }
            // step 4 - otherwise, if right element is odd, move right pointer
            else {
                e--;
            }
        }

        // step 5 - return array after operation completed
        return nums;
    }

    public static void main(String[] args) {
        // int[] nums = {3,1,2,4};

        int[] nums = {0};
        int[] res = sortArrayByParity(nums);
        System.out.println(Arrays.toString(res));
    }
}