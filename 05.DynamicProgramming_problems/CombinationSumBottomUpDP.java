
// Problem link - https://leetcode.com/problems/combination-sum-iv/

package DynamicProgramming_problems;

public class CombinationSumBottomUpDP {
    public static int[] arr;
    public static int[] dp;

    private static int findNumberOfPossibleCombinationsBottomUpDP(int target){
        dp = new int[target + 1];
        for(int curTarget = 0; curTarget <= target; curTarget++){
            // Base case: if target become 0 then we will first way
            if (curTarget == 0) dp[curTarget] = 1;

            // Recursive case: recurively calculate number of possible combinations that add up to target
           // f(target) = f(target - arr[i])
           else{
            int res = 0;
            for(int i=0; i<arr.length; i++){
                if(curTarget - arr[i] >= 0){
                    res += dp[curTarget - arr[i]];
                }
            }
            dp[curTarget] = res;
           }
        }
        return dp[target];
    }
    public static int combinationSum4(int[] nums, int target) {
        arr = nums;
        return findNumberOfPossibleCombinationsBottomUpDP(target);
    }

    public static void main(String[] args) {
        int[] nums = {1,2,3};
        int target = 4;
        System.out.println(combinationSum4(nums, target));
    }
}
