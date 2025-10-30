
// Problem link - https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/?envType=daily-question&envId=2025-10-30

package Array_problems;

public class MinimumNumberOfIncrementsOnSubarrayToFormTargetArray {
    public static int minNumberOperations(int[] target) {
        // get size of input array `nums`
        int n = target.length;

        // store final result in `res`
        int res = 0;

        // step 1 - iterate on `target` perform given operations
        int curr = 0, prev = 0;
        for (int i = 0; i < n; i++) {
            curr = target[i];

            // step 2 - check if absolute value of current is greater than previous value
            if (Math.abs(curr) > Math.abs(prev)) {
                res += Math.abs(curr - prev);
            }

            // step 3 - update previous, `prev`
            prev = curr;
        }

        // step 4 - return final result `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] target = {1,2,3,2,1};

        // int[] target = {3,1,1,2};

        int[] target = {3,1,5,4,2};
        System.out.println(minNumberOperations(target));
    }
}