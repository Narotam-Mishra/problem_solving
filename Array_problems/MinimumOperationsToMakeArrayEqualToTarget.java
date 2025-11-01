
// Problem link - https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/description/

package Array_problems;

public class MinimumOperationsToMakeArrayEqualToTarget {
    public static long minimumOperations(int[] nums, int[] target) {
        // get size of input array `nums`
        int n = nums.length;

        // store final result in `res`
        long res = 0;

        // step 2 - iterate on nums perform given operations
        int curr = 0, prev = 0;
        for (int i = 0; i < n; i++) {
            curr = target[i] - nums[i];

            // step 3 - check for sign change
            if ((curr > 0 && prev < 0) || (curr < 0 && prev > 0)) {
                res += Math.abs(curr);
            }

            // step 4 - check if absolute value of current is greater than previous value
            else if (Math.abs(curr) > Math.abs(prev)) {
                res += Math.abs(curr - prev);
            }

            // step 5 - update previous, `prev`
            prev = curr;
        }

        // step 6 - return final result `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {3,5,1,2}, target = {4,6,2,4};

        int[] nums = {1,3,2}, target = {2,1,4};
        System.out.println(minimumOperations(nums, target));
    }
}
