
// Problem link - https://leetcode.com/problems/longest-common-subsequence/

// Approach - using Top Down DP

package DynamicProgramming_problems;

import java.util.Arrays;

public class LongestCommonSubsequenceTopDownDP {
    public static int[][] dp;
    private static int findLCSTopDownDP(String s1,String s2, int i, int j){
        // Base case: if any of the string has been exhausted then return 0
        if(i == -1 || j == -1) return 0;

         // if dp[i][j] is already calculated then return dp[i][j]
        if(dp[i][j] != -1) return dp[i][j];

        // Recursive case1: if the current character from each string is equal
        // then add current character length and recursively call the function on remaining characters
        if(s1.charAt(i) == s2.charAt(j)){
            return dp[i][j] = 1 + findLCSTopDownDP(s1, s2, i-1, j-1);
        }else{
            // Recursive case2: either exclude current character from 1st string or 2nd string
            int l1 = findLCSTopDownDP(s1, s2, i-1, j);
            int l2 = findLCSTopDownDP(s1, s2, i, j-1);
            // and return maximum length 
            return dp[i][j] = Math.max(l1, l2);
        }
    }
    public static int longestCommonSubsequence1(String text1, String text2) {
        dp = new int[1005][1005];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return findLCSTopDownDP(text1, text2, text1.length()-1, text2.length()-1);
    }

    public static int[][] dpArr = new int[1005][1005];

    private static int findLCSBottomUpDP(String s1, String s2){
        for(int i=1; i<=s1.length(); i++){
            for(int j=1; j<=s2.length(); j++){
                if(i == 0 || j == 0) dpArr[i][j] = 0;
                else{
                    if(s1.charAt(i-1) == s2.charAt(j-1)){
                        dpArr[i][j] = 1 + dpArr[i-1][j-1];
                    }else{
                        dpArr[i][j] = Math.max(dpArr[i-1][j], dpArr[i][j-1]);
                    }
                }
            }
        }
        return dpArr[s1.length()][s2.length()];
    }

    public static int longestCommonSubsequence(String text1, String text2) {
        return findLCSBottomUpDP(text1, text2);
    }

    public static void main(String[] args) {
        String s1 = "abcde";
        String s2 = "ace" ;

        // String s1 = "abc";
        // String s2 = "abc" ;

        // String s1 = "abc";
        // String s2 = "def" ;
        System.out.println(longestCommonSubsequence(s1, s2));
    }
}