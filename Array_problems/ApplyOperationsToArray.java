
// Problem link - https://leetcode.com/problems/apply-operations-to-an-array/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.Arrays;

public class ApplyOperationsToArray {
    public static int[] applyOperations(int[] nums) {
        // find size of `nums` size
        int n = nums.length;

        // step 1 - iterate on input array and perform operations
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // step 2 - move zeros to end
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                int temp = nums[i];
                nums[i] = nums[k];
                nums[k] = temp;
                k++;
            }
        }

        // step 3 - return resultant array `nums`
        return nums;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,2,1,1,0};

        int[] nums = {0,1};
        int[] res = applyOperations(nums);
        System.out.println(Arrays.toString(res));
    }
}
