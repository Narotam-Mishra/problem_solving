
// Problem link - https://leetcode.com/problems/arithmetic-slices/description/

// Approach - using TopDown DP

package DynamicProgramming_problems;

import java.util.Arrays;

public class ArithmeticSlicesTopDownDP {
    public static int[] arr;
    public static int[] dp;

    private static int findNumOfArithmeticSlicesTopDownDP(int i) {
        // Base case1: if ith index is 0 or 1 then there is no Arithmetic slice return 0
        if (i == 0 || i == 1)
            return dp[i] = 0;

        // Base case2 : if the difference between any two consecutive elements is not
        // the same then return 0
        else if (arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2])
            return dp[i] = 0;

        // if dp[i] is already calculated then return dp[i]
        if (dp[i] != -1)
            return dp[i];

        else {
            // Recursive case:
            return dp[i] = 1 + findNumOfArithmeticSlicesTopDownDP(i - 1);
        }
    }

    private static int findNumOfArithmeticSlicesBottomUpDP() {
        for (int i = 0; i < arr.length; i++) {
            // Base case1: if ith index is 0 or 1 then there is no Arithmetic slice return 0
            if (i == 0 || i == 1) dp[i] = 0;

            // Base case2 : if the difference between any two consecutive elements is not
            // the same then return 0
            else if (arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2]) dp[i] = 0;

            else {
                // store ans in Bottom Up DP
                dp[i] = 1 + dp[i - 1];
            }
        }

        int res = 0;
        for(int id=0; id<arr.length; id++){
            res += dp[id];
        }

        return res;
    }

    public static int numberOfArithmeticSlices(int[] nums) {
        int size = nums.length;
        arr = nums;
        dp = new int[size+1];
        return findNumOfArithmeticSlicesBottomUpDP();
    }

    public static int numberOfArithmeticSlices1(int[] nums) {
        int size = nums.length;
        arr = nums;
        dp = new int[size+1];
        Arrays.fill(dp, -1);
        int res = 0;
        for(int i=0; i<size; i++){
            res += findNumOfArithmeticSlicesTopDownDP(i);
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {1,2,3,4};
        System.out.println(numberOfArithmeticSlices(nums));
    }
}
