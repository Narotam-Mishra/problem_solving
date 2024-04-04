
// Problem link - https://leetcode.com/problems/longest-increasing-subsequence/description/

package Recursion_problems;

public class LongestIncreasingSubsequence {
    public static int[] arr;

    private static int LIS_Recursion(int i){
        // Base case: if ith index 'i' is at 0
        if(i == 0) return 1;

        // there will be atleast 1 increasing subsequence in array always
        int res = 1;

        for(int j=0; j<=i-1; j++){
            if(arr[j] < arr[i]){
                res = Math.max(res, 1 + LIS_Recursion(j));
            }
        }
        return res;
    }
    public static int lengthOfLIS(int[] nums) {
        arr = nums;
        int ans = Integer.MIN_VALUE;
        for(int i=0; i<nums.length; i++){
            ans = Math.max(ans, LIS_Recursion(i));
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
