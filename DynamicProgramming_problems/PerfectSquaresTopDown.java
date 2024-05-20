
// Problem link - https://leetcode.com/problems/perfect-squares/description/

package DynamicProgramming_problems;

import java.util.Arrays;

public class PerfectSquaresTopDown {
    private static int[] sqArr;
    private static int[] dp;

    private static int PerfectSquaresTopDownDP(int num){
        // Base case: if num is 0 return 0
        if(num == 0) return 0;

        // if dp[num] is already calculated then return its value
        if(dp[num] != -1) return dp[num];

        int ans = Integer.MAX_VALUE;
        int n = sqArr.length;

        for(int i=0; i<n; i++){
            if(num >= sqArr[i]){
                ans = Math.min(ans, PerfectSquaresTopDownDP(num - sqArr[i]));
            }
        }

        return dp[num] = 1 + ans;
    }

    public static int numSquares(int n) {
        sqArr = new int[100];
        int j = 0;

        for(int i=1; i*i<=10000; i++){
            sqArr[j] = i*i;
            j++;
        }

        dp = new int[n+1];
        Arrays.fill(dp, -1);
        return PerfectSquaresTopDownDP(n);
    }

    public static void main(String[] args) {
        int n = 13;
        System.out.println(numSquares(n));
    }
}
