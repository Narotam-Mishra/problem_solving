
// Problem link - https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/?envType=daily-question&envId=2026-05-10

package DynamicProgramming_problems;

import java.util.*;

public class MaximumNumberOfJumpsToReachLastIndex {
    int n;

    private int solveRec(int i, int[] nums, int target, int[] memo){
        // base case: if we reached the target
        if(i == n-1) return memo[i] = 0;

        // if result is precomputed then return
        if(memo[i] != Integer.MIN_VALUE){
            return memo[i];
        }

        // recursive case: iterate on each valid index
        int res = Integer.MIN_VALUE;
        for(int j=i+1; j<n; j++){
            // compute result
            if(Math.abs(nums[i] - nums[j]) <= target){
                int temp = 1 + solveRec(j, nums, target, memo);
                res = Math.max(res, temp);
            }
        }

        return memo[i] = res;
    }

    public int maximumJumps(int[] nums, int target) {
        n = nums.length;

        // keep track of memoized value
        int[] memo = new int[n+1];
        Arrays.fill(memo, Integer.MIN_VALUE);

        // step 1 - solve recursively and return result
        int res = solveRec(0, nums, target, memo);
        return res < 0 ? -1 : res;
    }

    public static void main(String[] args) {
        int[] nums = {1,3,6,4,1,2};
        int target = 2;
        MaximumNumberOfJumpsToReachLastIndex obj = new MaximumNumberOfJumpsToReachLastIndex();
        System.out.println(obj.maximumJumps(nums, target));
    }
}
