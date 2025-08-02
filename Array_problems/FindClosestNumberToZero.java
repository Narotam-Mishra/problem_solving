
// Problem link - https://leetcode.com/problems/find-closest-number-to-zero/?envType=problem-list-v2&envId=array

package Array_problems;

public class FindClosestNumberToZero {
    public static int findClosestNumber(int[] nums) {
        // step 1 - assume first number of `nums` as closest number
        int closestNum = nums[0];

        // step 2 - iterate through the rest of the array starting from index 1
        for (int i = 1; i < nums.length; i++) {
            int currNum = nums[i];

            // step 3 - calculate absolute distances from 0
            int currDistance = Math.abs(currNum);
            int closestDistance = Math.abs(closestNum);

            // step 4 - check if current number is closer to 0
            if (currDistance < closestDistance) {
                closestNum = currNum;
            } else if (currDistance == closestDistance) {
                // step 5 - if distances are equal, we need to pick the larger number
                closestNum = Math.max(currNum, closestNum);
            }
        }

        // step 6 - return closest number `closestNum`
        return closestNum;
    }

    public static void main(String[] args) {
        // int[] nums = {-4,-2,1,4,8};

        int[] nums = {2,-1,1};
        System.out.println(findClosestNumber(nums));
    }
}
