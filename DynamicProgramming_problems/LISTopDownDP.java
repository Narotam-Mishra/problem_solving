
// Problem link - https://leetcode.com/problems/longest-increasing-subsequence/description/

package DynamicProgramming_problems;

import java.util.Arrays;

public class LISTopDownDP {
    public static int[] arr;
    public static int[] dp;

    private static int LIS_TopDownDP(int i){
        // Base case: if ith index 'i' is at 0
        if(i == 0) return 1;

        // if dp[i] is already calculated then return dp[i]
        if(dp[i] != -1) return dp[i];

        // there will be atleast 1 increasing subsequence in array always
        int res = 1;

        for(int j=0; j<=i-1; j++){
            if(arr[j] < arr[i]){
                res = Math.max(res, 1 + LIS_TopDownDP(j));
            }
        }
        dp[i] = res;
        return res;
    }

    private static int LIS_BottomUpDP(){
        dp = new int[2700];
        for(int i=0; i<arr.length; i++){
            // Base case: if ith index 'i' is at 0
            if (i == 0) dp[i] = 1;
    
            else{
                // there will be atleast 1 increasing subsequence in array always
                int res = 1;
                for (int j = 0; j <= i - 1; j++){
                    if (arr[j] < arr[i]){
                        res = Math.max(res, 1 + dp[j]);
                    }
                }
                dp[i] = res;
            }
        }

        // calculate final ans
        int ans = Integer.MIN_VALUE;
        for(int i=0; i<arr.length; i++){
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }

    public static int lengthOfLIS(int[] nums) {
        arr = nums;
        return LIS_BottomUpDP();
    }

    public static int lengthOfLIS1(int[] nums) {
        arr = nums;
        dp = new int[nums.length+1];
        Arrays.fill(dp, -1);

        int ans = Integer.MIN_VALUE;
        for(int i=0; i<nums.length; i++){
            ans = Math.max(ans, LIS_TopDownDP(i));
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {10,9,2,5,3,7,101,18};
        // int[] nums = {0,1,0,3,2,3};
        // int[] nums = {7,7,7,7,7,7,7};
        // int[] nums = {1,3,6,7,9,4,10,5,6};

        System.out.println(lengthOfLIS(nums));
    }
}
