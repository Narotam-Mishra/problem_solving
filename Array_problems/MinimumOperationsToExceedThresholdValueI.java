
// Problem link - https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/description/?envType=problem-list-v2&envId=array

package Array_problems;

public class MinimumOperationsToExceedThresholdValueI {
    public static int minOperations(int[] nums, int k) {
        // store minimum number of operations needed
        int minOps = 0;

        // step 1 - iterate on input array `nums`
        for (int num : nums) {
            // step 2 - increment minimum operation `minOps`
            // if current `num` is less than `k`
            if (num < k) {
                minOps++;
            }
        }

        // step 3 - return minimum number of operations needed
        return minOps;
    }

    public static void main(String[] args) {
        // int[] nums = {2,11,10,1,3};
        // int k = 10;

        // int[] nums = {1,1,2,4,9};
        // int k = 1;

        int[] nums = {1,1,2,4,9};
        int k = 9;
        System.out.println(minOperations(nums, k));
    }
}