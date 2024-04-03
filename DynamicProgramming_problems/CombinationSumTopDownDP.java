
// Problem link - https://leetcode.com/problems/combination-sum-iv/

package DynamicProgramming_problems;

import java.util.Arrays;

public class CombinationSumTopDownDP {
    public static int[] arr;
    public static int[] dp;

    private static int findNumberOfPossibleCombinationsTopDownDP(int curTarget){
        // Base case: if target become 0 then we will first way
        if(curTarget == 0) return 1;

        // if dp[curTarget] is already computed then return dp[curTarget]
        if(dp[curTarget] != -1) return dp[curTarget];

        // Recursive case: recurively calculate number of possible combinations that add up to target
        // f(target) = f(target - arr[i])

        int res = 0;
        for(int i=0; i<arr.length; i++){
            if(curTarget - arr[i] >= 0){
                res += findNumberOfPossibleCombinationsTopDownDP(curTarget - arr[i]);
            }
        }
        dp[curTarget] = res;
        return res;
    }
    public static int combinationSum4(int[] nums, int target) {
        arr = nums;
        dp = new int[target+1];
        Arrays.fill(dp, -1);
        return findNumberOfPossibleCombinationsTopDownDP(target);
    }

    public static void main(String[] args) {
        int[] nums = {1,2,3};
        int target = 4;
        System.out.println(combinationSum4(nums, target));
    }
}
