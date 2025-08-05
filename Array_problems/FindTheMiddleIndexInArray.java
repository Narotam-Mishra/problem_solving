
// Problem link - https://leetcode.com/problems/find-the-middle-index-in-array/?envType=problem-list-v2&envId=array

package Array_problems;

public class FindTheMiddleIndexInArray {
    public static int findMiddleIndex(int[] nums) {
        // find size of `nums` array
        int n = nums.length;

        // step 1 - find totalSum of `nums`
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // using formula, totalSum = leftSum + rightSum + nums[i]
        // so, rightSum = totalSum - leftSum - nums[i];

        // step 2 - iterate through array to find middle index
        // store left sum in `leftSum`
        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            // step 3 - calculate rightSum using above formula
            int rightSum = totalSum - leftSum - nums[i];

            // step 4 - check if leftSum equals rightSum
            if (leftSum == rightSum) {
                // return middle index `i` immediately
                return i;
            }

            // step 5 - calculate leftSum
            leftSum += nums[i];
        }

        // step 6 - no valid middle index found, so return -1
        return -1;
    }

    public static void main(String[] args) {
        // int[] nums = {2,3,-1,8,4};

        // int[] nums = {1,-1,4};

        int[] nums = {2,5};
        System.out.println(findMiddleIndex(nums));
    }
}