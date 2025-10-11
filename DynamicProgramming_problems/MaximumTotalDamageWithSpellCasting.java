
// Problem link - https://leetcode.com/problems/maximum-total-damage-with-spell-casting/?envType=daily-question&envId=2025-10-11

package DynamicProgramming_problems;

import java.util.*;

public class MaximumTotalDamageWithSpellCasting {
    // dp array for memoization
    static Long[] dp;

    // utility method to find lower bound
    private static int lowerBoundUtils(List<Long> nums, int left, int right, long target) {
        int result = right; // If not found, return right (out of bounds)
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums.get(mid) >= target) {
                result = mid;
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }

    // recursive method to take or skip the power and find maximum damage
    private static long solveRec(List<Long>nums, int i, int n, Map<Long, Long> frqMap){
        // base case: if index out of bounds, no more damage can be added
        if(i >= n){
            return 0;
        }

        // if this state is already computed, return cached result
        if(dp[i] != null){
            return dp[i];
        }

        // option 1 - skip the current power value, as it might fall in forbidden range
        long skipOption = solveRec(nums, i+1, n, frqMap);

        // option 2 - take current power value
        // find next power value that is not forbiddden range
        // using lower_bound to find first element >= nums.get(i) + 3
        int j = lowerBoundUtils(nums, i+1, n, nums.get(i) + 3);
        
        // total damage = (current power * its frequency) + damage from non-conflicting powers
        long takeOption = nums.get(i) * frqMap.get(nums.get(i)) + solveRec(nums, j, n, frqMap);

        // store and return the maximum of both options
        return dp[i] = Math.max(skipOption, takeOption);
    }

    public static long maximumTotalDamage(int[] power) {
        // step 1 - count frequency of each power value
        Map<Long, Long> frqMap = new HashMap<>();
        for(int p : power){
            long pLong = (long) p;
            frqMap.put(pLong, frqMap.getOrDefault(pLong, 0L) + 1);
        }

        // step 2 - extract unique power values
        List<Long> nums = new ArrayList<>(frqMap.keySet());

        // step 3 - sort in ascending order
        Collections.sort(nums);

        // step 4 - initialize dp array
        int n = nums.size();
        dp = new Long[n+1];

        // step 5 - solve recursively
        return solveRec(nums, 0, n, frqMap);
    }

    public static void main(String[] args) {
        // int[] power = {1,1,3,4};

        int[] power = {7,1,6,6};
        System.out.println(maximumTotalDamage(power));
    }
}
