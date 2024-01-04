
// Problem link - https://leetcode.com/problems/running-sum-of-1d-array/description/

package Array_problems;

/**
 * RunningSum
 */
public class RunningSum {
    public int[] runningSum(int[] nums) {
        int ans[] = new int[nums.length];
        int curSum = 0;
        for(int i=0; i<nums.length; i++){
            curSum += nums[i];
            ans[i] = curSum;
        }
        return ans;
    }
}

